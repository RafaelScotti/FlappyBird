#pragma once

#include "World.h"
//#include "Object.h"

//#include "Ground.h"
//#include "Sky.h"
//#include "Eixo.h"
//#include "Pipe.h"
//include "Bird.h"
class Bird;
class World;



class Game
{
	static int score;
	
public:
	Game();
	~Game();
	static bool start;
	
	static int incScore();
	static void startGame();
	static void restart();
	static void save(int score);
	static void exitGame();
	static bool hasStarted();
	static void update();
	static void stop();

};

