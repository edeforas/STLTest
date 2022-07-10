#include "Solid.h"

///////////////////////////////////////////////////////////////////////////
STL::STL(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
	_x1 = x1; _y1 = y1; _z1 = z1;
	_x2 = x2; _y2 = y2; _z2 = z2;
	_x3 = x3; _y3 = y3; _z3 = z3;
}
STL::STL(Point3 p1, Point3 p2, Point3 p3)
{
	_x1 = p1._x; _y1 = p1._y; _z1 = p1._z;
	_x2 = p2._x; _y2 = p2._y; _z2 = p2._z;
	_x3 = p3._x; _y3 = p3._y; _z3 = p3._z;
}
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

vector<STL> Triangle::stl() const
{
	vector<STL> vt;
	vt.push_back(STL(_p1, _p2, _p3));
	return vt;
}
///////////////////////////////////////////////////////////////////////////
Quad::Quad(Point3 p1, Point3 p2, Point3 p3, Point3 p4)
{
	_p1 = p1;	_p2 = p2;	_p3 = p3; _p4 = p4;
}
Quad::Quad(const Quad& t)
{
	_p1 = t._p1; _p2 = t._p2; _p3 = t._p3; _p4 = t._p4;
}

vector<STL> Quad::stl() const
{
	vector<STL> vt;
	vt.push_back(STL(_p1, _p2, _p3));
	vt.push_back(STL(_p3, _p4, _p1));

	return vt;
}
///////////////////////////////////////////////////////////////////////////
Solid::Solid()
{}

Solid::~Solid()
{
	for (int i = 0; i < _all_solids.size(); i++)
		delete _all_solids[i];
}

void Solid::add_solid(Solid* s)
{
	_all_solids.push_back(s);
}

vector<STL> Solid::stl() const
{
	vector<STL> vt;
	for (int i = 0; i < _all_solids.size(); i++)
	{
		auto t = _all_solids[i]->stl();
		vt.insert(vt.end(), t.begin(), t.end());
	}

	return vt;
}
///////////////////////////////////////////////////////////////////////////