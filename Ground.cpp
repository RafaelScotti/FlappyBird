#include "Ground.h"


Ground::Ground()
{
	
	setColor(0.18, 0.31, 0.31);
	
	primitiveType = GL_QUADS;
	addVertex(-500, -500);
	addVertex(-500, -350);
	addVertex(500, -350);
	addVertex(500, -500);
	glPushMatrix();
	
}


Ground::~Ground()
{
}
