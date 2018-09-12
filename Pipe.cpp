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
	// primeiro pipe
	//top
	pontoBase = random(-100, 300);
	addVertex(350, pontoBase); // 0
	addVertex(350, 500);
	addVertex(500, 500);
	addVertex(500, pontoBase);
	//bottom
	addVertex(350, pontoBase - 200);
	addVertex(350, -350);
	addVertex(500, -350);
	addVertex(500, pontoBase - 200); // 7

	// segundo pipe
	//top
	pontoBase = random(-100, 500);
	addVertex(765, pontoBase); // 8
	addVertex(765, 500);
	addVertex(915, 500);
	addVertex(915, pontoBase);
	//bottom
	addVertex(765, pontoBase - 200);
	addVertex(765, -350);
	addVertex(915, -350);
	addVertex(915, pontoBase - 200);  // 15
}



void Pipe::movePipe() {
	////pontoBase = random(-100, 500);
	//listVertex[0].x--;  // 0
	//listVertex[1].x--;  // 1
	//listVertex[2].x--;  // 2
	//listVertex[3].x--;  // 3
	//listVertex[4].x--;  // 4
	//listVertex[5].x--;  // 5
	//listVertex[6].x--;  // 6 
	//listVertex[7].x--;  // 7
	// 
	//listVertex[8].x--;  // 8
	//listVertex[9].x--;  // 9
	//listVertex[10].x--;  // 10
	//listVertex[11].x--;  // 11
	//listVertex[12].x--;  // 12
	//listVertex[13].x--;  // 13
	//listVertex[14].x--;  // 14
	//listVertex[15].x--;  // 15

	for (int i = 0; i < listVertex.size();i++) {
		listVertex[i].x -= 2;
	}
	//pontoBase = random(-100, 300);
	if (listVertex[0].x < -500) {
		pontoBase = random(-250, 500);
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

		listVertex[4].y = pontoBase-200;
		listVertex[7].y = pontoBase-200;
	}
	if (listVertex[8].x < -500) {
		pontoBase = random(-100, 500);
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

		listVertex[12].y = pontoBase - 200;
		listVertex[15].y = pontoBase - 200;
	}

}



Pipe::Pipe()
{
	setColor(0.68, 1, 0.18);
	primitiveType = GL_QUADS;
	
}


Pipe::~Pipe()
{
}




