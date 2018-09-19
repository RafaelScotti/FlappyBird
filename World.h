#pragma once
//#include <Windows.h>
//#define GLEW_STATIC
#include "GL\glew.h"
#include "GL\freeglut.h"

#include <cmath>
#include <ctime>

#include "Object.h"
#include "Ground.h"
#include "Sky.h"
#include "Eixo.h"
#include "Pipe.h"
#include "Bird.h"
#include "Game.h"

class Game;
class Bird;
class Ground;
class Sky;
class Eixo;
class Pipe;

class World
{	
	std::string nome;
	int w, h;
		
public:

	static Bird b;

	World(int argc, char **argv, std::string nome, int width = 350, int height = 500);
	~World();
	static void init();	
	static void inputCallback(int, int, int);
	static void reshapeCallback(int, int);
	static void timerCallback(int);
	static void update();
	static bool colisao();
	static bool target();
	static std::vector<Object*> objects;
	Object* getObject(int x) {
		return objects[x];
	}	
};

