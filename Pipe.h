#pragma once
#include "Object.h"
#include "stdio.h"
#include <ctime>
#include <vector>
#include <iostream>

class Pipe :
	public Object
{
	bool seedFlag = false;
	int random(int _min, int _max);
	int pontoBase = random(-100, 500);





public:
	Pipe();
	~Pipe();

	void makePipe();
	void movePipe();

};

