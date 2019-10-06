#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <Windows.h>
#include "TmgRender.h"

using namespace std;
using namespace glm;


void TmgRender::TMGRenderObject()
{

}

bool TmgRender::createVboFromArray(vec3 vertexArray[], unsigned int size)
{
	numVerts = size;
	cout << numVerts;
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

//GLuint TmgRender::Getvbo() {
//	return vbo;
//}