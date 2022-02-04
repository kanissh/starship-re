#include<SOIL2.h>
#include<glut.h>

#pragma once
#ifndef launchtower
#define launchtower

class Launchtower {
private:
	GLfloat starshipHeight = 8.3; //11
	GLfloat superheavyHeight = 15;
	GLfloat launchtowerHeight = starshipHeight + superheavyHeight;
	GLint cornerPoleLength = 3.4;
	GLint cornerPoleHeight = 1;
	GLfloat cornerPoleRadius = 0.1;
	GLint crossPoleLength = 1.5;
	GLfloat crossPoleRadius = 0.05;
	GLfloat sideLength = 0.6;

public:
	void renderLaunchtower(GLuint offGreyTex, GLuint blackTex) {
		glPushMatrix();
		drawLaunchtower(offGreyTex, blackTex);
		glPopMatrix();
	}

private:
	void drawCrosshatch(GLUquadricObj* qobj) {
		glPushMatrix();
		glTranslatef(0, 0, 0.3);
		for (int i = 0; i < 5; i++) {
			glPushMatrix();
			glRotatef(64, -1, 0, 0);
			gluCylinder(qobj, crossPoleRadius, crossPoleRadius, 1.11, 50, 50);
			glPopMatrix();
			glTranslatef(0, 0, 0.5);
		}
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0, 0.8);
		for (int i = 0; i < 5; i++) {
			glPushMatrix();
			glRotatef(116, -1, 0, 0);
			gluCylinder(qobj, crossPoleRadius, crossPoleRadius, 1.11, 50, 50);
			glPopMatrix();
			glTranslatef(0, 0, 0.5);
		}
		glPopMatrix();
	}

public:
	void drawLauchsupport(GLuint tex, GLUquadricObj* qobj) {
		glPushMatrix();
		glColor3f(0.1, 0.2, 1);
		/*glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);*/
		
		//corner poles
		glPushMatrix();
		gluCylinder(qobj, cornerPoleRadius, cornerPoleRadius, cornerPoleLength, 100, 100);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(sideLength,0,0);
		gluCylinder(qobj, cornerPoleRadius, cornerPoleRadius, cornerPoleLength, 100, 100);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(sideLength, cornerPoleHeight, 0);
		gluCylinder(qobj, cornerPoleRadius, cornerPoleRadius, cornerPoleLength, 100, 100);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, cornerPoleHeight, 0);
		gluCylinder(qobj, cornerPoleRadius, cornerPoleRadius, cornerPoleLength, 100, 100);
		glPopMatrix();

		//cross hatch
		glPushMatrix();
		drawCrosshatch(qobj);

		glTranslatef(sideLength, 0, 0);
		drawCrosshatch(qobj);
		glPopMatrix();

		//top, bottom bars
		glPushMatrix();
		glRotatef(90, 0, 1, 0);
		for (int i = 0; i < 5;i++) {
			glTranslatef(-0.5, 0, 0);
			gluCylinder(qobj, crossPoleRadius, crossPoleRadius, sideLength, 100, 100);
		}
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, cornerPoleHeight, 0);
		glRotatef(90, 0, 1, 0);
		for (int i = 0; i < 5; i++) {
			glTranslatef(-0.5, 0, 0);
			gluCylinder(qobj, crossPoleRadius, crossPoleRadius, sideLength, 100, 100);
		}

		glPopMatrix();

		glPopMatrix();

		//glDisable(GL_TEXTURE_2D);
	}

public:
	void drawCylinder(GLfloat radius, GLfloat height, GLfloat r, GLfloat g, GLfloat b) {
		GLfloat y = 0.0;
		GLfloat z = 0.0;
		GLfloat angle = 0.0;
		GLfloat angle_stepsize = 0.1;

		glColor3f(r, g, b);

		// TUBE
		glBegin(GL_QUAD_STRIP);
		angle = 2 * 3.14;
		while (angle >= 0.0) {
			y = radius * sin(angle);
			z = radius * cos(angle);
			glVertex3f(height, y, z);
			glVertex3f(0.0, y, z);
			angle = angle - angle_stepsize;
		}
		glVertex3f(height, 0.0, radius);
		glVertex3f(0.0, 0.0, radius);
		glEnd();

		// BACK
		glColor3f(1.0, 1.0, 0.5);
		glBegin(GL_POLYGON);
		angle = 0.0;
		while (angle < 2 * 3.14) {
			y = radius * sin(angle);
			z = radius * cos(angle);
			glVertex3f(0.0, y, z);
			angle = angle + angle_stepsize;
		}
		glVertex3f(0.0, 0.0, radius);
		glEnd();

		// FRONT
		glColor3f(1.0, 1.0, 0.5);
		glBegin(GL_POLYGON);
		angle = 2 * 3.14 - angle_stepsize;
		while (angle >= 0.0) {
			y = radius * sin(angle);
			z = radius * cos(angle);
			glVertex3f(height, y, z);
			angle = angle - angle_stepsize;
		}
		glVertex3f(height, 0.0, radius);
		glEnd();
	}

public:
	void drawLaunchtower(GLuint offGreyTex, GLuint blackTex) {
		//front
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, offGreyTex);
		glPushMatrix();
		glBegin(GL_QUAD_STRIP);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
		glTexCoord2f(1.0, 0.0); glVertex3f(2, 0, 0);
		glTexCoord2f(1.0, 1.0); glVertex3f(0, launchtowerHeight - 4, 0);
		glTexCoord2f(0.0, 1.0); glVertex3f(2, launchtowerHeight - 4, 0);
		glTexCoord2f(0.0, 0.0); glVertex3f(0, launchtowerHeight - 1, 0);
		glTexCoord2f(1.0, 0.0); glVertex3f(4, launchtowerHeight - 1, 0);
		glTexCoord2f(1.0, 1.0); glVertex3f(0, launchtowerHeight, 0);
		glTexCoord2f(0.0, 1.0); glVertex3f(4, launchtowerHeight, 0);
		glEnd();
		glPopMatrix();

		//back
		glPushMatrix();
		glTranslatef(0, 0, -0.5);
		glNormal3f(0, 0, -1);
		glBegin(GL_QUAD_STRIP);
		glTexCoord2f(0.0, 0.0); glVertex3f(2, 0, 0);
		glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, 0);
		glTexCoord2f(1.0, 1.0); glVertex3f(2, launchtowerHeight - 4, 0);
		glTexCoord2f(0.0, 1.0); glVertex3f(0, launchtowerHeight - 4, 0);
		glTexCoord2f(0.0, 0.0); glVertex3f(4, launchtowerHeight - 1, 0);
		glTexCoord2f(1.0, 0.0); glVertex3f(0, launchtowerHeight - 1, 0);
		glTexCoord2f(1.0, 1.0); glVertex3f(4, launchtowerHeight, 0);
		glTexCoord2f(0.0, 1.0); glVertex3f(0, launchtowerHeight, 0);
		glEnd();
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, blackTex);

		//right
		glPushMatrix();
		glColor3f(0.1, 1, 0);
		glBegin(GL_QUAD_STRIP);
		glTexCoord2f(0.0, 0.0); glVertex3f(2, 0, 0);
		glTexCoord2f(1.0, 0.0); glVertex3f(2, 0, -0.5);
		glTexCoord2f(1.0, 1.0); glVertex3f(2, launchtowerHeight - 4, 0);
		glTexCoord2f(0.0, 1.0); glVertex3f(2, launchtowerHeight - 4, -0.5);
		glTexCoord2f(0.0, 0.0); glVertex3f(4, launchtowerHeight - 1, 0);
		glTexCoord2f(1.0, 0.0); glVertex3f(4, launchtowerHeight - 1, -0.5);
		glTexCoord2f(1.0, 1.0); glVertex3f(4, launchtowerHeight, 0);
		glTexCoord2f(0.0, 1.0); glVertex3f(4, launchtowerHeight, -0.5);
		glEnd();
		glPopMatrix();

		//top
		glPushMatrix();
		glTranslatef(0, launchtowerHeight, 0);
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
		glTexCoord2f(1.0, 0.0); glVertex3f(0, launchtowerHeight, 0);
		glTexCoord2f(1.0, 1.0); glVertex3f(0, launchtowerHeight, -0.5);
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


};

#endif // !launchtower


