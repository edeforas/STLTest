#include "Solid.h"

///////////////////////////////////////////////////////////////////////////
Point3::Point3(float x, float y, float z)
{
	_x = x; _y = y; _z = z;
}
///////////////////////////////////////////////////////////////////////////
Triangle::Triangle(Point3 p1, Point3 p2, Point3 p3)
{
	_p1 = p1;	_p2 = p2;	_p3 = p3;
}
///////////////////////////////////////////////////////////////////////////
Quad::Quad(Point3 p1, Point3 p2, Point3 p3, Point3 p4)
{
	_p1 = p1;	_p2 = p2;	_p3 = p3; _p4 = p4;
}
///////////////////////////////////////////////////////////////////////////
Solid::Solid()
{}
	
void Solid::add_triangle(const Triangle& t)
{
	_all_triangles.push_back(t);
}

void Solid::add_quad(const Quad& t)
{
	_all_triangles.push_back(Triangle(t._p1,t._p2, t._p3));
	_all_triangles.push_back(Triangle(t._p3, t._p4, t._p1));
}

vector<Triangle>& Solid::triangles()
{
	return _all_triangles;
}
///////////////////////////////////////////////////////////////////////////