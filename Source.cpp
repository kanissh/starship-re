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
#include "launchstage/launchstage.h"
#include "container/container.h"
#include "building/building.h"

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

GLuint steelTex;
GLuint steelTexFins;
GLuint concreteTex;
GLuint concreteTexBase;
GLuint redPillarTex;
GLuint whiteMetalTex;
GLuint blackTex;
GLuint offGreyTex;
GLuint offWhiteTex;
GLuint znTex;
GLuint redRustTex;
GLuint baremetalTex;
GLuint skyTex;

bool showWireframe = false;
bool showAxes = false;
bool showGrid = false;

bool setCamSupports = true;
bool setCamRocket = true;

GLint refreshMills = 60;
GLboolean launchFlag = false;
GLfloat launchSupportDisplacement = 0;
GLfloat rocketPathDisplacement = 0;
GLfloat baseRadius = 60;

Container whitecon;
Container bluecon;
Building office;


void init();
void display();
void reshape(GLsizei, GLsizei);
void keyboardSpecial(int, int, int);
void keyboard(unsigned char, int, int);
void Timer(int);
void setupLighting();

GLfloat animateRotation = 0.0f; //global add to glrotatef

void initTexture() {
    baremetalTex = SOIL_load_OGL_texture
    (
        "textures/bare-metal.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    steelTex = SOIL_load_OGL_texture
    (
        "textures/steel-tex.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    steelTexFins = SOIL_load_OGL_texture
    (
        "textures/steel-tex-fins.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    concreteTex = SOIL_load_OGL_texture
    (
        "textures/concrete-tex.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    concreteTexBase = SOIL_load_OGL_texture
    (
        "textures/concrete-tex-2.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    redPillarTex = SOIL_load_OGL_texture
    (
        "textures/red-pillar-tex.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    whiteMetalTex = SOIL_load_OGL_texture
    (
        "textures/white-metal-tex.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    blackTex = SOIL_load_OGL_texture
    (
        "textures/black-tex.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    offGreyTex = SOIL_load_OGL_texture
    (
        "textures/off-grey-tex.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    offWhiteTex = SOIL_load_OGL_texture
    (
        "textures/off-white-tex.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    znTex = SOIL_load_OGL_texture
    (
        "textures/zinc-tex.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    redRustTex = SOIL_load_OGL_texture
    (
        "textures/red-rust-tex.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );


    skyTex = SOIL_load_OGL_texture
    (
       "textures/sky.jpg",
       SOIL_LOAD_AUTO,
       SOIL_CREATE_NEW_ID,
       SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    //
    whitecon.loadTextures("textures/container-tex/front-white-2.jpg",
        "textures/container-tex/back.jpg",
        "textures/container-tex/side-white.jpg",
        "textures/container-tex/side-white.jpg",
        "textures/container-tex/top-bottom-white.jpg",
        "textures/container-tex/top-bottom-white.jpg");

    bluecon.loadTextures("textures/container-tex/door-blue.jpg",
        "textures/container-tex/back-blue.jpg",
        "textures/container-tex/side-blue.jpg",
        "textures/container-tex/side-blue.jpg",
        "textures/container-tex/top-bottom-blue.jpg",
        "textures/container-tex/top-bottom-blue.jpg");

    office.loadTextures("textures/building/front.jpg",
        "textures/building/concrete-wall.jpg");

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

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

    glutTimerFunc(refreshMills, Timer, 1);
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

    initTexture();

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

void renderBase(GLuint tex) {

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);
    gluQuadricTexture(qobj, GL_TRUE);
    gluQuadricNormals(qobj, GLU_SMOOTH);
    glRotatef(90, -1, 0, 0);
    gluDisk(qobj, 0, baseRadius, 50, 50);
   

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void renderSky(GLuint tex){
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);
    gluQuadricTexture(qobj, GL_TRUE);
    gluQuadricNormals(qobj, GLU_SMOOTH);
    

    glTranslatef(0, -8, 0);
    glRotatef(90, -1, 0, 0);
    gluCylinder(qobj, baseRadius, baseRadius, 200, 100, 100);

    glDisable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);
    glPopMatrix();
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

    if (showAxes) {
        drawAxes();
    }

    if (showGrid) {
        drawGrid();
    }

    glPushMatrix();
    renderSky(skyTex);
    glPopMatrix();

    //stage
    glPushMatrix();
    Launchstage ls;
    ls.renderLaunchStage(concreteTex);
    glPopMatrix();
    
    //superheavy and starship
    glPushMatrix();
    if (launchFlag && launchSupportDisplacement >= 2) {

        if (setCamRocket) {
            camX = 0; camY = 32; camZ = 0; rotX = 0; rotY = -130; rotZ = 0; moveX = 3; moveY = 0; moveZ = 0;
            setCamRocket = false;
        }

        glTranslatef(0, rocketPathDisplacement, 0);
        if (camY < 100) {
            rocketPathDisplacement += 1;
            camY += 1;
        }
    }

    Superheavy sh;
    Starship ss;
    sh.renderSuperheavy(steelTex,steelTexFins, qobj);

    glTranslatef(0, sh.getSuperheavyHeight(), 0);
    ss.renderStarship(steelTex,steelTexFins, qobj);
    glPopMatrix();

    //launchtower
    glPushMatrix();
    Launchtower lt;
    glTranslatef(0, 0, 6);
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, 0, 0.5);
    lt.renderLaunchtower(offGreyTex, blackTex, qobj);
    glPopMatrix();

    //sup
    glPushMatrix();
    if (launchFlag) {

        if (setCamSupports) {
            camX = 0; camY = 21; camZ = 0; rotX = 0; rotY = -90; rotZ =0; moveX = 3; moveY = 0; moveZ = 0;
            setCamSupports = false;
        }
        
        glTranslatef(0, 0, launchSupportDisplacement);
        if (launchSupportDisplacement < 2) {
            launchSupportDisplacement += 0.1;
        }
    }

    glTranslatef(-0.3, sh.getSuperheavyHeight() - 3, 1);
    lt.renderLauchsupport(znTex, qobj);
    
    glTranslatef(0, ss.getstarshipHeight() - 2, 0);
    lt.renderLauchsupport(znTex, qobj);
    glPopMatrix();

    //base
    glPushMatrix();
    glTranslatef(0, -4, 0);
    renderBase(concreteTexBase);
    glPopMatrix();

    //comm. tower
    glPushMatrix();
    Comtower ct;
    glTranslatef(35, -4, -35);
    ct.renderComtower(redPillarTex, whiteMetalTex, qobj);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-35, -4, 35);
    ct.renderComtower(redPillarTex, whiteMetalTex, qobj);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(35, -4, 35);
    ct.renderComtower(redPillarTex, whiteMetalTex, qobj);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-35, -4, -35);
    O2tower o2t;
    o2t.renderO2tower(qobj, baremetalTex, blackTex, redRustTex);
    glPopMatrix();

    //containers
    glPushMatrix();
    //          
    //    |10|  |9|
    //    |6,7||5,8|  
    // |1||2,3||4||11|
    //         |13||12|
    //
    glTranslatef(-30,-4, 45);
    bluecon.renderContainer(6, 2.5);//1
    glTranslatef(6, 0, 5);
    whitecon.renderContainer(6, 2.5);//2
    glTranslatef(0, 2.5, 0);
    whitecon.renderContainer(6, 2.5);//3
    glTranslatef(6, -2.5, 0);
    bluecon.renderContainer(6, 2.5);//4
    glTranslatef(0, 0, -2.5);
    whitecon.renderContainer(6, 2.5);//5
    glTranslatef(-6, 0, 0);
    whitecon.renderContainer(6, 2.5);//6
    glTranslatef(0, 2.5, 0);
    bluecon.renderContainer(6, 2.5);//7
    glTranslatef(6, 0, 0);
    bluecon.renderContainer(6, 2.5);//8
    glTranslatef(0, -2.5, -2.5);
    whitecon.renderContainer(6, 2.5);//9
    glTranslatef(-6, 0, 0);
    bluecon.renderContainer(6, 2.5);//10
    glTranslatef(12, 0, 5);
    whitecon.renderContainer(6, 2.5);//11
    glTranslatef(0, 0, 2.5);
    whitecon.renderContainer(6, 2.5);//12
    glTranslatef(-6, 0, 0);
    bluecon.renderContainer(6, 2.5);//13
    glPopMatrix();


    //building
    glPushMatrix();
    glTranslatef(20,-4,-35);
    office.renderContainer(12, 5);
    glPopMatrix();




    glPopMatrix();
    glutSwapBuffers();
}

void keyboardSpecial(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {
        moveZ += 2;
    }
    else if (key == GLUT_KEY_DOWN) {
        moveZ -= 2;
    }
    else if (key == GLUT_KEY_LEFT) {
        moveX += 2;
    }
    else if (key == GLUT_KEY_RIGHT) {
        moveX -= 2;
    }

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'w') {
        camY += 0.5;
    }
    else if (key == 's') {
        camY -= 0.5;
    }
    else if (key == 'a') {
        rotY += 5.0;
    }
    else if (key == 'd') {
        rotY -= 5.0;
    }
    else if (key == 'c') {
        if (showWireframe)
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        showWireframe = !showWireframe;
    }
    else if (key == 'x') {
        showAxes = !showAxes;
    }
    else if (key == 'g') {
        showGrid = !showGrid;
    }
    else if (key == 'r') {
        launchFlag = false;
        launchSupportDisplacement = 0;
        rocketPathDisplacement = 0;
        setCamSupports = true;
        camY = 10;
        camZ = 20;
        moveY = 0;
        moveX = 0;
        moveZ = 10;
    }
    else if (key == 'p') {
        std::cout << "camX = " << camX << ";camY =" << camY << ";camZ =" << camZ << ";rotX =" << rotX << ";rotY =" << rotY << ";rotZ =" << rotZ << ";moveX =" << moveX << ";moveY =" << moveY << ";moveZ =" << moveZ << "\n";
    }
    else if (key == 'l') {
        launchFlag = true;
    }
    else if (key == '1') {
        camX = 0; camY = 10; camZ = 0; rotX = 0; rotY = -5; rotZ = 0; moveX = 32; moveY = 0; moveZ = 32;
    }
    else if (key == '2') {
        camX = 0; camY = 3.5; camZ = 0; rotX = 0; rotY = 5; rotZ = 0; moveX = -24; moveY = 0; moveZ = 24;
    }
    else if (key == '3') {
        camX = 0; camY = 11; camZ = 0; rotX = 0; rotY = 5; rotZ = 0; moveX = -38; moveY = 0; moveZ = -34;
    }
    else if (key == '4') {
        camX = 0; camY = 8.5; camZ = 20; rotX = 0; rotY = -140; rotZ = 0; moveX = 14; moveY = 0; moveZ = 60;
    }
    else if (key == '5') {
        camX = 0; camY = 16; camZ = 20; rotX = 0; rotY = -90; rotZ = 0; moveX = 2; moveY = 0; moveZ = 20;
    }
    else if (key == '6') {
        camX = 0; camY = 43; camZ = 20; rotX = 0; rotY = -90; rotZ = 0; moveX = 2; moveY = 0; moveZ = 10;
    }
    else if (key == '6') {
        glEnable(GL_LIGHT0);
    }
    else if (key == '[') {
        glDisable(GL_LIGHT0);
    }
    else if (key == '-') {
        glEnable(GL_LIGHT1);
    }
    else if (key == '=') {
        glDisable(GL_LIGHT1);
    }
    
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
    glutTimerFunc(0, Timer, 0);
    glutMainLoop();
    return 0;
}