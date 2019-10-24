#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

using namespace glm;

class Renderable
{
public:
	aitRenderObject();
	bool createVboFromArray(vec3 vertexArray[], unsigned int size);
	void render();

private:
	GLuint vbo;
	unsigned int numVerts;
};

