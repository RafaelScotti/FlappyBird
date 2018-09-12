#include "World.h"

std::vector<Object*> World::objects = std::vector<Object*>();
Pipe pipe;
Bird bird;


void init()
{
	glClearColor(0.94, 1.0, 1.0, 1.0);
	pipe.makePipe();
	//pipe2.makePipe2();
	
}

void update()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	
	
	pipe.movePipe();
	bird.fall();
	
	bird.colisao();

	for (int i = 0; i < World::objects.size(); i++)
	{
		World::objects[i]->draw();
	}
	
	
	

	glutSwapBuffers();

}

void displayCallback(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	
	
	update();
	//update();

	glutSwapBuffers();
}

void inputCallback(int key, int x, int y)
{
	if (key == GLUT_KEY_UP) {

		bird.jump();
		
		
	}
	//glFlush();
	update();
}

void reshapeCallback(int w, int h)
{
	glViewport(0, 0, (GLfloat)w, GLfloat(h));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w, w, -h, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void timerCallback(int)
{
	glutPostRedisplay();
	glutTimerFunc(100, timerCallback, 0);
}



World::World(int argc, char **argv, std::string nome, int width, int height)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(400, 100);
	glutInitWindowSize(width, height);
	glutCreateWindow(nome.c_str());
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);
	glutSpecialFunc(inputCallback);
	glutTimerFunc(100, timerCallback, 0);
	glutIdleFunc(update);
	init();
	
	
	

	glutMainLoop();
}

World::~World()
{
}
