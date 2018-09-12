#pragma once
#define GLEW_STATIC
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <vector>
using namespace std;

struct Vertex {
	int x, y;
	Vertex(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class Object
{
protected:
	int x, y;
	float colorRGB[3];
	GLenum primitiveType;
	std::vector<Vertex> listVertex;
	void setColor(float r, float g, float b);
	void addVertex(int x, int y);

public:

	Object();
	~Object();

	int getX(int x) {
		return listVertex[x].x;
	}
	int getY(int y) {
		return listVertex[y].y;
	}

	void draw();

	
	void colisao();

};

