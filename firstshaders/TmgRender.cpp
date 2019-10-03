#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "TmgRender.h"
using namespace glm;


TmgRender::TMGRenderObject()
{

}

bool TmgRender::createVboFromArray(vec3 vertexArray[], unsigned int size)
{
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexArray), vertexArray, GL_STATIC_DRAW);
}

void TmgRender::render() {

}