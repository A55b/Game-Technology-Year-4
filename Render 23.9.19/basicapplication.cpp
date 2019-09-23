#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <Rend.h>

using namespace std;

float red = 0.0f;
float blue = 0.0f;

static void renderSceneCallBack()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

static void processNormalKeys(unsigned char key, int x, int y) 
{

	if (key == 'a')
	{
		 glClearColor(0.0f, 1.0f, 0.0f, 0.0f); 
	}
	else if (key == 'b')
	{
		 glClearColor(0.0f, 0.0f, 1.0f, 0.0f); 
	}
}

void mouseWheel(int button, int dir, int x, int y)
{
	if (dir > 0)
	{
		if (red < 0.9f && blue == 0.0f)
		{
			red = red + 0.1f;
			glClearColor(red, 0.0f, 0.0f, 0.0f);
		}
		else if (red == 0.0f && blue < 0.9f)
		{
			blue = blue - 0.1f;
			glClearColor(red, 0.0f, blue, 0.0f);
		}
	}
	else if (dir < 0)
	{
		if (red == 0.0f && blue <= 0.9f)
		{
			red = red - 0.1f;
			glClearColor(red, 0.0f, blue, 0.0f);
		}
		else if (red >= 0.9f && blue == 0.0f)
		{
			blue = blue + 0.1f;
			glClearColor(red, 0.0f, blue, 0.0f);
		}
		//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}
	else if (button > 0)
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	}

	return;
}

static void initializeGlutCallbacks()
{
    glutDisplayFunc(renderSceneCallBack);
	glutIdleFunc(renderSceneCallBack);
	glutMouseWheelFunc(mouseWheel);
	//glutKeyboardFunc(processNormalKeys);
}




int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Basic Application");

    initializeGlutCallbacks();

    // Must be done after glut is initialized!
    GLenum res = glewInit();
    if (res != GLEW_OK) 
    {
		cerr<<"Error: "<<glewGetErrorString(res)<<"\n";
		return 1;
    }

    glClearColor(1.0f, 0.0f, 0.0f, 0.0f); 

    glutMainLoop();
    
    return 0;
}