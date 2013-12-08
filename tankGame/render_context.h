#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "shader_program.h"

typedef glm::vec3 vector3;

typedef GLuint textureID;
typedef GLuint meshID;

class render_context
{
public:
	void initilize();
	void begin();
	void end();
	void resize(int pWidth, int pHeight);

	void set_camera(vector3 pPosition, vector3 pTarget, vector3 pUp);

	void draw_cube();
private:
	static GLuint mWidth, mHeight;
	static GLfloat mAspectRatio, mFieldOfView;

	static glm::mat4 mProjectionMatrix;
	static glm::mat4 mViewMatrix;
	//static glm::mat4 mModelMatrix;

	static shader_program mShader;
};

