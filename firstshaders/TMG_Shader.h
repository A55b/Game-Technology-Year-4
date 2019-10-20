#ifndef TmgShader_H
#define	TmgShader_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <Windows.h>
using namespace std;
using namespace glm;

class TmgShader
{
public:

	void CreateShaders();
	string readFileToString(char* filename);
	void addShader(GLuint shaderProgram, const char* pShaderText, GLenum shaderType);
	//GLuint Getvbo();

private:

	GLuint shaderProgram;
	float size;
};



#endif