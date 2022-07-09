#include "Mesh.h"

#include <cassert>
#include <algorithm>

inline double square(double a)
{ return a*a; }

///////////////////////////////////////////////////////////////////////////
Triangle::Triangle(int vertex1, int vertex2, int vertex3)
{
	this->vertex1 = vertex1; this->vertex2 = vertex2; this->vertex3 = vertex3;
	state = 1; // 1=Valid; 0=deleted
}

bool Triangle::is_triangle_deleted() const
{
	return state==0;
}
void Triangle::flip()
{
	int iV1 = vertex1;
	vertex1 = vertex2;
	vertex2 = iV1;
}
///////////////////////////////////////////////////////////////////////////
Mesh::Mesh()
{ }

Mesh::~Mesh()
{ }

int Mesh::nb_triangles() const
{
	return (int)_vTriangles.size();
}
///////////////////////////////////////////////////////////////////////////
void Mesh::get_triangle(int iTriangle, Triangle3& f) const
{
	assert(iTriangle < (int)_vTriangles.size());

	int iP1, iP2, iP3;
	get_triangle(iTriangle, iP1, iP2, iP3);
	
	f.set_p1(_vVertices[iP1].vertex);
	f.set_p2(_vVertices[iP2].vertex);
	f.set_p3(_vVertices[iP3].vertex);
}

void Mesh::get_triangle(int iTriangle, int& iVertex1, int& iVertex2, int& iVertex3) const
{
	assert(iTriangle < (int)_vTriangles.size());

	iVertex1 = _vTriangles[iTriangle].vertex1;
	iVertex2 = _vTriangles[iTriangle].vertex2;
	iVertex3 = _vTriangles[iTriangle].vertex3;
}

void Mesh::get_triangle(int iTriangle, Point3 & p1, Point3& p2, Point3& p3) const
{
	assert(iTriangle < (int)_vTriangles.size());

	int iP1, iP2, iP3;
	get_triangle(iTriangle, iP1, iP2, iP3);

	get_vertex(iP1, p1);
	get_vertex(iP2, p2);
	get_vertex(iP3, p3);
}

bool Mesh::is_triangle_deleted(int iTriangle) const
{
	assert(iTriangle < (int)_vTriangles.size());
	return _vTriangles[iTriangle].is_triangle_deleted();
}

void Mesh::delete_triangle(int iTriangle)
{
	assert(iTriangle < (int)_vTriangles.size());

	// set bad state
	auto& iT = _vTriangles[iTriangle];
	iT.state = 0;

	//unlink vertex with faces
	_vVertices[iT.vertex1].remove_triangle(iTriangle);
	_vVertices[iT.vertex2].remove_triangle(iTriangle);
	_vVertices[iT.vertex3].remove_triangle(iTriangle);
}

void Mesh::add_mesh(const Mesh& f)
{
	// todo manage face ids

	int iNbVertices = nb_vertices();
	for (int i = 0; i < f.nb_vertices(); i++)
	{
		Point3 v;
		f.get_vertex(i, v);
		add_vertex(v);
	}

	int iVertex1, iVertex2, iVertex3;
	for (int i = 0; i < f.nb_triangles(); i++)
	{
		if (f.is_triangle_deleted(i))
			continue;

		f.get_triangle(i, iVertex1, iVertex2, iVertex3);
		add_triangle(iVertex1 + iNbVertices, iVertex2 + iNbVertices, iVertex3 + iNbVertices);
	}
}

int Mesh::add_triangle(int iVertex1, int iVertex2, int iVertex3)
{
	// vertices should exist:
	assert(iVertex1 < (int)_vVertices.size());
	assert(iVertex2 < (int)_vVertices.size());
	assert(iVertex3 < (int)_vVertices.size());

	_vTriangles.push_back(Triangle(iVertex1, iVertex2, iVertex3));

	int iTriangle = (int)(_vTriangles.size() - 1); // return the new iTriangle
	_vVertices[iVertex1].triangles.push_back(iTriangle);
	_vVertices[iVertex2].triangles.push_back(iTriangle);
	_vVertices[iVertex3].triangles.push_back(iTriangle);

	return iTriangle;
}

void Mesh::add_quad(int iVertex1, int iVertex2, int iVertex3, int iVertex4)
{
	add_triangle(iVertex1, iVertex2, iVertex3);
	add_triangle(iVertex3, iVertex4, iVertex1);
}

void Mesh::add_pentagon(int iVertex1, int iVertex2, int iVertex3, int iVertex4, int iVertex5)
{
	add_triangle(iVertex1, iVertex2, iVertex3);
	add_triangle(iVertex3, iVertex4, iVertex5);
	add_triangle(iVertex1, iVertex3, iVertex5);
}

void Mesh::split_triangle_with_vertex(int iTriangle, int iVertex)
{ 
	//replace triangle with 3 triangles built with iVertex
	int iV1, iV2, iV3;
	get_triangle(iTriangle, iV1, iV2, iV3);
	delete_triangle(iTriangle);

	add_triangle(iV1, iV2, iVertex);
	add_triangle(iV2, iV3, iVertex);
	add_triangle(iV3, iV1, iVertex);
}

void Mesh::flip_triangle(int iTriangle)
{ 	
	assert(iTriangle < (int)_vTriangles.size());
	_vTriangles[iTriangle].flip();
}

void Mesh::clear()
{
	_vTriangles.clear();
	_vVertices.clear();
}

bool Mesh::empty()
{
	return _vVertices.empty();
}

int Mesh::add_vertex(const Point3& vertex)
{
	VertexTriangles vf;
	vf.vertex = vertex;
	_vVertices.push_back(vf);
	return (int)_vVertices.size() - 1;
}

void Mesh::add_vertex(double a, double b, double c)
{
	add_vertex(Point3(a, b, c));
}

void Mesh::set_vertex(int iVertex, const Point3& vertex)
{
	assert(iVertex < (int)_vVertices.size());
	_vVertices[iVertex].vertex= vertex ;
}

void Mesh::get_vertex(int iVertex, Point3& vertex) const
{
	assert(iVertex < (int)_vVertices.size());
	vertex = _vVertices[iVertex].vertex;
}

int Mesh::nb_vertices() const
{
	return (int)_vVertices.size();
}

void VertexTriangles::remove_triangle(int iTriangle)
{
	auto it = find(triangles.begin(),triangles.end(),iTriangle);
	if (it != triangles.end())
		triangles.erase(it);
}
