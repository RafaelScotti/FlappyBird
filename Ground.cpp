#include "Ground.h"


Ground::Ground()
{
	

	setColor(0.43, 0.21, 0.1);
	primitiveType = GL_QUADS;
	addVertex(-350, -500);
	addVertex(-350, -350);
	addVertex(350, -350);
	addVertex(350, -500);
	glPushMatrix();
	
}


Ground::~Ground()
{
}
