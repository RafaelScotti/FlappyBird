#pragma once
#include "Object.h"

class Bird :
	public Object
{
	int peso = 1;
	int ac = 1;
	int vel = 0;


public:
	Bird();
	~Bird();

	void jump();
	void fall();
	void reset();
};

