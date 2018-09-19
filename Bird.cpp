#include "Bird.h"



Bird::Bird()
{
	setColor(1, 0, 0);
	primitiveType = GL_QUADS;
	addVertex(-60, -50);
	addVertex(-60, 0);
	addVertex(0, 0);
	addVertex(0, -50);
}


Bird::~Bird()
{
}


void Bird::jump()
{
	//cout << "\n======= JUMPING ========";
	ac = 1;
	vel = 14;
	vel += ac;
	vel *= -1;
	for (int i = 0; i < listVertex.size(); i++) {
		listVertex[i].y -= vel;
	}
	
}

void Bird::fall()
{
	ac = 1;
	vel += ac;
	
	if (listVertex[0].y <= -350) {
		ac = 0;
		vel = 0;
	}
	else {

		for (int i = 0; i < listVertex.size(); i++) {
			listVertex[i].y -= vel;
 		}
	}	
	
}

void Bird::reset()
{
	listVertex[0].x = -60;
	listVertex[0].y = -50;

	listVertex[1].x = -60;
	listVertex[1].y =  0;
		
	listVertex[2].x =  0;
	listVertex[2].y =  0;

	listVertex[3].x =  0;
	listVertex[3].y = -50;

}
