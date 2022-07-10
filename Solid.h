#ifndef _Solid_
#define _Solid_

#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////////////
class Point3
{
public:
    Point3(float x = 0.f, float y = 0.f, float z = 0.f);

    float _x, _y, _z;
};
///////////////////////////////////////////////////////////////////////////
class STL
{
public:
    STL(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
    STL(Point3 p1, Point3 p2, Point3 p3);

    float _x1, _y1, _z1, _x2, _y2, _z2, _x3, _y3, _z3;
};

///////////////////////////////////////////////////////////////////////////
class Solid
{
public:
    Solid();
    virtual ~Solid();

    void add_solid(Solid* s);
    virtual vector<STL> stl() const;

private:
    vector<Solid*> _all_solids;
};

///////////////////////////////////////////////////////////////////////////
class Triangle: public Solid
{
public:
	Triangle(Point3 p1, Point3 p2, Point3 p3);

    virtual vector<STL> stl() const override ;
	
    Point3 _p1, _p2, _p3;
};
///////////////////////////////////////////////////////////////////////////
class Quad : public Solid
{
public:
    Quad(Point3 p1, Point3 p2, Point3 p3, Point3 p4);
    Quad::Quad(const Quad& t);

    virtual vector<STL> stl() const override;

    Point3 _p1, _p2, _p3, _p4;
};
///////////////////////////////////////////////////////////////////////////

#endif