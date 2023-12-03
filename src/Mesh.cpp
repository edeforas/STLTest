#include "Mesh.h"

#include <cassert>

#include "MeshKernelTIN.h"
#include "MeshKernelHalfEdge.h"
#include "MeshKernelLinkedTriangles.h"

#include "Util.h"

///////////////////////////////////////////////////////////////////////////
Mesh::Mesh()
{ 
	//_pKernel=new MeshKernelTIN;
	//_pKernel =new MeshKernelHalfEdge;
	_pKernel = new MeshKernelLinkedTriangles;
	_iColor = -1;
}

Mesh::Mesh(const Mesh& m)
{
	this->operator=(m);
}

Mesh::~Mesh()
{ 
	delete _pKernel;
}

void Mesh::set_color(int iColor)
{
	_iColor = iColor;
}

int Mesh::get_color() const
{
	return _iColor;
}

int Mesh::nb_triangles() const
{
	return _pKernel->nb_triangles();
}

bool Mesh::is_triangle_unlinked(int iTriangle) const
{
	assert(iTriangle >= 0);
	assert(iTriangle < _pKernel->nb_triangles());

	return _pKernel->is_triangle_unlinked(iTriangle);
}
void Mesh::get_near_triangles(int iTriangle, int& iT1, int& iT2, int& iT3) const
{
	assert(iTriangle >= 0);
	assert(iTriangle < _pKernel->nb_triangles());

	return _pKernel->get_near_triangles(iTriangle,iT1,iT2,iT3);
}
///////////////////////////////////////////////////////////////////////////
void Mesh::get_triangle(int iTriangle, Triangle3& f) const
{
	assert(iTriangle >= 0);
	assert(iTriangle < _pKernel->nb_triangles());

	int iP1, iP2, iP3;
	get_triangle(iTriangle, iP1, iP2, iP3);
	
	Point3 v1,v2,v3;
	_pKernel->get_vertex(iP1,v1);
	_pKernel->get_vertex(iP2,v2);
	_pKernel->get_vertex(iP3,v3);
	
	f.set_p1(v1);
	f.set_p2(v2);
	f.set_p3(v3);
}

void Mesh::get_triangle(int iTriangle, int& iVertex1, int& iVertex2, int& iVertex3) const
{
	assert(iTriangle >= 0);
	assert(iTriangle < _pKernel->nb_triangles());

	_pKernel->get_triangle(iTriangle,iVertex1,iVertex2,iVertex3);
}

void Mesh::get_triangle(int iTriangle, Point3& p1, Point3& p2, Point3& p3) const
{
	assert(iTriangle >= 0);
	assert(iTriangle < _pKernel->nb_triangles());

	int iP1, iP2, iP3;
	get_triangle(iTriangle, iP1, iP2, iP3);

	_pKernel->get_vertex(iP1, p1);
	_pKernel->get_vertex(iP2, p2);
	_pKernel->get_vertex(iP3, p3);
}

void Mesh::unlink_triangle(int iTriangle)
{
	assert(iTriangle >= 0);
	assert(iTriangle < _pKernel->nb_triangles());

	_pKernel->unlink_triangle(iTriangle);
}

Mesh& Mesh::operator=(const Mesh& m)
{
	//todo something quicker

	clear();
	add_mesh(m);
	set_color(m.get_color());

	return *this;
}

void Mesh::add_mesh(const Mesh& f)
{
	// todo manage face ids

	//todo manage color by vertex
	_iColor = f.get_color();

	int iNbVertices = nb_vertices();
	for (int i = 0; i < f.nb_vertices(); i++)
	{
		Point3 v;
		f.get_vertex(i, v);
		_pKernel->add_vertex(v);
	}

	int iVertex1, iVertex2, iVertex3;
	for (int i = 0; i < f.nb_triangles(); i++)
	{
		if (f.is_triangle_unlinked(i))
			continue;

		f.get_triangle(i, iVertex1, iVertex2, iVertex3);
		add_triangle(iVertex1 + iNbVertices, iVertex2 + iNbVertices, iVertex3 + iNbVertices);
	}
}

int Mesh::add_triangle(int iVertex1, int iVertex2, int iVertex3)
{
	assert(iVertex1 >= 0);
	assert(iVertex2 >= 0);
	assert(iVertex3 >= 0);

	assert(iVertex1 < _pKernel->nb_vertices());
	assert(iVertex2 < _pKernel->nb_vertices());
	assert(iVertex3 < _pKernel->nb_vertices());

	return _pKernel->add_triangle(iVertex1,iVertex2,iVertex3);
}

void Mesh::add_quad(int iVertex1, int iVertex2, int iVertex3, int iVertex4)
{
	assert(iVertex1 >= 0);
	assert(iVertex2 >= 0);
	assert(iVertex3 >= 0);
	assert(iVertex4 >= 0);

	assert(iVertex1 < _pKernel->nb_vertices());
	assert(iVertex2 < _pKernel->nb_vertices());
	assert(iVertex3 < _pKernel->nb_vertices());
	assert(iVertex4 < _pKernel->nb_vertices());

	_pKernel->add_triangle(iVertex1, iVertex2, iVertex3);
	_pKernel->add_triangle(iVertex3, iVertex4, iVertex1);
}

void Mesh::add_pentagon(int iVertex1, int iVertex2, int iVertex3, int iVertex4, int iVertex5)
{
	assert(iVertex1 >= 0);
	assert(iVertex2 >= 0);
	assert(iVertex3 >= 0);
	assert(iVertex4 >= 0);
	assert(iVertex5 >= 0);

	assert(iVertex1 < _pKernel->nb_vertices());
	assert(iVertex2 < _pKernel->nb_vertices());
	assert(iVertex3 < _pKernel->nb_vertices());
	assert(iVertex4 < _pKernel->nb_vertices());
	assert(iVertex5 < _pKernel->nb_vertices());

	_pKernel->add_triangle(iVertex1, iVertex2, iVertex3);
	_pKernel->add_triangle(iVertex3, iVertex4, iVertex5);
	_pKernel->add_triangle(iVertex1, iVertex3, iVertex5);
}

void Mesh::split_triangle_with_vertex(int iTriangle, int iVertex)
{ 
	assert(iTriangle >= 0);
	assert(iTriangle < _pKernel->nb_triangles());

	assert(iVertex >= 0);
	assert(iVertex < _pKernel->nb_vertices());

	//replace triangle with 3 triangles built with iVertex
	int iV1, iV2, iV3;
	_pKernel->get_triangle(iTriangle, iV1, iV2, iV3);
	_pKernel->unlink_triangle(iTriangle);

	_pKernel->add_triangle(iV1, iV2, iVertex);
	_pKernel->add_triangle(iV2, iV3, iVertex);
	_pKernel->add_triangle(iV3, iV1, iVertex);
}
//////////////////////////////////////////////////////////////////////////////////
// split edge at new vertice
// return false if vertices are not sharing triangles edges
bool Mesh::split_edge_with_vertex(int iVertex1, int iVertex2, int iVertexSplit) // 4 new triangles added at the end
{
	int iTriangle1, iTriangle2;
	bool bOk=_pKernel->get_triangles_near_edge(iVertex1, iVertex2, iTriangle1, iTriangle2);
	if (!bOk)
		return false;

	assert(iTriangle1 != -1);
	assert(iTriangle2 != -1);

	//split triangle1
	int iV1, iV2, iV3;
	_pKernel->get_triangle(iTriangle1, iV1, iV2, iV3);
	if (iV1 != iVertex1)
		rotate(iV1, iV2, iV3);
	if (iV1 != iVertex1)
		rotate(iV1, iV2, iV3);
	assert(iV1 == iVertex1);

	_pKernel->add_triangle(iV1, iVertexSplit, iV3);
	_pKernel->add_triangle(iVertexSplit, iV2, iV3);
	_pKernel->unlink_triangle(iTriangle1);

	//split triangle2
	_pKernel->get_triangle(iTriangle2, iV1, iV2, iV3);
	if (iV2 != iVertex2)
		rotate(iV1, iV2, iV3);
	if (iV2 != iVertex2)
		rotate(iV1, iV2, iV3);
	assert(iV2 == iVertex2);

	_pKernel->add_triangle(iV2, iVertexSplit, iV3);
	_pKernel->add_triangle(iVertexSplit, iV1, iV3);
	_pKernel->unlink_triangle(iTriangle2);

	return true;
}
//////////////////////////////////////////////////////////////////////////////////
void Mesh::flip_triangle(int iTriangle)
{ 	
	assert(iTriangle >= 0);
	assert(iTriangle < _pKernel->nb_triangles());

	int iV1, iV2, iV3;
	_pKernel->get_triangle(iTriangle, iV1, iV2, iV3);
	_pKernel->unlink_triangle(iTriangle);
	_pKernel->add_triangle(iV1, iV3, iV2);
}
//////////////////////////////////////////////////////////////////////////////////
void Mesh::clear()
{
	_pKernel->clear();
}

bool Mesh::empty() const
{
	return _pKernel->nb_triangles()==0;
}

int Mesh::add_vertex(const Point3& vertex)
{
	return _pKernel->add_vertex(vertex);
}

void Mesh::add_vertex(double a, double b, double c)
{
	_pKernel->add_vertex(Point3(a, b, c));
}

void Mesh::set_vertex(int iVertex, const Point3& vertex)
{
	assert(iVertex >= 0);
	assert(iVertex < _pKernel->nb_vertices());

	_pKernel->set_vertex(iVertex,vertex);
}

void Mesh::get_vertex(int iVertex, Point3& vertex) const
{
	assert(iVertex >= 0);
	assert(iVertex < _pKernel->nb_vertices());

	_pKernel->get_vertex(iVertex,vertex);
}

int Mesh::nb_vertices() const
{
	return _pKernel->nb_vertices();
}