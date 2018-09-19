#include "Sky.h"



Sky::Sky()
{

	setColor(0.41, 0.41, 0.41);
	primitiveType = GL_LINES;
	addVertex(-350, 500);
	addVertex(350, 500);

}


Sky::~Sky()
{
}
