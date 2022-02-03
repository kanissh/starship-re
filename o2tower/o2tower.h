#include<SOIL2.h>
#include<glut.h>

#pragma once
#ifndef o2tower
#define o2tower

class O2tower {
private:
	GLfloat o2tankRadius = 2;
	GLfloat o2tankHeight = 2.5;
	GLfloat towerPillarHeight = 10;
	GLfloat towerPillarDistance = 3;
	GLfloat towerPillarLeanAngle = 9;
	GLfloat mainPipeRadius = 0.5;
	GLfloat supportPillarRadius = 0.20;
	GLfloat centerpipeRadius = 0.5;

public:
	void drawTank(GLuint tex, GLUquadricObj* qobj) {

		/*glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);
		gluQuadricTexture(qobj, GL_TRUE);
		gluQuadricNormals(qobj, GLU_SMOOTH);*/
		double eqnTop[] = { 0.0, 0.0, 1.0, 0.0 };
		double eqnBottom[] = { 0.0, 0.0, -1.0, 0.0 };

		glPushMatrix();
		glRotatef(90, -1, 0, 0);

		//Cylinder tank
		glPushMatrix();
		gluCylinder(qobj, o2tankRadius, o2tankRadius, o2tankHeight, 100, 100);
		glPopMatrix();

		////top dome 
		glPushMatrix();
		glTranslatef(0, 0, o2tankHeight - 0.02);
		glClipPlane(GL_CLIP_PLANE0, eqnTop);
		glEnable(GL_CLIP_PLANE0);

		glTranslatef(0, 0, -2.20);
		glColor3f(1, 0, 1);
		glutSolidSphere(3, 100, 100);

		glDisable(GL_CLIP_PLANE0);
		glPopMatrix();

		//bottom dome
		glPushMatrix();
		
		glTranslatef(0, 0, 0.02);
		glClipPlane(GL_CLIP_PLANE0, eqnBottom);
		glEnable(GL_CLIP_PLANE0);

		glTranslatef(0, 0, 2.20);
		glColor3f(1, 0, 1);
		glutSolidSphere(3, 100, 100);

		glDisable(GL_CLIP_PLANE0);
		glPopMatrix();

		glPopMatrix();

		//glDisable(GL_TEXTURE_2D);
	}

public:
	void drawCenterpipe(GLuint tex,GLUquadricObj* qobj, GLfloat height) {
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);
		gluQuadricTexture(qobj, GL_TRUE);
		gluQuadricNormals(qobj, GLU_SMOOTH);
		//center pipe
		glRotatef(90, -1, 0, 0);
		gluCylinder(qobj, centerpipeRadius, centerpipeRadius, height, 100, 100);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

private:
	void drawPillarPair(GLUquadricObj* qobj) {
		glPushMatrix();
		glTranslatef(towerPillarDistance, 0, 0);
		glRotatef(towerPillarLeanAngle, 0, -1, 0);
		gluCylinder(qobj, supportPillarRadius, supportPillarRadius, towerPillarHeight, 100, 100);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-towerPillarDistance, 0, 0);
		glRotatef(towerPillarLeanAngle, 0, 1, 0);
		gluCylinder(qobj, supportPillarRadius, supportPillarRadius, towerPillarHeight, 100, 100);
		glPopMatrix();
	}

public:
	void drawPillars(GLuint tex, GLUquadricObj* qobj) {

		glPushMatrix();
		glRotatef(90, -1, 0, 0);

		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);
		gluQuadricTexture(qobj, GL_TRUE);
		gluQuadricNormals(qobj, GLU_SMOOTH);
		
		drawPillarPair(qobj);
		glRotatef(60, 0, 0, 1);
		drawPillarPair(qobj);
		glRotatef(60, 0, 0, 1);
		drawPillarPair(qobj);

		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

	
		
		glPushMatrix();
		/*glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);*/
		glColor3f(1, 1, 0.25);
		glTranslatef(0, 0, 2);
		glutSolidTorus(0.125, 2.69, 100, 100);

		glTranslatef(0, 0, 2);
		glutSolidTorus(0.125, 2.366, 100, 100);

		glTranslatef(0, 0, 2);
		glutSolidTorus(0.125, 2.05, 100, 100);

		glTranslatef(0, 0, 2);
		glutSolidTorus(0.125, 1.73, 100, 100);
		//glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPopMatrix();
	}

public:
	void renderO2tower(GLUquadricObj* qobj, GLuint tankTex, GLuint cpipeTex, GLuint pillarTex) {
		glPushMatrix();
		drawCenterpipe(cpipeTex, qobj, towerPillarHeight);
		drawPillars(pillarTex, qobj);

		glTranslatef(0,10,0);
		drawTank(tankTex, qobj);
		glPopMatrix();
	}

};

#endif // !o2tower

