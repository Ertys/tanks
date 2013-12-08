#include "render_context.h"

GLuint render_context::mWidth;
GLuint render_context::mHeight;
GLfloat render_context::mAspectRatio;
GLfloat render_context::mFieldOfView;

glm::mat4 render_context::mProjectionMatrix;
glm::mat4 render_context::mViewMatrix;
//glm::mat4 render_context::mModelMatrix;

shader_program render_context::mShader;

void render_context::initilize()
{
	glewInit();

	mFieldOfView = 60.0f;
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_ALPHA_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	mShader.load_shader("vertShader.txt", "fragShader.txt");
	mShader.bind();
}

void render_context::begin()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void render_context::end()
{
}


void render_context::resize(int pWidth, int pHeight)
{

	mWidth	= pWidth;
	mHeight = pHeight;

	mAspectRatio = (GLfloat)mWidth / (GLfloat)mHeight;

	glViewport(0, 0, mWidth, mHeight);

	mProjectionMatrix = glm::perspective(mFieldOfView, mAspectRatio, 10.0f, 1000.0f);
}

void render_context::set_camera(vector3 pPosition, vector3 pTarget, vector3 pUp)
{
	mViewMatrix = glm::lookAt(pPosition, pTarget, pUp);
}

void render_context::draw_cube()
{
	glm::mat4 MVP = mProjectionMatrix * mViewMatrix;



	glMatrixMode(GL_MODELVIEW);
	//top
	glBegin(GL_QUADS);
	glVertex3f(+0.5, +0.5, +0.5); glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5, +0.5, +0.5); glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5, +0.5, -0.5); glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(+0.5, +0.5, -0.5); glNormal3f(0.0f, 1.0f, 0.0f);
	glEnd();

	//bottom
	glBegin(GL_QUADS);
	glVertex3f(+0.5, -0.5, +0.5); glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(-0.5, -0.5, +0.5); glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5); glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(+0.5, -0.5, -0.5); glNormal3f(0.0f, -1.0f, 0.0f);
	glEnd();

	//left
	glBegin(GL_QUADS);
	glVertex3f(+0.5, +0.5, +0.5); glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(+0.5, -0.5, +0.5); glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(+0.5, -0.5, -0.5); glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(+0.5, +0.5, -0.5); glNormal3f(1.0f, 0.0f, 0.0f);
	glEnd();


	//right
	glBegin(GL_QUADS);
	glVertex3f(-0.5, +0.5, +0.5); glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, +0.5); glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5); glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5, +0.5, -0.5); glNormal3f(-1.0f, 0.0f, 0.0f);
	glEnd();

	//front
	glBegin(GL_QUADS);
	glVertex3f(+0.5, +0.5, -0.5); glNormal3f(0.0f, 0.0f,-1.0f);
	glVertex3f(-0.5, +0.5, -0.5); glNormal3f(0.0f, 0.0f,-1.0f);
	glVertex3f(-0.5, -0.5, -0.5); glNormal3f(0.0f, 0.0f,-1.0f);
	glVertex3f(+0.5, -0.5, -0.5); glNormal3f(0.0f, 0.0f,-1.0f);
	glEnd();

	//back
	glBegin(GL_QUADS);
	glVertex3f(+0.5, +0.5, +0.5); glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5, +0.5, +0.5); glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5, -0.5, +0.5); glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(+0.5, -0.5, +0.5); glNormal3f(0.0f, 0.0f, 1.0f);
	glEnd();
}

