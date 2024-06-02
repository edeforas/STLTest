#include "SurfaceMesh.h"

///////////////////////////////////////////////////////////////////////////
SurfaceMesh::SurfaceMesh()
{ }

SurfaceMesh::~SurfaceMesh()
{ }

void SurfaceMesh::clear()
{
	_mesh.clear();
}

void SurfaceMesh::add_to_mesh(Mesh& m, int iNbSegments)
{
	(void)iNbSegments;
	m.add_mesh(_mesh);
}
///////////////////////////////////////////////////////////////////////////
Mesh& SurfaceMesh::mesh()
{
	return _mesh;
}