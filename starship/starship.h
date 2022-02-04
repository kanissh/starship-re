#pragma once
#ifndef starship
#define starship

#include<SOIL2.h>
#include<glut.h>


class Starship
{
private:
	GLfloat finthickness = 0.15;
	GLfloat smallfinthickness = 0.05;
	GLfloat topConeHeight = 2.3;
	GLfloat topConeTopRad = 0.2;
	GLfloat topConeBottomRad = 1;
	GLfloat topFinHeight = 3.5;
	GLfloat bottomFinHeight = 4;
	GLfloat rocketRadius = 1;
	GLfloat starshipHeight = 8.3; //11

public:
	GLfloat getstarshipHeight() {
		return starshipHeight;
	}

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
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);

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

		glDisable(GL_TEXTURE_2D);

	}

public:
	void drawBottomFins(GLuint tex, GLfloat height) {

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);
		
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

		glPushMatrix();
		glBegin(GL_QUAD_STRIP);
		glColor3f(0, 1, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, -finthickness);
		glVertex3f(2, 0, 0);
		glVertex3f(2, 0, -finthickness);
		glVertex3f(2, 1.5, 0);
		glVertex3f(2, 1.5, -finthickness);
		glVertex3f(1, height, 0);
		glVertex3f(1, height, -finthickness);
		glVertex3f(-1, height, 0);
		glVertex3f(-1, height, -finthickness);
		glVertex3f(-2, 1.5, 0);
		glVertex3f(-2, 1.5, -finthickness);
		glVertex3f(-2, 0, 0);
		glVertex3f(-2, 0, -finthickness);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, -finthickness);
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);


	}

public:
	void drawSmallFins(GLuint tex) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);
		glPushMatrix();
		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);
		glVertex3f(1.25, 0, 0);
		glVertex3f(1.25, 1.2, 0);
		glVertex3f(1, 1.5, 0);
		glVertex3f(-1, 1.5, 0);
		glVertex3f(-1.25, 1.2, 0);
		glVertex3f(-1.25, 0, 0);
		glVertex3f(1.25, 0, 0);

		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0, -smallfinthickness);
		glBegin(GL_POLYGON);

		glColor3f(0, 1, 1);
		glVertex3f(1.25, 0, 0);
		glVertex3f(-1.25, 0, 0);
		glVertex3f(-1.25, 1.2, 0);
		glVertex3f(-1, 1.5, 0);
		glVertex3f(1, 1.5, 0);
		glVertex3f(1.25, 1.2, 0);
		glVertex3f(1.25, 0, 0);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glBegin(GL_QUAD_STRIP);
		glColor3f(0, 1, 0);
		glVertex3f(1.25, 0, 0);
		glVertex3f(1.25, 0, -smallfinthickness);
		glVertex3f(1.25, 1.2, 0);
		glVertex3f(1.25, 1.2, -smallfinthickness);
		glVertex3f(1, 1.5, 0);
		glVertex3f(1, 1.5, -smallfinthickness);
		glVertex3f(-1, 1.5, 0);
		glVertex3f(-1, 1.5, -smallfinthickness);
		glVertex3f(-1.25, 1.2, 0);
		glVertex3f(-1.25, 1.2, -smallfinthickness);
		glVertex3f(-1.25, 0, 0);
		glVertex3f(-1.25, 0, -smallfinthickness);
		glVertex3f(1.25, 0, 0);
		glVertex3f(1.25, 0, -smallfinthickness);
		glEnd();
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}

public:
	void renderStarship(GLuint bodytex,
		GLuint fintex,
		GLUquadricObj* qobj) {
		
		//cylinder, top cone
		glPushMatrix();
		drawBody(bodytex, qobj, rocketRadius, starshipHeight);
		glTranslatef(0, starshipHeight, 0);
		drawTopCone(bodytex, qobj, topConeTopRad, topConeBottomRad, topConeHeight);
		glPopMatrix();
		
		//top, bottom fins
		glPushMatrix();
		glTranslatef(0, 0, finthickness/2);
		drawBottomFins(fintex, bottomFinHeight);
		glTranslatef(0, starshipHeight + topConeHeight - topFinHeight, 0);
		drawTopFins(fintex, topFinHeight);
		glPopMatrix();

		//small fins
		glPushMatrix();
		glTranslatef(0, 0, finthickness / 2);
		
		glRotatef(60, 0, 1, 0);
		drawSmallFins(fintex);

		glRotatef(60, 0, 1, 0);
		drawSmallFins(fintex);
		glPopMatrix();

	}

};

#endif // !starship