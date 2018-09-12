#include "Sky.h"



Sky::Sky()
{

	setColor(0.69, 0.77, 0.87);
	primitiveType = GL_LINE;
	addVertex(-350, 500);
	addVertex(350, 500);

}


Sky::~Sky()
{
}
