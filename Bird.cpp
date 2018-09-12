#include "Bird.h"



Bird::Bird()
{
	
	setColor(1, 0, 0);
	primitiveType = GL_QUADS;

	addVertex(-50, -40);
	addVertex(-50, 0);
	addVertex(0, 0);
	addVertex(0, -40);

}


Bird::~Bird()
{
}

void Bird::jump()
{
	for (int i = 0; i < listVertex.size(); i++) {
		listVertex[i].y += 100;
	}
}

void Bird::fall()
{
	for (int i = 0; i < listVertex.size(); i++) {
		listVertex[i].y -= 5;
	}
}
