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




	

	
