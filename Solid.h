#ifndef _Solid_
#define _Solid_

#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////////////
class Triangle
{
public:
	Triangle(float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3);
	
    float _x1, _y1, _z1, _x2, _y2, _z2, _x3, _y3, _z3;
};
///////////////////////////////////////////////////////////////////////////
class Solid
{
public:
	Solid();
        
    void add_triangle(const Triangle& t);
	
    vector<Triangle>& triangles();

private:
    vector<Triangle> _all_triangles;
};

#endif