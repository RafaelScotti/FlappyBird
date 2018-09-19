#pragma once
#include "Object.h"


class Pipe :
	public Object
{
	bool seedFlag = false;
	int random(int _min, int _max);
	int pontoBase = random(-10, 400);
	int midSpace = 230;
	



public:
	Pipe();
	~Pipe();

	void makePipe();
	void movePipe(int speed);
	void reset();
};

