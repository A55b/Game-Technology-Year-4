#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <Windows.h>

#include "aiterror.h"
#include "TmgRender.h"

using namespace std;
using namespace glm;


void TmgRender::TMGRenderObject()
{

}

bool TmgRender::createVboFromArray(vec3 vertexArray[], unsigned int size)
{
	numVerts = size;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexArray), vertexArray, GL_STATIC_DRAW);
	
	return true;
}

void TmgRender::render() {
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, numVerts);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}
//
//string readFileToString(char* filename)
//{
//	ifstream file(filename, ios::in);
//	if (file.is_open())
//	{
//		stringstream continut;
//		continut << file.rdbuf();
//		continut << '\0';
//		return continut.str();
//	}
//	return "";
//}
//
//void TmgRender::CreateShaders() {
//	shaderProgram = glCreateProgram();
//
//	if (shaderProgram == 0)
//	{
//		AIT_ASSERT(0, "Error creating shader program\n");
//	}
//
//	string VS = readFileToString("vertexShader.glsl");
//	string FS = readFileToString("fragmentShader.glsl");
//
//	addShader(shaderProgram, VS.c_str(), GL_VERTEX_SHADER);
//	addShader(shaderProgram, FS.c_str(), GL_FRAGMENT_SHADER);
//
//	GLint success = 0;
//	GLchar errorLog[1024] = { 0 };
//
//	glLinkProgram(shaderProgram);
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (success == 0)
//	{
//		glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
//		std::stringstream ss;
//		ss << "Error linking shader program: " << errorLog << endl;
//		AIT_ASSERT(0, ss.str());
//	}
//
//	glValidateProgram(shaderProgram);
//	glGetProgramiv(shaderProgram, GL_VALIDATE_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
//		cerr << "Error linking shader program: " << errorLog << endl;
//		std::stringstream ss;
//		ss << "Error linking shader program: " << errorLog << endl;
//		AIT_ASSERT(0, ss.str());
//	}
//
//	glUseProgram(shaderProgram);
//}
//
//void TmgRender::addShader(GLuint shaderProgram, const char* pShaderText, GLenum shaderType)
//{
//	GLuint shaderObj = glCreateShader(shaderType);
//
//	if (shaderObj == 0)
//	{
//		std::stringstream ss;
//		ss << "Error creating shader type " << shaderType << endl;
//		AIT_ASSERT(0, ss.str());
//	}
//
//	const GLchar* p[1];
//	p[0] = pShaderText;
//	GLint Lengths[1];
//	Lengths[0] = strlen(pShaderText);
//	glShaderSource(shaderObj, 1, p, Lengths);
//	glCompileShader(shaderObj);
//	GLint success;
//	glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		GLchar InfoLog[1024];
//		glGetShaderInfoLog(shaderObj, 1024, NULL, InfoLog);
//		std::stringstream ss;
//		ss << "Error compiling shader type " << shaderType << ": " << InfoLog << endl;
//		AIT_ASSERT(0, ss.str());
//	}
//
//	glAttachShader(shaderProgram, shaderObj);
//}

//GLuint TmgRender::Getvbo() {
//	return vbo;
//}