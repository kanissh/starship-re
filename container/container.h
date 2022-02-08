#include<SOIL2.h>
#include<glut.h>


#pragma once
#ifndef container
#define container

class Container {
private:
	GLuint fronttex;
	GLuint backtex;
	GLuint righttex;
	GLuint lefttex;
	GLuint toptex;
	GLuint bottomtex;

public:
	void loadTextures(const char front[],
	const char back[],
	const char right[],
	const char left[],
	const char top[],
	const char bottom[]) 
	{
		fronttex = SOIL_load_OGL_texture
		(
			front,
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
		
		backtex = SOIL_load_OGL_texture
		(
			back,
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
		
		righttex = SOIL_load_OGL_texture
		(
			right,
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
		
		lefttex = SOIL_load_OGL_texture
		(
			left,
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
		
		toptex = SOIL_load_OGL_texture
		(
			top,
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
		
		bottomtex = SOIL_load_OGL_texture
		(
			bottom,
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
		glBindTexture(GL_TEXTURE_2D, righttex);
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
		glBindTexture(GL_TEXTURE_2D, lefttex);
		glBegin(GL_QUADS);
		glTexCoord2f(1, 0); glVertex3f(length, 0, -width);
		glTexCoord2f(0, 0); glVertex3f(0, 0, -width);
		glTexCoord2f(0, 1); glVertex3f(0, width, -width);
		glTexCoord2f(1, 1); glVertex3f(length, width, -width);
		glEnd();
		glDisable(GL_TEXTURE_2D);


		
		//front
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, fronttex);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f(0, 0, -width);
		glTexCoord2f(1, 0); glVertex3f(0, 0, 0);
		glTexCoord2f(1, 1); glVertex3f(0, width, 0);
		glTexCoord2f(0, 1); glVertex3f(0, width, -width);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		

		
		
		//back
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, backtex);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f(length, 0, 0);
		glTexCoord2f(1, 0); glVertex3f(length, 0, -width);
		glTexCoord2f(1, 1); glVertex3f(length, width, -width);
		glTexCoord2f(0, 1); glVertex3f(length, width, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);

		
		
		//top
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, toptex);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1); glVertex3f(0, width, -width);
		glTexCoord2f(0, 0); glVertex3f(0, width, 0);
		glTexCoord2f(1, 0); glVertex3f(length, width, 0);
		glTexCoord2f(1, 1); glVertex3f(length, width, -width);	
		glEnd();
		glDisable(GL_TEXTURE_2D);

		//bottom
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, bottomtex);
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

#endif // !container
