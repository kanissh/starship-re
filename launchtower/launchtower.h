#include<SOIL2.h>
#include<glut.h>

#pragma once
#ifndef launchtower
#define launchtower

void drawLaunchTower(GLuint offGreyTex, GLuint blackTex, GLfloat height) {
	//front
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, offGreyTex);
	glPushMatrix();
	glBegin(GL_QUAD_STRIP);
	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(2, 0, 0);
	glTexCoord2f(1.0, 1.0); glVertex3f(0, height - 4, 0);
	glTexCoord2f(0.0, 1.0); glVertex3f(2, height - 4, 0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0, height - 1, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(4, height - 1, 0);
	glTexCoord2f(1.0, 1.0); glVertex3f(0, height, 0);
	glTexCoord2f(0.0, 1.0); glVertex3f(4, height, 0);
	glEnd();
	glPopMatrix();

	//back
	glPushMatrix();
	glTranslatef(0, 0, -0.5);
	glNormal3f(0,0,-1);
	glBegin(GL_QUAD_STRIP);
	glTexCoord2f(0.0, 0.0); glVertex3f(2, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 1.0); glVertex3f(2, height - 4, 0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0, height - 4, 0);
	glTexCoord2f(0.0, 0.0); glVertex3f(4, height - 1, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0, height - 1, 0);
	glTexCoord2f(1.0, 1.0); glVertex3f(4, height, 0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0, height, 0);
	glEnd();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, blackTex);

	//right
	glPushMatrix();
	glColor3f(0.1,1,0);
	glBegin(GL_QUAD_STRIP);
	glTexCoord2f(0.0, 0.0); glVertex3f(2, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(2, 0, -0.5);
	glTexCoord2f(1.0, 1.0); glVertex3f(2, height - 4, 0); 
	glTexCoord2f(0.0, 1.0); glVertex3f(2, height - 4, -0.5); 
	glTexCoord2f(0.0, 0.0); glVertex3f(4, height - 1, 0); 
	glTexCoord2f(1.0, 0.0); glVertex3f(4, height - 1, -0.5); 
	glTexCoord2f(1.0, 1.0); glVertex3f(4, height, 0); 
	glTexCoord2f(0.0, 1.0); glVertex3f(4, height, -0.5); 
	glEnd();
	glPopMatrix();

	//top
	glPushMatrix();
	glTranslatef(0, height, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(4, 0, 0);
	glTexCoord2f(1.0, 1.0); glVertex3f(4, 0, -0.5);
	glTexCoord2f(0.0, 1.0); glVertex3f(0, 0, -0.5);
	glEnd();
	glPopMatrix();
		
	//left
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0, height, 0);
	glTexCoord2f(1.0, 1.0); glVertex3f(0, height , -0.5);
	glTexCoord2f(0.0, 1.0); glVertex3f(0, 0, -0.5);
	glEnd();
	glPopMatrix();

	//bottom
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, -0.5);
	glTexCoord2f(1.0, 1.0); glVertex3f(2, 0, -0.5);
	glTexCoord2f(0.0, 1.0); glVertex3f(2, 0, 0);
	glEnd();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}


#endif // !launchtower


