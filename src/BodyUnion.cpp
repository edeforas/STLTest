#include "BodyUnion.h"

#include "MeshBoolean.h"
#include "Mesh.h"

///////////////////////////////////////////////////////////////////////////
BodyUnion::BodyUnion() :
	Body()
{
	_A = (Body*)nullptr;
	_B = (Body*)nullptr;
}

BodyUnion::~BodyUnion()
{ }

void BodyUnion::set(Body& A, Body& B)
{
	_A = &A;
	_B = &B;
}

void BodyUnion::compute_mesh()
{
	Mesh Aoutside, Boutside, AinB, BinA,meshA, meshB;
	MeshBoolean mb;

	_A->to_mesh(meshA);
	_B->to_mesh(meshB);

	mb.split_meshes(meshA,meshB, Aoutside, Boutside, AinB, BinA);

	_mesh.clear();
	_mesh.add_mesh(Aoutside);
	_mesh.add_mesh(Boutside);
}
///////////////////////////////////////////////////////////////////////////