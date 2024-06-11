#include "BodyDifference.h"

#include "MeshBoolean.h"
#include "Mesh.h"

///////////////////////////////////////////////////////////////////////////
BodyDifference::BodyDifference():
	Body()
{ 
	_A = ( Body*)nullptr;
	_B = ( Body*)nullptr;
}

BodyDifference::~BodyDifference()
{ }

void BodyDifference::set( Body& A, Body& B)
{
	_A = &A;
	_B = &B;
}

void BodyDifference::compute_mesh()
{
	Mesh Aonly, Bonly, AinB, BinA,meshA, meshB;
	MeshBoolean mb;
	_A->to_mesh(meshA);
	_B->to_mesh(meshB);

	mb.split_meshes(meshA, meshB, Aonly, Bonly, AinB, BinA);

	_mesh = Aonly;
	
	for (int i = 0; i < AinB.nb_triangles(); i++)
		AinB.flip_triangle(i);
	
	_mesh.add_mesh(AinB);
}
///////////////////////////////////////////////////////////////////////////