#ifndef TmgRender_H
#define	TmgRender_H

#include <GL/glew.h>
#include <glm/glm.hpp>
using namespace glm;

class TmgRender
{
public:
	TMGRenderObject();
	bool createVboFromArray(vec3 vertexArray[], unsigned int size);
	void render();

private:
	GLuint vbo;
	unsigned int numVerts;

	//float size;
};


#endif