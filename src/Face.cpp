#include "Face.h"

#include <cassert>

///////////////////////////////////////////////////////////////////////////
Face::Face()
{
	_iColor = 0x808080; //grey
}

Face::~Face()
{ }

void Face::set_color(int iColor)
{
	_iColor = iColor;
}
