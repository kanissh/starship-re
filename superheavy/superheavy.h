#include<glut.h>
#include<SOIL2.h>

#pragma once
#ifndef superheavy
#define superheavy

class Superheavy {

private:
	GLfloat superheavyHeight = 15;
	GLfloat rocketRadius = 1;
	GLfloat finthickness = 0.15;
	GLfloat bottomFinHeight = 3.75;

public:
	GLfloat getSuperheavyHeight() {
		return superheavyHeight;
	}

public:
	void drawBody(GLuint tex, GLUquadricObj* qobj, GLfloat radius, GLfloat height) {
		glPushMatrix();
		glColor3f(1, 0.2, 0);
		/*glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);*/
		gluQuadricTexture(qobj, GL_TRUE);
		gluQuadricNormals(qobj, GLU_SMOOTH);
		glRotatef(90, -1, 0, 0);
		gluCylinder(qobj, radius, radius, height, 100, 100);
		//glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

public:
	void drawBottomFins(GLuint tex, GLfloat height) {
		/*glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);*/
		
		glPushMatrix();
		glBegin(GL_POLYGON);
		glVertex3f(2, 0, 0);
		glVertex3f(2, 1, 0);
		glVertex3f(1, 3.75, 0);
		glVertex3f(-1, 3.75, 0);
		glVertex3f(-2, 1, 0);
		glVertex3f(-2, 0, 0);
		glVertex3f(2, 0, 0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0, -finthickness);
		glColor3f(1, 0, 1);
		glBegin(GL_POLYGON);
		glVertex3f(2, 0, 0);
		glVertex3f(-2, 0, 0);
		glVertex3f(-2, 1, 0);
		glVertex3f(-1, 3.75, 0);
		glVertex3f(1, 3.75, 0);
		glVertex3f(2, 1, 0);
		glVertex3f(2, 0, 0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1, 0, 0.4);
		glBegin(GL_QUAD_STRIP);
		glVertex3f(2, 0, 0);
		glVertex3f(2, 0, -finthickness);

		glVertex3f(2, 1, 0);
		glVertex3f(2, 1, -finthickness);

		glVertex3f(1, 3.75, 0);
		glVertex3f(1, 3.75, -finthickness);

		glVertex3f(-1, 3.75, 0);
		glVertex3f(-1, 3.75, -finthickness);

		glVertex3f(-2, 1, 0);
		glVertex3f(-2, 1, -finthickness);

		glVertex3f(-2, 0, 0);
		glVertex3f(-2, 0, -finthickness);

		glVertex3f(2, 0, 0);
		glVertex3f(2, 0, -finthickness);
		glEnd();
		glPopMatrix();

		//glDisable(GL_TEXTURE_2D);
	}

public:
	void renderSuperheavy(GLuint tex, GLUquadricObj* qobj) {
		glPushMatrix();
		drawBody(tex, qobj, rocketRadius, superheavyHeight);

		glTranslatef(0, 0, finthickness / 2);

		drawBottomFins(tex, bottomFinHeight);
		glRotatef(60, 0, 1, 0);
		drawBottomFins(tex, bottomFinHeight);
		glRotatef(60, 0, 1, 0);
		drawBottomFins(tex, bottomFinHeight);

		glPopMatrix();
	}
};

#endif // !superheavy

