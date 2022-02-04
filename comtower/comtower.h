#include<glut.h>
#include<math.h>

#pragma once
#ifndef comtower
#define comtower

class Comtower {
private:
	GLfloat comTowerHeight = 12;
	GLfloat comTowerPillarRadius = 0.15;
	GLfloat comTowerDistanceFromOrigin = 0.5;

	GLfloat topAntennaeStageHeight = 3;
	GLfloat topAntennaeStagePillarRadius = 0.1;
	GLfloat stageRadius = 2;
	GLfloat antennaeRadius = 0.5;
	GLfloat antennaeHeight = 7;

public:
	void drawPillars(GLuint tex, GLUquadricObj* qobj) {
		
		glPushMatrix();
		glColor3f(0.1, 1, 0);
		/*glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, redPillarTex);
			gluQuadricTexture(qobj, GL_TRUE);
			gluQuadricNormals(qobj, GLU_SMOOTH);
			glRotatef(90, -1, 0, 0);*/
		//pillars
		glPushMatrix();
		glTranslatef(comTowerDistanceFromOrigin, comTowerDistanceFromOrigin, 0);
		gluCylinder(qobj, comTowerPillarRadius, comTowerPillarRadius, comTowerHeight, 100, 100);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-comTowerDistanceFromOrigin, -comTowerDistanceFromOrigin, 0);
		gluCylinder(qobj, comTowerPillarRadius, comTowerPillarRadius, comTowerHeight, 100, 100);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-comTowerDistanceFromOrigin, comTowerDistanceFromOrigin, 0);
		gluCylinder(qobj, comTowerPillarRadius, comTowerPillarRadius, comTowerHeight, 100, 100);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(comTowerDistanceFromOrigin, -comTowerDistanceFromOrigin, 0);
		gluCylinder(qobj, comTowerPillarRadius, comTowerPillarRadius, comTowerHeight, 100, 100);
		glPopMatrix();

		//glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		
	}

public: 
	void drawStage(GLuint tex, GLUquadricObj* qobj) {
		
		glPushMatrix();

		/*glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, redPillarTex);
		gluQuadricTexture(qobj, GL_TRUE);
		gluQuadricNormals(qobj, GLU_SMOOTH);*/

		for (float j = 0; j < 360; j += 45) {
			glRotatef(45, 0, 0, 1);
			glPushMatrix();
			glTranslatef(stageRadius - topAntennaeStagePillarRadius, 0, 0);
			gluCylinder(qobj, topAntennaeStagePillarRadius, topAntennaeStagePillarRadius, topAntennaeStageHeight, 100, 100);
			glPopMatrix();
		}
		
		//hori rings
		glPushMatrix();
		glColor3f(1, 1, 0);
		glutSolidTorus(topAntennaeStagePillarRadius, stageRadius - topAntennaeStagePillarRadius , 100, 100);
		glTranslatef(0, 0, topAntennaeStageHeight/2);
		glutSolidTorus(topAntennaeStagePillarRadius, stageRadius - topAntennaeStagePillarRadius, 100, 100);
		glTranslatef(0, 0, topAntennaeStageHeight / 2);
		glutSolidTorus(topAntennaeStagePillarRadius, stageRadius - topAntennaeStagePillarRadius, 100, 100);
		glPopMatrix();

		//base and top
		glPushMatrix();
		glColor3f(0.3, 0.4, 1);
		gluQuadricNormals(qobj, GLU_SMOOTH);
		gluQuadricOrientation(qobj, GLU_INSIDE);
		glTranslatef(0,0,-topAntennaeStagePillarRadius/2);
		gluDisk(qobj, 0, stageRadius, 100, 100);

		gluQuadricOrientation(qobj, GLU_OUTSIDE);
		glTranslatef(0, 0, topAntennaeStagePillarRadius);
		gluDisk(qobj, 0, stageRadius, 100, 100);

		glTranslatef(0, 0, -topAntennaeStagePillarRadius/2);

		glTranslatef(0, 0, topAntennaeStageHeight - topAntennaeStagePillarRadius/2);
		gluQuadricOrientation(qobj, GLU_INSIDE);
		gluDisk(qobj, 0, stageRadius, 100, 100);

		glTranslatef(0, 0, topAntennaeStagePillarRadius / 2);
		gluQuadricOrientation(qobj, GLU_OUTSIDE);
		gluDisk(qobj, 0, stageRadius, 100, 100);
		glPopMatrix();

		//antennae
		glPushMatrix();
		gluCylinder(qobj, antennaeRadius, antennaeRadius, antennaeHeight, 100, 100);

		glTranslatef(0, 0, antennaeHeight);
		gluDisk(qobj, 0, antennaeRadius, 100, 100);

		glPopMatrix();

		//glDisable(GL_TEXTURE_2D);
		glPopMatrix();	
	}

public:
	void drawCircularPillars(GLuint tex, GLUquadricObj* qobj) {
		
		
		glPushMatrix();
		/*glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, redPillarTex);
			gluQuadricTexture(qobj, GL_TRUE);
			gluQuadricNormals(qobj, GLU_SMOOTH);
			glRotatef(90, -1, 0, 0);*/

		for (int i = 3; i < comTowerHeight; i += 3) {
			glTranslatef(0, 0, 3);
			glutSolidTorus(0.15, comTowerDistanceFromOrigin + comTowerPillarRadius, 100, 100);
		}
		//glDisable(GL_TEXTURE_2D);

		glPopMatrix();
	}

public:
	void renderComtower(GLuint tex ,GLUquadricObj* qobj) {
		glPushMatrix();
		glRotatef(90, -1, 0, 0);
		
		
		drawPillars(tex, qobj);
		drawCircularPillars(tex, qobj);
		
		glTranslatef(0,0,comTowerHeight);
		drawStage(tex, qobj);

		glPopMatrix();
	}

	

};

#endif // !comtower
