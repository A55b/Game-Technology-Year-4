#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

#include "Rend.h"

using namespace std;
using namespace glm;

GLuint VBO;
//const int NUMVERTS = 6;
const int numro = 2;
Rend myRenderObjects(numro);

static void renderSceneCallBack()
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < numro; i++)
	{
		myRenderObjects[i].render();
	}

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//glDrawArrays(GL_POINTS, 0, NUMVERTS);
	//glDrawArrays(GL_TRIANGLES, 0, NUMVERTS);
	//glDrawArrays(GL_TRIANGLES, 1, NUMVERTS);
	//glDrawArrays(GL_TRIANGLES, 2, NUMVERTS);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

static void initializeGlutCallbacks()
{
	glutDisplayFunc(renderSceneCallBack);
}

static void renderSceneCallBack()
{
	const int numVertsA = 1;
	vec2 verticesA[numVertsA];
	verticesA
}

static void createVertexBuffer()
{
	// Create some vertices to put in our VBO.
	vec3 vertices[NUMVERTS];
	vertices[0] = vec3(-0.5f, -0.5f, 0.0f);
	vertices[1] = vec3(0.5f, -0.5f, 0.0f);
	vertices[2] = vec3(0.0f, 0.5f, 0.0f);
	vertices[3] = vec3(0.5f, 1.5f, 0.0f);
	vertices[4] = vec3(-1.0f, 1.5f, 0.0f);
	vertices[5] = vec3(0.1f, 0.5f, 0.0f);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3) * NUMVERTS, vertices, GL_STATIC_DRAW);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Basic Application");

	initializeGlutCallbacks();

	// Must be done after glut is initialized!
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		cerr << "Error: " << glewGetErrorString(res) << "\n";
		return 1;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// Create a vertex buffer
	createVertexBuffer();

	glutMainLoop();

	return 0;
}