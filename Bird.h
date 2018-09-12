#pragma once
#include "Object.h"
class Bird :
	public Object
{
public:
	Bird();
	~Bird();

	void jump();
	void fall();
};

