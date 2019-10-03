#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Rend.h"

void Rend::render()
{
	glewInit();


}

bool Rend::createVboFromArray(vec3 vertexArray[], unsigned int size)
{
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * size, vertexArray, GL_STATIC_DRAW);
}

Rend::TMGRenderObject()
{
}
