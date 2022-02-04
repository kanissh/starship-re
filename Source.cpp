#include<Windows.h>
#include<glut.h>
#include<math.h>
#include<iostream>
#include<SOIL2.h>

#include "barebones.h"
#include "launchtower/launchtower.h"
#include "starship/starship.h"
#include "superheavy/superheavy.h"
#include "o2tower/o2tower.h"
#include "comtower/comtower.h"


GLfloat windowW = 10;
GLfloat windowH = 10;
GLfloat znear = 1;
GLfloat zfar = 100;

// variables to move outermost Object Frame (to move all the rendered environment)
GLfloat moveX = 0.0f;
GLfloat moveY = 0.0f;
GLfloat moveZ = 0.0f;

// variables to rotate outermost Object Frame (to move all the rendered environment)
GLfloat rotX = 0.0f;
GLfloat rotY = 0.0f;
GLfloat rotZ = 0.0f;

//variables to move the camera
GLfloat camY = 0.0f;
GLfloat camX = 0.0f;
GLfloat camZ = 0.0f;

GLUquadricObj* qobj;


GLuint blackTex;
GLuint offGreyTex;

void init();
void display();
void reshape(GLsizei, GLsizei);
void keyboardSpecial(int, int, int);
void keyboard(unsigned char, int, int);
void Timer(int);
void setupLighting();

GLfloat animateRotation = 0.0f; //global add to glrotatef

void setMaterials() {//call inside the drawing funtion at top , can define different for dif
    float mat_ambient[] = { 0.329f, 0.223f, 0.0274f, 1.0f };
    float mat_diffuse[] = { 0.780f, 0.568f, 0.113f, 1.0f };
    float mat_specular[] = { 0.992f, 0.941f, 0.807f, 1.0f };

    float shine[] = { 27.897f };

    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
}

void setupLighting() {
    // Lighting setup
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

    // Set lighting intensity and color
    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0f };
    GLfloat light_diffuse[] = { 1.0, 1.0f, 1.0f, 1.0f };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };

    // Set the light position
    GLfloat position01[] = { 0, 0, -2 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, position01);

    GLfloat position02[] = { 0, 1, -1 };

    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, position02);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}

void Timer(int x) {
    animateRotation += animateRotation >= 360.0 ? -animateRotation : 5;
    glutPostRedisplay();

    glutTimerFunc(60, Timer, 1);
}


void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK); 
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    setupLighting();
    glShadeModel(GL_SMOOTH); // or GL_FLAT 
    glEnable(GL_COLOR_MATERIAL);

 

    blackTex = SOIL_load_OGL_texture
    (
        "F:/FOS/300L/CS308 Computer Graphics Programming Practical/starship/textures/black-tex.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    offGreyTex = SOIL_load_OGL_texture
    (
        "F:/FOS/300L/CS308 Computer Graphics Programming Practical/starship/textures/off-grey-tex.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    qobj = gluNewQuadric();

//GL_FRONT, GL_FRONT_AND_BACK, GL_FRONT_LEFT, GL_FRONT_RIGHT, GL_BACK_LEFT,  GL_BACK_RIGHT

}

void reshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    GLfloat aspectRatio = h == 0 ? (GLfloat)w / 1 : (GLfloat)w / (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //if (w <= h)
        //glOrtho(-windowW, windowW, -windowH / aspectRatio, windowH / aspectRatio, 1.0, -1.0);
    //else
        //glOrtho(-windowW * aspectRatio, windowW * aspectRatio, -windowH, windowH, 1.0, -1.0);

    //perspective projection
    gluPerspective(120.0, aspectRatio, znear, zfar);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    // camera orientation (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
    gluLookAt(0.0 + camX, 2.0 + camY, 5.0 + camZ, 0, 0, 0, 0, 1.0, 0);

    // move the object frame using keyboard keys
    glTranslatef(moveX, moveY, moveZ);
    glRotatef(rotX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotZ, 0.0f, 0.0f, 1.0f);

    drawAxes();
    drawGrid();

    glPushMatrix();
    //drawing code
    //drawLaunchTower(offGreyTex, blackTex, 23.3);
    
   /* Superheavy sh;
    sh.renderSuperheavy(offGreyTex, qobj);

    Starship ss;
    glTranslatef(0, 15, 0);
    ss.renderStarship(offGreyTex, qobj);*/

    /*O2tower o2t;
    o2t.drawTank(offGreyTex, qobj);
    o2t.drawCenterpipe(offGreyTex, qobj, 10);
    o2t.renderO2tower(qobj, offGreyTex, offGreyTex, offGreyTex);*/

    //Comtower ct;
    //ct.drawCircularPillars(offGreyTex ,qobj);
    //ct.drawStage(offGreyTex ,qobj);
    //ct.renderComtower(offGreyTex, qobj);

    //Launchtower lt;
    //lt.renderLaunchtower(offGreyTex, blackTex);
    //lt.drawLauchsupport(offGreyTex, qobj);
    
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void keyboardSpecial(int key, int x, int y) {
    if (key == GLUT_KEY_UP)
        moveZ += 1;

    if (key == GLUT_KEY_DOWN)
        moveZ -= 1;

    if (key == GLUT_KEY_LEFT)
        rotY -= 5.0;

    if (key == GLUT_KEY_RIGHT)
        rotY += 1.0;

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'w')
        camY += 0.5;
    if (key == 's')
        camY -= 0.5;
    if (key == 'b')
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    if (key == 'B')
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    if (key == 'c')
        glEnable(GL_CULL_FACE);
    if (key == 'C')
        glDisable(GL_CULL_FACE);

    glutPostRedisplay();

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("starship");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardSpecial);
    init();
    glutTimerFunc(60.0, Timer, 1);
    glutMainLoop();
    return 0;
}