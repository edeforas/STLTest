#include "MeshKernelLinkedTriangles.h"

#include <cassert>

///////////////////////////////////////////////////////////////////////////
TriangleLT::TriangleLT(int vertex1, int vertex2, int vertex3)
{
	_vertex1 = vertex1; _vertex2 = vertex2; _vertex3 = vertex3;
	_triangle1 = -1;
	_triangle2 = -1;
	_triangle3 = -1;
	_unlinked = 0; // if ==-1 -> unlinked;
	_reserved = 0;
}
///////////////////////////////////////////////////////////////////////////
VertexLT::VertexLT(const Point3& vertex) :
	_vertex(vertex)
{
	_oneTriangle = -1;
}
///////////////////////////////////////////////////////////////////////////
MeshKernelLinkedTriangles::MeshKernelLinkedTriangles()
{ }

MeshKernelLinkedTriangles::~MeshKernelLinkedTriangles()
{
	MeshKernelLinkedTriangles::clear();
}

void MeshKernelLinkedTriangles::clear()
{
	_vTriangles.clear();
	_vVertices.clear();
}
///////////////////////////////////////////////////////////////////////////
int MeshKernelLinkedTriangles::add_vertex(const Point3& vertex)
{
	_vVertices.push_back(VertexLT(vertex));
	return (int)_vVertices.size() - 1;
}

void MeshKernelLinkedTriangles::set_vertex(int iVertex, const Point3& vertex)
{
	assert(iVertex >= 0);
	assert(iVertex < (int)_vVertices.size());

	_vVertices[iVertex]._vertex = vertex;
}

void MeshKernelLinkedTriangles::get_vertex(int iVertex, Point3& vertex) const
{
	assert(iVertex >= 0);
	assert(iVertex < (int)_vVertices.size());

	vertex = _vVertices[iVertex]._vertex;
}

int MeshKernelLinkedTriangles::nb_vertices() const
{
	return (int)_vVertices.size();
}
///////////////////////////////////////////////////////////////////////////
int MeshKernelLinkedTriangles::add_triangle(int iVertex1, int iVertex2, int iVertex3)
{
	// vertices should exist:
	assert(iVertex1 >= 0);
	assert(iVertex1 < (int)_vVertices.size());
	assert(iVertex2 >= 0);
	assert(iVertex2 < (int)_vVertices.size());
	assert(iVertex3 >= 0);
	assert(iVertex3 < (int)_vVertices.size());

	_vTriangles.push_back(TriangleLT(iVertex1, iVertex2, iVertex3));
	int iTriangle = (int)(_vTriangles.size() - 1);

	// associate with near triangles
	int iT1 = _vVertices[iVertex1]._oneTriangle;
	int iT2 = _vVertices[iVertex2]._oneTriangle;
	int iT3 = _vVertices[iVertex3]._oneTriangle;

	// todo
	if (iT1 != -1)
	{

	}
	else
	{

	}

	// associate with vertex
	_vVertices[iVertex1]._oneTriangle = iTriangle;
	_vVertices[iVertex2]._oneTriangle = iTriangle;
	_vVertices[iVertex3]._oneTriangle = iTriangle;

	return iTriangle;
}

void MeshKernelLinkedTriangles::get_triangle(int iTriangle, int& iVertex1, int& iVertex2, int& iVertex3) const
{
	assert(iTriangle >= 0);
	assert(iTriangle < (int)_vTriangles.size());

	iVertex1 = _vTriangles[iTriangle]._vertex1;
	iVertex2 = _vTriangles[iTriangle]._vertex2;
	iVertex3 = _vTriangles[iTriangle]._vertex3;
}

void MeshKernelLinkedTriangles::unlink_triangle(int iTriangle)
{
	assert(iTriangle >= 0);
	assert(iTriangle < (int)_vTriangles.size());

	_vTriangles[iTriangle]._unlinked = -1;

	// with near triangles
	int iT1 = -1, iT2 = -1, iT3 = -1;
	get_near_triangles(iTriangle, iT1, iT2, iT3);

	//simple unoptimized code for now, todo use rotate_corner_CCW
	if (iT1 != -1)
	{
		TriangleLT& tmp = _vTriangles[iT1];
		if (tmp._triangle1 == iTriangle)
			tmp._triangle1 = -1;
		else if (tmp._triangle2 == iTriangle)
			tmp._triangle2 = -1;
		else if (tmp._triangle3 == iTriangle)
			tmp._triangle3 = -1;
	}

	if (iT2 != -1)
	{
		TriangleLT& tmp = _vTriangles[iT2];
		if (tmp._triangle1 == iTriangle)
			tmp._triangle1 = -1;
		else if (tmp._triangle2 == iTriangle)
			tmp._triangle2 = -1;
		else if (tmp._triangle3 == iTriangle)
			tmp._triangle3 = -1;
	}

	if (iT3 != -1)
	{
		TriangleLT& tmp = _vTriangles[iT3];
		if (tmp._triangle1 == iTriangle)
			tmp._triangle1 = -1;
		else if (tmp._triangle2 == iTriangle)
			tmp._triangle2 = -1;
		else if (tmp._triangle3 == iTriangle)
			tmp._triangle3 = -1;
	}

	// unlink with vertice

	// todo
}

bool MeshKernelLinkedTriangles::is_triangle_unlinked(int iTriangle)
{
	assert(iTriangle >= 0);
	assert(iTriangle < (int)_vTriangles.size());

	return _vTriangles[iTriangle]._unlinked == -1;
}

int MeshKernelLinkedTriangles::nb_triangles() const
{
	return (int)_vTriangles.size();
}

void MeshKernelLinkedTriangles::get_near_triangles(int iTriangle, int& iT1, int& iT2, int& iT3) const
{
	assert(iTriangle >= 0);
	assert(iTriangle < (int)_vTriangles.size());

	const TriangleLT& t = _vTriangles[iTriangle];

	iT1 = t._triangle1;
	iT2 = t._triangle2;
	iT3 = t._triangle3;
}
int MeshKernelLinkedTriangles::find_next_face_CCW(int iVertex, int iFace) const
{
	return 0;
}
///////////////////////////////////////////////////////////////////////////

