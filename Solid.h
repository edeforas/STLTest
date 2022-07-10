#ifndef _Solid_
#define _Solid_

#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////////////
class Point3
{
public:
    Point3(float x=0.f, float y=0.f, float z=0.f);

    float _x, _y, _z;
};

///////////////////////////////////////////////////////////////////////////
class Triangle
{
public:
	Triangle(Point3 p1, Point3 p2, Point3 p3);
	
    Point3 _p1, _p2, _p3;
};
///////////////////////////////////////////////////////////////////////////
class Quad
{
public:
    Quad(Point3 p1, Point3 p2, Point3 p3, Point3 p4);

    Point3 _p1, _p2, _p3, _p4;
};
///////////////////////////////////////////////////////////////////////////
class Solid
{
public:
	Solid();
        
    void add_triangle(const Triangle& t);
    void add_quad(const Quad& t);
	
    vector<Triangle>& triangles();

private:
    vector<Triangle> _all_triangles;
};

#endif