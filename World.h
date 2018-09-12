#pragma once
#include <Windows.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <cmath>
#include "Object.h"

#include "Eixo.h"
#include "Pipe.h"
#include "Bird.h"
#include "Ground.h"
#include "Sky.h"

class World
{
	
	Eixo meuEixo;
	Ground ground;
	Sky sky;
	std::string nome;
	int w, h;


	
public:
	static std::vector<Object*> objects;

	Object* getObject(int x) {
		return objects[x];
	}
	World(int argc, char **argv, std::string nome, int width = 350, int height = 500);
	~World();

	/*void init();
	void displayCallback();
	void inputCallback(int, int, int);
	void reshapeCallback(int, int);
	void timerCallback(int);
	void update();*/
	
	
	

	
};

