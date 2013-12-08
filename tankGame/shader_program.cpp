#include "shader_program.h"

static char* read_shader_file(const char *mFileName)
{
	char* text = new char[0];

	if (mFileName != NULL) {
		FILE *file;
		fopen_s(&file, mFileName, "rt");

		if (file != NULL) {
			fseek(file, 0, SEEK_END);
			int count = ftell(file);
			rewind(file);

			if (count > 0) {
				text = (char*)malloc(sizeof(char)* (count + 1));
				count = fread(text, sizeof(char), count, file);
				text[count] = '\0';
			}
			fclose(file);
		}
		else
		std::cout << "FILE NOT FOUND!\n";
	}
	std::cout << text << std::endl;
	return text;
}

void shader_program::load_shader(const char* pVertexFile, const char* pFragmentFile)
{
	mVertex		= glCreateShader(GL_VERTEX_SHADER);
	mFragment	= glCreateShader(GL_FRAGMENT_SHADER);

	const char* vsText = read_shader_file(pVertexFile);
	const char* fsText = read_shader_file(pFragmentFile);

	if (vsText == NULL || fsText == NULL) {
		return;
	}

	glShaderSource(mVertex,		1, &vsText, 0);
	glShaderSource(mFragment,	1, &fsText, 0);

	glCompileShader(mVertex);
	glCompileShader(mFragment);

	mProgram = glCreateProgram();
	glAttachShader(mProgram, mVertex);
	glAttachShader(mProgram, mFragment);
	glLinkProgram(mProgram);
}
void shader_program::bind()
{
	glUseProgram(mProgram);
}
void shader_program::unbind()
{
	glUseProgram(0);
}

GLuint shader_program::program_ID()
{
	return mProgram;
}