#include "Eixo.h"



Eixo::Eixo()
{

	setColor(0, 0, 0);
	primitiveType = GL_LINES;
	addVertex(0, -100);
	addVertex(0, 100);
	addVertex(-100, 0);
	addVertex(100, 0);

}


Eixo::~Eixo()
{
}
