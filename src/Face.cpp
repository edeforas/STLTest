#include "Face.h"

#include <cassert>

///////////////////////////////////////////////////////////////////////////
Face::Face()
{
	_iColor = 0x808080; //grey
}

Face::~Face()
{ 
}

void Face::set_color(int iColor)
{
	_iColor = iColor;
}

void Face::to_mesh(Mesh& m,int iNbSegments)
{
	m.clear();
	for (auto& s : _vSurfaces)
		s.add_to_mesh(m, iNbSegments);
}

vector<Surface>& Face::faces()
{
	return _vSurfaces;
}