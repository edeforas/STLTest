#include "BodyIntersection.h"

#include "MeshBoolean.h"
#include "Mesh.h"

///////////////////////////////////////////////////////////////////////////
BodyIntersection::BodyIntersection() :
	Body()
{
	_A = (Body*)nullptr;
	_B = (Body*)nullptr;
}

BodyIntersection::~BodyIntersection()
{ }

void BodyIntersection::set(Body& A, Body& B)
{
	_A = &A;
	_B = &B;
}

void BodyIntersection::compute_mesh()
{
	Mesh Aonly, Bonly, AinB, BinA,meshA,meshB;
	MeshBoolean mb;
	_A->to_mesh(meshA);
	_B->to_mesh(meshB);

	mb.split_meshes(meshA, meshB, Aonly, Bonly, AinB, BinA);

	for (int i = 0; i < AinB.nb_triangles(); i++)
		AinB.flip_triangle(i);

	for (int i = 0; i < BinA.nb_triangles(); i++)
		BinA.flip_triangle(i);

	_mesh = AinB;
	_mesh.add_mesh(BinA);
}
///////////////////////////////////////////////////////////////////////////