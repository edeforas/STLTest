#include "Body.h"

///////////////////////////////////////////////////////////////////////////
Body::Body()
{ 
	_iNbSegments = 64;
}

Body::~Body()
{ }

Transform& Body::transform()
{
	return _transform;
}

Mesh& Body::mesh()
{
	compute_faces();
	return _mesh;
}

void Body::set_precision(int iPrecision)
{
	_iNbSegments = iPrecision;
	_mesh.clear(); // must recompute everything next time
}
///////////////////////////////////////////////////////////////////////////