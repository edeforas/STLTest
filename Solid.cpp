#include "Solid.h"

///////////////////////////////////////////////////////////////////////////
Triangle::Triangle(float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3)
{
	_x1 = x1;
	_y1 = y1;
	_z1 = z1;
		
	_x2 = x2;
	_y2 = y2;
	_z2 = z2;

	_x3 = x3;
	_y3 = y3;
	_z3 = z3;
}
///////////////////////////////////////////////////////////////////////////
Solid::Solid()
{}
	
void Solid::add_triangle(const Triangle& t)
{
	_all_triangles.push_back(t);
}

vector<Triangle>& Solid::triangles()
{
	return _all_triangles;
}
///////////////////////////////////////////////////////////////////////////