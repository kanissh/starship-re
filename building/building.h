#include<glut.h>
#include<SOIL2.h>

#pragma once
#ifndef building
#define building

class Building {

private:
	GLuint fronttex;
	GLuint othertex;
	

public:
	void loadTextures(const char front[],
		const char other[]
		)
	{
		fronttex = SOIL_load_OGL_texture
		(
			front,
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);

		othertex = SOIL_load_OGL_texture
		(
			other,
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
	}

public:
	void renderContainer(
		GLfloat length,
		GLfloat width) {

		glPushMatrix();


		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, fronttex);
		//right
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
		glTexCoord2f(1, 0); glVertex3f(length, 0, 0);
		glTexCoord2f(1, 1); glVertex3f(length, width, 0);
		glTexCoord2f(0, 1); glVertex3f(0, width, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);

		//left
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, othertex);
		glBegin(GL_QUADS);
		glTexCoord2f(1, 0); glVertex3f(length, 0, -width);
		glTexCoord2f(0, 0); glVertex3f(0, 0, -width);
		glTexCoord2f(0, 1); glVertex3f(0, width, -width);
		glTexCoord2f(1, 1); glVertex3f(length, width, -width);
		glEnd();
		glDisable(GL_TEXTURE_2D);



		//front
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, othertex);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f(0, 0, -width);
		glTexCoord2f(1, 0); glVertex3f(0, 0, 0);
		glTexCoord2f(1, 1); glVertex3f(0, width, 0);
		glTexCoord2f(0, 1); glVertex3f(0, width, -width);
		glEnd();
		glDisable(GL_TEXTURE_2D);




		//back
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, othertex);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f(length, 0, 0);
		glTexCoord2f(1, 0); glVertex3f(length, 0, -width);
		glTexCoord2f(1, 1); glVertex3f(length, width, -width);
		glTexCoord2f(0, 1); glVertex3f(length, width, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);



		//top
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, othertex);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1); glVertex3f(0, width, -width);
		glTexCoord2f(0, 0); glVertex3f(0, width, 0);
		glTexCoord2f(1, 0); glVertex3f(length, width, 0);
		glTexCoord2f(1, 1); glVertex3f(length, width, -width);
		glEnd();
		glDisable(GL_TEXTURE_2D);

		//bottom
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, othertex);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1); glVertex3f(0, 0, 0);
		glTexCoord2f(0, 0); glVertex3f(0, 0, -width);
		glTexCoord2f(1, 0); glVertex3f(length, 0, -width);
		glTexCoord2f(1, 1); glVertex3f(length, 0, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);

		glPopMatrix();
	}
};

#endif // !building.h
