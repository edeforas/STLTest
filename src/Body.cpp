#include "Body.h"

///////////////////////////////////////////////////////////////////////////
Body::Body()
{
	clear();
}

Body::~Body()
{ }

void Body::clear()
{
	_faces.clear();
	_iNbSegments = 64;
	_iColor = -1;
}

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

vector<Face>& Body::faces()
{
	return _faces;
}

void Body::set_mesh_precision(int iPrecision)
{
	_iNbSegments = iPrecision;
	_mesh.clear(); // must recompute everything next time
}

void Body::set_color(int iColor)
{
	_iColor = iColor;
	_mesh.set_color(_iColor);

	auto& f = faces();
	for (auto& fa : f)
	{
		fa.set_color(iColor);
	}
}

///////////////////////////////////////////////////////////////////////////

void Body::compute_mesh()
{}