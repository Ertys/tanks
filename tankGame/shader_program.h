#pragma once

#include <GL\glew.h>
#include <iostream>
#include <stdlib.h>


static char* read_shader_file(const char *mFileName);

class shader_program
{
public:
	void load_shader(const char* pVertexFile, const char* pFragmentFile);
	void bind();
	void unbind();

	GLuint program_ID();

private:
	GLuint mVertex, mFragment, mProgram;
};

