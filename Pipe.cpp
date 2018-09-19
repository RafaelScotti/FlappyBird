#include "Pipe.h"

int Pipe::random(int _min, int _max)
{
	{
		if (!seedFlag)
		{
			srand(time(NULL));
			seedFlag = true;
		}
		else
			seedFlag = false;
		return _min + rand() % (_max - _min);
	}
}

void Pipe::makePipe()
{
	pontoBase = random(-10, 350);
	addVertex(350, pontoBase); // 0
	addVertex(350, 500);
	addVertex(440, 500);
	addVertex(440, pontoBase);
	//bottom
	addVertex(350, pontoBase - midSpace);
	addVertex(350, -350);
	addVertex(440, -350);
	addVertex(440, pontoBase - midSpace); // 7
	
									 // segundo pipe
									 //top
	pontoBase = random(-10, 100);
	addVertex(765, pontoBase); // 8
	addVertex(765, 500);
	addVertex(855, 500);
	addVertex(855, pontoBase);
	//bottom
	addVertex(765, pontoBase - midSpace);
	addVertex(765, -350);
	addVertex(855, -350);
	addVertex(855, pontoBase - midSpace);  // 15

}


void Pipe::movePipe(int speed) 
{
	for (int i = 0; i < listVertex.size();i++) {
		listVertex[i].x -= speed;
	}
	if (listVertex[0].x < -500) {

		pontoBase = random(-10, 400);

		listVertex[0].x += 850 ;  // 0
		listVertex[1].x += 850;  // 1
		listVertex[2].x += 850;  // 2
		listVertex[3].x += 850;  // 3
		listVertex[4].x += 850;  // 4
		listVertex[5].x += 850;  // 5
		listVertex[6].x += 850;  // 6 
		listVertex[7].x += 850;  // 7

		listVertex[0].y = pontoBase;
		listVertex[3].y = pontoBase;
		listVertex[4].y = pontoBase - midSpace;
		listVertex[7].y = pontoBase - midSpace;
	}
	if (listVertex[8].x < -500) {
		pontoBase = random(0, 400);

		listVertex[8].x += 850;  // 8
		listVertex[9].x += 850;  // 9
		listVertex[10].x += 850;  // 10
		listVertex[11].x += 850;  // 11
		listVertex[12].x += 850;  // 12
		listVertex[13].x += 850;  // 13
		listVertex[14].x += 850;  // 14 
		listVertex[15].x += 850;  // 15

		listVertex[8].y = pontoBase;
		listVertex[11].y = pontoBase;
		listVertex[12].y = pontoBase - midSpace;
		listVertex[15].y = pontoBase - midSpace;
	}

}

void Pipe::reset() {
	pontoBase = random(-10, 350);

	listVertex[0].x = 550;  // 0
	listVertex[0].y = pontoBase;
	listVertex[1].x = 550;  // 1
	listVertex[2].x = 640;  // 2
	listVertex[3].x = 640;  // 3
	listVertex[3].y = pontoBase;
	listVertex[4].x = 550;  // 4	
	listVertex[4].y = pontoBase - midSpace;
	listVertex[5].x = 550;  // 5
	listVertex[6].x = 640;  // 6 
	listVertex[7].x = 640;  // 7
	listVertex[7].y = pontoBase - midSpace;

	pontoBase = random(-10, 100);

	listVertex[8].x = 965;  // 8
	listVertex[8].y = pontoBase;
	listVertex[9].x = 965;  // 9
	listVertex[10].x = 1055;  // 10
	listVertex[11].x = 1055;  // 11
	listVertex[11].y = pontoBase;
	listVertex[12].x = 965;  // 12
	listVertex[12].y = pontoBase - midSpace;
	listVertex[13].x = 965;  // 13
	listVertex[14].x = 1055;  // 14 
	listVertex[15].x = 1055;  // 15
	listVertex[15].y = pontoBase - midSpace;
}

Pipe::Pipe()
{
	setColor(0.18, 0.31, 0.31);
	primitiveType = GL_QUADS;
}

Pipe::~Pipe()
{
}




