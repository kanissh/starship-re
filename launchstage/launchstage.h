#include<SOIL2.h>
#include<glut.h>

#pragma once
#ifndef launchstage
#define launchstage

class Launchstage {

public:
	void renderLaunchStage() {
		
		glPushMatrix();
		/*glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, concreteTex);*/

		//front slant
		glPushMatrix();
		glBegin(GL_QUADS);
		glColor3f(1, 1, 0);
		glTexCoord2f(0.0, 0.0); glVertex3f(-5, 0, 10);
		glTexCoord2f(1.0, 0.0); glVertex3f(-5, 0, -6);
		glTexCoord2f(1.0, 1.0); glVertex3f(-15, -4, -6);
		glTexCoord2f(0.0, 1.0); glVertex3f(-15, -4, 10);
		glEnd();
		glPopMatrix();

		//side1
		glPushMatrix();
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glTexCoord2f(0.0, 0.0); glVertex3f(4, 0, 10);
		glTexCoord2f(1.0, 0.0); glVertex3f(-5, 0, 10);
		glTexCoord2f(1.0, 1.0); glVertex3f(-5, -4, 25);
		glTexCoord2f(0.0, 1.0); glVertex3f(4, -4, 25);
		glEnd();
		glPopMatrix();

		//side2
		glPushMatrix();
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glTexCoord2f(0.0, 0.0); glVertex3f(-5, 0, -6);
		glTexCoord2f(1.0, 0.0); glVertex3f(4, 0, -6);
		glTexCoord2f(1.0, 1.0); glVertex3f(4, -4, -25);
		glTexCoord2f(0.0, 1.0); glVertex3f(-5, -4, -25);
		glEnd();
		glPopMatrix();


		glPushMatrix();
		//slant side1
		glBegin(GL_QUAD_STRIP);
		glColor3f(1, 0.5, 0.5);
		glTexCoord2f(0.0, 0.0); glVertex3f(-5, 0, 10);
		glTexCoord2f(1.0, 0.0); glVertex3f(-15, -4, 10);
		glTexCoord2f(1.0, 1.0); glVertex3f(-5, -4, 25);
		glTexCoord2f(0.0, 1.0); glVertex3f(-15, -4, 25);
		glEnd();
		glPopMatrix();
		
		
		glPushMatrix();
		//slant side2
		glBegin(GL_QUAD_STRIP);
		glColor3f(1, 0.5, 0.5);
		glTexCoord2f(0.0, 0.0); glVertex3f(-15, -4, -6); 
		glTexCoord2f(1.0, 0.0); glVertex3f(-5, 0, -6); 
		glTexCoord2f(1.0, 1.0); glVertex3f(-15, -4, -25);
		glTexCoord2f(0.0, 1.0); glVertex3f(-5, -4, -25); 
		glEnd();
		glPopMatrix();
		
		glPushMatrix();
		//back slant side1
		glBegin(GL_QUAD_STRIP);
		glColor3f(1, 0.1, 0.5);
		glTexCoord2f(0.0, 0.0); glVertex3f(4, 0, 10);
		glTexCoord2f(1.0, 0.0); glVertex3f(4, -4, 25);
		glTexCoord2f(1.0, 1.0); glVertex3f(10, -4, 10);
		glTexCoord2f(0.0, 1.0); glVertex3f(10, -4, 25);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		//back slant side2
		glBegin(GL_QUAD_STRIP);
		glColor3f(0, 0.0, 0.5);
		glTexCoord2f(0.0, 0.0); glVertex3f(4, 0, -6);
		glTexCoord2f(1.0, 0.0); glVertex3f(10, -4, -6); 
		glTexCoord2f(1.0, 1.0); glVertex3f(4, -4, -25); 
		glTexCoord2f(0.0, 1.0); glVertex3f(10, -4, -25);
		glEnd();
		glPopMatrix();
		
		//curve inside
		glPushMatrix();
		glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(10, -4, -6);
		glVertex3f(4, 0, -6);
		glVertex3f(4, -4, -6);
		glVertex3f(-5, 0, -6);
		glVertex3f(-5, -4, -6);
		glVertex3f(-5, 0, 10);
		glVertex3f(-5, -4, 10);
		glVertex3f(4, 0, 10);
		glVertex3f(4, -4, 10);
		glVertex3f(10, -4, 10);
		glEnd();
		glPopMatrix();
		//glDisable(GL_TEXTURE_2D);

		drawPlatform();
		glPopMatrix();

	}

private:
	void drawPlatform() {
		glPushMatrix();
		GLfloat elevation = 0.5f;
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);

		//side 1
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0, 0.0); glVertex3f(-5, 0, 10);
		glTexCoord2f(1.0, 0.0); glVertex3f(-5, -elevation, 10);
		glTexCoord2f(1.0, 1.0); glVertex3f(4, -elevation, 10);
		glTexCoord2f(0.0, 1.0); glVertex3f(4, 0, 10);


		//back
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0, 0.0); glVertex3f(4, 0, 10);
		glTexCoord2f(1.0, 0.0); glVertex3f(4, -elevation, 10);
		glTexCoord2f(1.0, 1.0); glVertex3f(4, -elevation, -6);
		glTexCoord2f(0.0, 1.0); glVertex3f(4, 0, -6);

		//side 2
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0, 0.0); glVertex3f(4, 0, -6);
		glTexCoord2f(1.0, 0.0); glVertex3f(4, -elevation, -6);
		glTexCoord2f(1.0, 1.0); glVertex3f(-5, -elevation, -6);
		glTexCoord2f(0.0, 1.0); glVertex3f(-5, 0, -6);

		//front
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0, 0.0); glVertex3f(-5, 0, 10);
		glTexCoord2f(1.0, 0.0); glVertex3f(-5, 0, -6);
		glTexCoord2f(1.0, 1.0); glVertex3f(-5, -elevation, -6);
		glTexCoord2f(0.0, 1.0); glVertex3f(-5, -elevation, 10);

		//top
		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0, 0.0); glVertex3f(-5, 0, 10);
		glTexCoord2f(1.0, 0.0); glVertex3f(4, 0, 10);
		glTexCoord2f(1.0, 1.0); glVertex3f(4, 0, -6);
		glTexCoord2f(0.0, 1.0); glVertex3f(-5, 0, -6);

		//bottom
		glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(0.0, 0.0); glVertex3f(-5, -elevation, 10);
		glTexCoord2f(1.0, 0.0); glVertex3f(4, -elevation, 10);
		glTexCoord2f(1.0, 1.0); glVertex3f(4, -elevation, -6);
		glTexCoord2f(0.0, 1.0); glVertex3f(-5, -elevation, -6);

		glEnd();
		glPopMatrix();

	}
};

#endif // !launchstage


