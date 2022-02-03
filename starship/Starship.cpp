#include<SOIL2.h>
#include<glut.h>

class Starship
{
public:
	void drawBody(GLuint steelTex, GLUquadricObj* qobj, GLfloat radius, GLfloat height) {
		glPushMatrix();

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, steelTex);
		gluQuadricTexture(qobj, GL_TRUE);
		gluQuadricNormals(qobj, GLU_SMOOTH);

		//glColor3f(1, 0.4, 1);
		glRotatef(90, -1, 0, 0);

		gluCylinder(qobj, radius, radius, height, 100, 100);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}
};