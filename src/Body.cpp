#include "Body.h"

///////////////////////////////////////////////////////////////////////////
Body::Body()
{ 
	_iNbSegments = 64;
	_iColor = -1;
}

Body::~Body()
{ }

Transform& Body::transform()
{
	return _transform;
}

Mesh& Body::mesh()
{
	compute_mesh();
	if(_iColor!=-1)
		_mesh.set_color(_iColor);
	return _mesh;
}

void Body::set_precision(int iPrecision)
{
	_iNbSegments = iPrecision;
	_mesh.clear(); // must recompute everything next time
}

void Body::set_color(int iColor)
{
	_iColor = iColor;
	_mesh.set_color(_iColor);
}

///////////////////////////////////////////////////////////////////////////