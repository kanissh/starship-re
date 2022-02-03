#pragma once
#ifndef starship
#define starship

#include<SOIL2.h>
#include<glut.h>


class Starship
{
private:
	GLfloat finthickness = 0.15;

public:
	void drawBody(GLuint tex, GLUquadricObj* qobj, GLfloat radius, GLfloat height) {
		glPushMatrix();

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);
		gluQuadricTexture(qobj, GL_TRUE);
		gluQuadricNormals(qobj, GLU_SMOOTH);

		//glColor3f(1, 0.4, 1);
		glRotatef(90, -1, 0, 0);

		gluCylinder(qobj, radius, radius, height, 100, 100);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

public:
	void drawTopCone(GLuint tex, GLUquadricObj* qobj, GLfloat topRadius, GLfloat baseRadius, GLfloat height) {

		glPushMatrix();

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);
		gluQuadricTexture(qobj, GL_TRUE);
		gluQuadricNormals(qobj, GLU_SMOOTH);

		//glTranslatef(0, height, 0);
		glRotatef(-90, 1, 0, 0);
		gluCylinder(qobj, baseRadius, topRadius, height, 50, 50);

		glTranslatef(0, 0, height - 0.07);
		gluSphere(qobj, topRadius, 100, 100);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

	}

public:
	void drawTopFins(GLuint tex, GLfloat height) {
		/*glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);*/

		glPushMatrix();
		glBegin(GL_POLYGON);

		//large face
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(2, 0.3, 0);
		glVertex3f(2, 0.6, 0);
		glVertex3f(0, height, 0);
		glVertex3f(-2, 0.6, 0);
		glVertex3f(-2, 0.3, 0);
		glVertex3f(-1, 0, 0);
		glVertex3f(0, 0, 0);
		glEnd();

		glPopMatrix();

		//large face
		glPushMatrix();
		glTranslatef(0, 0, -finthickness);
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(-1, 0, 0);
		glVertex3f(-2, 0.3, 0);
		glVertex3f(-2, 0.6, 0);
		glVertex3f(0, height, 0);
		glVertex3f(2, 0.6, 0);
		glVertex3f(2, 0.3, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glEnd();

		glPopMatrix();

		//bottom rectangle
		glPushMatrix();
		glBegin(GL_QUAD_STRIP);
		glColor3f(0, 0, 1);
		glVertex3f(1, 0, 0);
		glVertex3f(1, 0, -finthickness);

		glVertex3f(2, 0.3, 0);
		glVertex3f(2, 0.3, -finthickness);

		glVertex3f(2, 0.6, 0);
		glVertex3f(2, 0.6, -finthickness);

		glVertex3f(0, height, 0);
		glVertex3f(0, height, -finthickness);

		glVertex3f(-2, 0.6, 0);
		glVertex3f(-2, 0.6, -finthickness);

		glVertex3f(-2, 0.3, 0);
		glVertex3f(-2, 0.3, -finthickness);
		
		glVertex3f(-1, 0, 0);
		glVertex3f(-1, 0, -finthickness);
		
		glVertex3f(1, 0, 0);
		glVertex3f(1, 0, -finthickness);


		glEnd();
		glPopMatrix();

		//glDisable(GL_TEXTURE_2D);

	}

public:
	void drawBottomFins(GLuint tex, GLfloat height) {

		/*glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);*/
		
		//large face
		glPushMatrix();
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(2, 0, 0);
		glVertex3f(2, 1.5, 0);
		glVertex3f(1, height, 0);
		glVertex3f(-1, height, 0);
		glVertex3f(-2, 1.5, 0);
		glVertex3f(-2, 0, 0);
		glVertex3f(0, 0, 0);
		glEnd();

		glPopMatrix();

		//large face
		glPushMatrix();
		glTranslatef(0, 0, -finthickness);
		glBegin(GL_POLYGON);

		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(-2, 0, 0);
		glVertex3f(-2, 1.5, 0);
		glVertex3f(-1, height, 0);
		glVertex3f(1, height, 0);
		glVertex3f(2, 1.5, 0);
		glVertex3f(2, 0, 0);
		glVertex3f(0, 0, 0);
		glEnd();

		glPopMatrix();

		////rectangular sides
		//glPushMatrix();
		//glTranslatef(0, superheavyHeight, 0);

		////bottom
		//glBegin(GL_POLYGON);
		//glColor3f(1, 1, 1);
		//glVertex3f(2, 0, 0.15);
		//glVertex3f(-2, 0, 0.15);
		//glVertex3f(-2, 0, -0.15);
		//glVertex3f(2, 0, -0.15);
		//glVertex3f(2, 0, 0.15);
		//glEnd();

		////side
		//glBegin(GL_POLYGON);
		//glColor3f(1, 1, 1);
		//glVertex3f(2, 0, 0.15);
		//glVertex3f(2, 0, -0.15);
		//glVertex3f(2, 1.5, -0.15);
		//glVertex3f(2, 1.5, 0.15);
		//glVertex3f(2, 0, 0.15);
		//glEnd();

		////side
		//glBegin(GL_POLYGON);
		//glColor3f(1, 1, 1);
		//glVertex3f(-2, 0, 0.15);
		//glVertex3f(-2, 0, -0.15);
		//glVertex3f(-2, 1.5, -0.15);
		//glVertex3f(-2, 1.5, 0.15);
		//glVertex3f(-2, 0, 0.15);
		//glEnd();

		////side slant
		//glBegin(GL_POLYGON);
		//glColor3f(1, 1, 1);
		//glVertex3f(-2, 1.5, -0.15);
		//glVertex3f(-2, 1.5, 0.15);
		//glVertex3f(-1, bottomFinHeight, 0.15);
		//glVertex3f(-1, bottomFinHeight, -0.15);
		//glVertex3f(-2, 1.5, -0.15);
		//glEnd();

		////side slant
		//glBegin(GL_POLYGON);
		//glColor3f(1, 1, 1);
		//glVertex3f(2, 1.5, -0.15);
		//glVertex3f(2, 1.5, 0.15);
		//glVertex3f(1, bottomFinHeight, 0.15);
		//glVertex3f(1, bottomFinHeight, -0.15);
		//glVertex3f(2, 1.5, -0.15);
		//glEnd();

		//glPopMatrix();
		//glDisable(GL_TEXTURE_2D);


	}

};

#endif // !starship