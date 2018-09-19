#include "World.h"
#define FPS 60

std::vector<Object*> World::objects = std::vector<Object*>();

//Eixo meuEixo;

Sky sky;
Pipe pipe;
Bird bird;
Ground ground;
static Game game;

void  World::init()
{
	glClearColor(0.94, 1.0, 1.0, 1.0);
	pipe.makePipe();
	
}

void  World::update()
{
	if (!game.hasStarted()) {
		//show menu
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glClear(GL_COLOR_BUFFER_BIT);

		for (int i = 0; i < World::objects.size(); i++) {
			World::objects[i]->draw();

		}
		glutSwapBuffers();
	}
	else {

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glClear(GL_COLOR_BUFFER_BIT);

		for (int i = 0; i < World::objects.size(); i++) {
			World::objects[i]->draw();

		}

		pipe.movePipe(5);
		bird.fall();

		game.incScore();

		if (World::colisao()) {
			//pipe.movePipe(-5);
			if (bird.getY(1) > -350) {
				bird.fall();
			}

			game.stop();
			pipe.reset();
			bird.reset();

		}
		//glFlush();
		glutSwapBuffers();
		//glutSwapBuffers();
		//glutPostRedisplay();
	}
}

void World::inputCallback(int key, int x, int y)
{
	if (key == GLUT_KEY_UP) {
		if (!game.hasStarted()) {
			game.startGame();
			update();	
		}
		bird.jump();
	}
	//update();
	//glutPostRedisplay();
	//glutSwapBuffers();
}

void  World::reshapeCallback(int w, int h)
{
	glViewport(0, 0, (GLfloat)w, GLfloat(h));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w, w, -h, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void  World::timerCallback(int)
{
	//cout << "    time";
	//update();
	glutPostRedisplay();
	glutTimerFunc(1000/FPS, timerCallback, 0);
	
}

World::World(int argc, char **argv, std::string nome, int width, int height)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(500, 100);
	glutInitWindowSize(width, height);
	int mainWindow = glutCreateWindow(nome.c_str());
	glutDisplayFunc(update);

	/*glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glShadeModel(GL_SMOOTH);*/
	//glutIdleFunc(update);

	glutTimerFunc(1000 / FPS, timerCallback, 0);
	glutReshapeFunc(reshapeCallback);
	glutSpecialFunc(inputCallback);
	init();


	glutMainLoop();
}


void menu() {

}

bool World::colisao()
{
	if (bird.getX(1) >= pipe.getX(1) && bird.getX(1) <= pipe.getX(2)) {
		if (bird.getY(1) >= pipe.getY(0) && bird.getY(1) <= pipe.getY(1)) {
			return true;  // COLISAO
		}
	}
	else
	{
		if (bird.getX(2) >= pipe.getX(1) && bird.getX(2) <= pipe.getX(2)) {
			if (bird.getY(2) >= pipe.getY(0) && bird.getY(2) <= pipe.getY(1)) {
				return true;  // COLISAO
			}
		}
		else
		{
			if (bird.getX(0) >= pipe.getX(1) && bird.getX(0) <= pipe.getX(2)) {
				if (bird.getY(0) >= pipe.getY(0) && bird.getY(0) <= pipe.getY(1)) {
					return true;  // COLISAO
				}
			}
			else
			{
				if (bird.getX(3) >= pipe.getX(1) && bird.getX(3) <= pipe.getX(2)) {
					if (bird.getY(3) >= pipe.getY(0) && bird.getY(3) <= pipe.getY(1)) {
						return true;  // COLISAO
					}
				}
				else { // pipe 2 -------/ /-------------/ /-------------/ /------
					if (bird.getX(1) >= pipe.getX(9) && bird.getX(1) <= pipe.getX(10)) {
						if (bird.getY(1) >= pipe.getY(8) && bird.getY(1) <= pipe.getY(9)) {
							return true;  // COLISAO
						}
					}
					else
					{
						if (bird.getX(2) >= pipe.getX(9) && bird.getX(2) <= pipe.getX(10)) {
							if (bird.getY(2) >= pipe.getY(8) && bird.getY(2) <= pipe.getY(9)) {
								return true;  // COLISAO
							}
						}
						else
						{
							if (bird.getX(0) >= pipe.getX(9) && bird.getX(0) <= pipe.getX(10)) {
								if (bird.getY(0) >= pipe.getY(8) && bird.getY(0) <= pipe.getY(9)) {
									return true;  // COLISAO
								}
							}
							else
							{
								if (bird.getX(3) >= pipe.getX(9) && bird.getX(3) <= pipe.getX(10)) {
									if (bird.getY(3) >= pipe.getY(8) && bird.getY(3) <= pipe.getY(9)) {
										return true;  // COLISAO
									}
								}
							}
						}
					}
				}
			}
		}
	}
	// PIPE BOTTOM
	if (bird.getX(0) >= pipe.getX(4) && bird.getX(0) <= pipe.getX(7)) {
		if (bird.getY(0) >= pipe.getY(5) && bird.getY(0) <= pipe.getY(4)) {
			return true;  // COLISAO
		}
	}
	else
	{
		if (bird.getX(3) >= pipe.getX(4) && bird.getX(3) <= pipe.getX(7)) {
			if (bird.getY(3) >= pipe.getY(5) && bird.getY(3) <= pipe.getY(4)) {
				return true;  // COLISAO
			}
		}
		else
		{
			if (bird.getX(1) >= pipe.getX(4) && bird.getX(1) <= pipe.getX(7)) {
				if (bird.getY(1) >= pipe.getY(5) && bird.getY(1) <= pipe.getY(4)) {
					return true;  // COLISAO
				}
			}
			else
			{
				if (bird.getX(2) >= pipe.getX(4) && bird.getX(2) <= pipe.getX(7)) {
					if (bird.getY(2) >= pipe.getY(5) && bird.getY(2) <= pipe.getY(4)) {
						return true;  // COLISAO
					}
				}
				else { // pipe 2 -------/ /-------------/ /-------------/ /------
					if (bird.getX(0) >= pipe.getX(12) && bird.getX(0) <= pipe.getX(15)) {
						if (bird.getY(0) >= pipe.getY(13) && bird.getY(0) <= pipe.getY(12)) {
							return true;  // COLISAO
						}
					}
					else
					{
						if (bird.getX(3) >= pipe.getX(12) && bird.getX(3) <= pipe.getX(15)) {
							if (bird.getY(3) >= pipe.getY(13) && bird.getY(3) <= pipe.getY(12)) {
								return true;  // COLISAO
							}
						}
						else
						{
							if (bird.getX(1) >= pipe.getX(12) && bird.getX(1) <= pipe.getX(15)) {
								if (bird.getY(1) >= pipe.getY(13) && bird.getY(1) <= pipe.getY(12)) {
									return true;  // COLISAO
								}
							}
							else
							{
								if (bird.getX(2) >= pipe.getX(12) && bird.getX(2) <= pipe.getX(15)) {
									if (bird.getY(2) >= pipe.getY(13) && bird.getY(2) <= pipe.getY(12)) {
										return true;  // COLISAO
									}
								}
							}
						}
					}
				}
			}
		}
	}

	// COLISAO GROUND
	if (bird.getY(0) <= ground.getY(1)) {
		return true;  // COLISAO

	}
	// COLISAO SKY
	if (bird.getY(1) >= sky.getY(0)) {
		return true;  // COLISAO
	}



	return false;
}


bool World::target()
{
	if (bird.getX(2) >= pipe.getX(0) && bird.getX(2) < pipe.getX(3)) {
		if (bird.getY(2) < pipe.getY(0) && bird.getY(3) > pipe.getY(4)) {
			return true; // ponto
		}
	}
	else {
		if (bird.getX(2) >= pipe.getX(8) && bird.getX(2) < pipe.getX(11)) {
			if (bird.getY(2) < pipe.getY(8) && bird.getY(3) > pipe.getY(12)) {
				return true; // ponto
			}
		}
	}
	return false;
}



World::~World()
{
}




