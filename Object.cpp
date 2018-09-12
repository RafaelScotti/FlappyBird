#include "Object.h"
#include "World.h"


Object::Object() : x(0), y(0), colorRGB{0.0f, 0.0f, 0.0f}, primitiveType(GL_LINE_LOOP)
{
	World::objects.push_back(this);
}


Object::~Object()
{
}

void Object::setColor(float r, float g, float b)
{
	colorRGB[0] = r;
	colorRGB[1] = g;
	colorRGB[2] = b;
	
}

void Object::addVertex(int x, int y)
{
	this->listVertex.push_back(Vertex(x, y));
}

void Object::draw() {
	glPushMatrix();
	glColor3f(colorRGB[0], colorRGB[1], colorRGB[2]);
	glBegin(primitiveType);
	for (int i = 0; i < listVertex.size(); i++) {
		glVertex2f(listVertex[i].x, listVertex[i].y);
	}
	glEnd();
	glPopMatrix();
}

//if (Q2V1.x >= Q1V1.x && Q2V1.x <= Q1V4.x) {
//	if (Q2V1.y >= Q1V2.y && Q2V1.y <= Q1V1.y) {
//		printf(“colisão”);
//	}
//}


void Object::colisao() {
	
	/*if(Q2V4.x >= Q1V1.x && Q2V4.x <= Q1V4.x){
		if(Q2V4.y >= Q1V2.y && Q2V4.y <= Q1V1.y){
			printf(“colisão”);
		}
	  }	*/

	if (World::objects[1]->getX(1) >= World::objects[0]->getX(1) && World::objects[1]->getX(1) <= World::objects[0]->getX(2)) {
		if (World::objects[1]->getY(1) >= World::objects[0]->getY(0) && World::objects[1]->getY(1) <= World::objects[0]->getY(1)) {
			cout << "COLISAO";
		}
	}
	else
	{
		if (World::objects[1]->getX(2) >= World::objects[0]->getX(1) && World::objects[1]->getX(2) <= World::objects[0]->getX(2)) {
			if (World::objects[1]->getY(2) >= World::objects[0]->getY(0) && World::objects[1]->getY(2) <= World::objects[0]->getY(1)) {
				cout << "COLISAO";
			}
		}
		else
		{
			if (World::objects[1]->getX(0) >= World::objects[0]->getX(1) && World::objects[1]->getX(0) <= World::objects[0]->getX(2)) {
				if (World::objects[1]->getY(0) >= World::objects[0]->getY(0) && World::objects[1]->getY(0) <= World::objects[0]->getY(1)) {
					cout << "COLISAO";
				}
			}
			else
			{
				if (World::objects[1]->getX(3) >= World::objects[0]->getX(1) && World::objects[1]->getX(3) <= World::objects[0]->getX(2)) {
					if (World::objects[1]->getY(3) >= World::objects[0]->getY(0) && World::objects[1]->getY(3) <= World::objects[0]->getY(1)) {
						cout << "COLISAO";
					}
				}
				else { // pipe 2 -------/ /-------------/ /-------------/ /------
					if (World::objects[1]->getX(1) >= World::objects[0]->getX(9) && World::objects[1]->getX(1) <= World::objects[0]->getX(10)) {
						if (World::objects[1]->getY(1) >= World::objects[0]->getY(8) && World::objects[1]->getY(1) <= World::objects[0]->getY(9)) {
							cout << "COLISAO";
						}
					}
					else
					{
						if (World::objects[1]->getX(2) >= World::objects[0]->getX(9) && World::objects[1]->getX(2) <= World::objects[0]->getX(10)) {
							if (World::objects[1]->getY(2) >= World::objects[0]->getY(8) && World::objects[1]->getY(2) <= World::objects[0]->getY(9)) {
								cout << "COLISAO";
							}
						}
						else
						{
							if (World::objects[1]->getX(0) >= World::objects[0]->getX(9) && World::objects[1]->getX(0) <= World::objects[0]->getX(10)) {
								if (World::objects[1]->getY(0) >= World::objects[0]->getY(8) && World::objects[1]->getY(0) <= World::objects[0]->getY(9)) {
									cout << "COLISAO";
								}
							}
							else
							{
								if (World::objects[1]->getX(3) >= World::objects[0]->getX(9) && World::objects[1]->getX(3) <= World::objects[0]->getX(10)) {
									if (World::objects[1]->getY(3) >= World::objects[0]->getY(8) && World::objects[1]->getY(3) <= World::objects[0]->getY(9)) {
										cout << "COLISAO";
									}
								}
							}
						}
					}
				}
			}
		}
	}
	// PIPE BOTTOM
	if (World::objects[1]->getX(0) >= World::objects[0]->getX(4) && World::objects[1]->getX(0) <= World::objects[0]->getX(7)) {
		if (World::objects[1]->getY(0) >= World::objects[0]->getY(5) && World::objects[1]->getY(0) <= World::objects[0]->getY(4)) {
			cout << "COLISAO";
		}
	}
	else
	{
		if (World::objects[1]->getX(3) >= World::objects[0]->getX(4) && World::objects[1]->getX(3) <= World::objects[0]->getX(7)) {
			if (World::objects[1]->getY(3) >= World::objects[0]->getY(5) && World::objects[1]->getY(3) <= World::objects[0]->getY(4)) {
				cout << "COLISAO";
			}
		}
		else
		{
			if (World::objects[1]->getX(1) >= World::objects[0]->getX(4) && World::objects[1]->getX(1) <= World::objects[0]->getX(7)) {
				if (World::objects[1]->getY(1) >= World::objects[0]->getY(5) && World::objects[1]->getY(1) <= World::objects[0]->getY(4)) {
					cout << "COLISAO";
				}
			}
			else
			{
				if (World::objects[1]->getX(2) >= World::objects[0]->getX(4) && World::objects[1]->getX(2) <= World::objects[0]->getX(7)) {
					if (World::objects[1]->getY(2) >= World::objects[0]->getY(5) && World::objects[1]->getY(2) <= World::objects[0]->getY(4)) {
						cout << "COLISAO";
					}
				}
				else { // pipe 2 -------/ /-------------/ /-------------/ /------
					if (World::objects[1]->getX(0) >= World::objects[0]->getX(12) && World::objects[1]->getX(0) <= World::objects[0]->getX(15)) {
						if (World::objects[1]->getY(0) >= World::objects[0]->getY(13) && World::objects[1]->getY(0) <= World::objects[0]->getY(12)) {
							cout << "COLISAO";
						}
					}
					else
					{
						if (World::objects[1]->getX(3) >= World::objects[0]->getX(12) && World::objects[1]->getX(3) <= World::objects[0]->getX(15)) {
							if (World::objects[1]->getY(3) >= World::objects[0]->getY(13) && World::objects[1]->getY(3) <= World::objects[0]->getY(12)) {
								cout << "COLISAO";
							}
						}
						else
						{
							if (World::objects[1]->getX(1) >= World::objects[0]->getX(12) && World::objects[1]->getX(1) <= World::objects[0]->getX(15)) {
								if (World::objects[1]->getY(1) >= World::objects[0]->getY(13) && World::objects[1]->getY(1) <= World::objects[0]->getY(12)) {
									cout << "COLISAO";
								}
							}
							else
							{
								if (World::objects[1]->getX(2) >= World::objects[0]->getX(12) && World::objects[1]->getX(2) <= World::objects[0]->getX(15)) {
									if (World::objects[1]->getY(2) >= World::objects[0]->getY(13) && World::objects[1]->getY(2) <= World::objects[0]->getY(12)) {
										cout << "COLISAO";
									}
								}
							}
						}
					}
				}
			}
		}
	} // COLISAO GROUND
	if (World::objects[1]->getX(0) >= World::objects[3]->getX(1) && World::objects[1]->getX(0) <= World::objects[3]->getX(2)) {
		if (World::objects[1]->getY(0) >= World::objects[3]->getY(0) && World::objects[1]->getY(0) <= World::objects[3]->getY(1)) {
			cout << "COLISAO";

		}
		else {
			if (World::objects[1]->getY(1) >= World::objects[4]->getY(0) && World::objects[1]->getY(1) <= World::objects[4]->getY(1)) {
				cout << "COLISAO";
			}
		}
	}
	
	
}

	

	
