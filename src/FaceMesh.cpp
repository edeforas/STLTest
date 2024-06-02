#include "FaceMesh.h"

///////////////////////////////////////////////////////////////////////////
FaceMesh::FaceMesh()
{ }

FaceMesh::~FaceMesh()
{ }

void FaceMesh::clear()
{
	_mesh.clear();
}

void FaceMesh::add_to_mesh(Mesh& m, int iNbSegments)
{
	(void)iNbSegments;
	m.add_mesh(_mesh);
}
///////////////////////////////////////////////////////////////////////////
Mesh& FaceMesh::mesh()
{
	return _mesh;
}