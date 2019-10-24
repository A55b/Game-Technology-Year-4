#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>

using namespace glm;

class Rend
{
public:
	TMGRenderObject();
	bool createVboFromArray(vec3 vertexArray[], unsigned int size);
	void render();

private:
	GLuint vbo;
	unsigned int numVerts;
};

//#pragma once
//#include <GL/glew.h>
//#include <glm/glm.hpp>
//
//using namespace glm;
//
//class Rend
//{
//public:
//	aitRenderObject();
//	bool createVboFromArray(vec3 vertexArray[], unsigned int size);
//	void render();
//
//private:
//	GLuint vbo;
//	unsigned int numVerts;
//};
