#include "Geometry.h"

#include <cmath>

inline double square(double a)
{ return a*a; }

///////////////////////////////////////////////////////////////////////////
Point3::Point3()
{
	_x = 0.; _y = 0.; _z = 0.;
}

Point3::Point3(double x, double y, double z)
{
	_x = x; _y = y; _z = z;
}

Point3& Point3::operator+=(const Point3& p)
{
	_x += p._x;
	_y += p._y;
	_z += p._z;

	return *this;
}

Point3& Point3::operator-=(const Point3& p)
{
	_x -= p._x;
	_y -= p._y;
	_z -= p._z;

	return *this;
}

Point3 Point3::operator+(const Point3& p) const
{
	Point3 res;

	res._x = _x + p._x;
	res._y = _y + p._y;
	res._z = _z + p._z;

	return res;
}

Point3 Point3::operator*(double d) const
{
	Point3 res;

	res._x = d*_x;
	res._y = d*_y;
	res._z = d*_z;

	return res;
}

Point3 Point3::operator/(double d) const
{
	Point3 res;

	res._x = _x/d;
	res._y = _y/d;
	res._z = _z/d;

	return res;
}

Point3 Point3::operator-(const Point3& p) const
{
	Point3 res;

	res._x = _x - p._x;
	res._y = _y - p._y;
	res._z = _z - p._z;
	
	return res;
}

double Point3::distance_square(const Point3& p) const
{
	return square(_x - p._x) + square(_y - p._y) + square(_z - p._z);
}

double Point3::dot_product(const Point3& p) const
{
	return _x * p._x +_y * p._y + _z * p._z;
}

Point3 Point3::cross_product(const Point3& p) const
{
	// from https://en.wikipedia.org/wiki/Cross_product
	return Point3( _y*p._z-_z*p._y , _z*p._x-_x*p._z , _x*p._y-_y*p._x );
}

double Point3::norm() const
{
	return sqrt(_x * _x + _y * _y + _z * _z);
}

Point3 Point3::normalized() const
{
	double d = 1./norm();
	return this->operator*(d);
}
///////////////////////////////////////////////////////////////////////////
Triangle3::Triangle3()
{ }

Triangle3::Triangle3(const Point3& p1, const Point3& p2, const Point3& p3):
_p1(p1),_p2(p2),_p3(p3)
{ }

Point3 Triangle3::p1() const
{
	return _p1;
}

Point3 Triangle3::p2() const
{
	return _p2;
}

Point3 Triangle3::p3() const
{
	return _p3;
}

void Triangle3::set_p1(const Point3& p)
{
	_p1=p;
}

void Triangle3::set_p2(const Point3& p)
{
	_p2=p;
}

void Triangle3::set_p3(const Point3& p)
{
	_p3=p;
}

bool Triangle3::cutted_by(const Triangle3& t) const
{
	Plane3 p; p.compute_using(t);

	double proj1 = p.relative_distance(p1());
	double proj2 = p.relative_distance(p2());
	double proj3 = p.relative_distance(p3());

	int nbPositive=0, nbNegative=0;

	if (proj1 > 0.) nbPositive++;
	if (proj1 < 0.) nbNegative++;

	if (proj2 > 0.) nbPositive++;
	if (proj2 < 0.) nbNegative++;

	if (proj3 > 0.) nbPositive++;
	if (proj3 < 0.) nbNegative++;

	return (nbPositive==2 && nbNegative==1 ) || (nbPositive == 1 && nbNegative == 2);
}

bool Triangle3::is_inside(const Point3& p) const
{
	// from https://gdbooks.gitbooks.io/3dcollisions/content/Chapter4/point_in_triangle.html

	Point3 a = _p1 - p;
	Point3 b = _p2 - p;
	Point3 c = _p3 - p;

	Point3 u = b.cross_product(c);

	Point3 v = c.cross_product(a);
	if (u.dot_product(v) < 0.)
		return false;

	Point3 w = a.cross_product(b);
	if (u.dot_product(w) < 0.)
		return false;

	return true;
}
///////////////////////////////////////////////////////////////////////////
Plane3::Plane3()
{
	_a = 0.; _b = 0.; _c = 0.; _d = 0.;
}

Plane3::Plane3(const Point3& p1, const Point3& p2, const Point3& p3)
{
	compute_using(p1,p2,p3);
}

void Plane3::compute_using(const Point3& p1, const Point3& p2, const Point3& p3)
{
	//compute normal using the cross product
	Point3 pn = (p1 - p2).cross_product(p1 - p3);

	_a = pn._x; _b = pn._y; _c = pn._z;

	//compute _d (the plane must pass thru p1)
	_d = -(_a * p1._x + _b * p1._y + _c * p1._z);
}

void Plane3::compute_using(const Triangle3& t)
{
	compute_using(t.p1(), t.p2(), t.p3());
}

double Plane3::relative_distance(const Point3& p) const
{
	return _a * p._x + _b * p._y + _c * p._z + _d; //not divided by sqrt(a*a+b*b+c*c)
}

double Plane3::absolute_distance(const Point3& p) const
{
	//for now: slow
	double denom = std::sqrt(_a * _a + _b * _b + _c * _c);
	return (_a * p._x + _b * p._y + _c * p._z + _d) / denom;
}

void Plane3::get(double& a, double& b, double& c, double& d)
{
	a = _a; b = _b; c = _c; d = _d;
}

bool Plane3::intersect_with_segment(const Point3& p1, const Point3& p2, Point3& pIntersection)
{
	double k = _a * p1._x + _b * p1._y + _c * p1._z + _d;
	double u = _a * (p2._x- p1._x) + _b * (p2._y- p1._y) + _c * (p2._z - p1._z);

	if (u == 0.)
		return false; // no intersection

	double t = -k / u;

	pIntersection._x = p1._x + t * (p2._x - p1._x);
	pIntersection._y = p1._y + t * (p2._y - p1._y);
	pIntersection._z = p1._z + t * (p2._z - p1._z);

	return true;
}

Point3 Plane3::normal() const
{
	return Point3(_a,_b,_c);
}
///////////////////////////////////////////////////////////////////////////
BoundingBox3::BoundingBox3()
{
	_bInitialized=false;
	_x1=0; _y1=0; _z1=0;
	_x2=0; _y2=0; _z2=0;
}

void BoundingBox3::add(const Point3& p1)
{
	double x = p1._x;
	double y = p1._y;
	double z = p1._z;

	if(_bInitialized==false)
	{
		_x1= x; _y1 = y; _z1 = z;
		_x2= x; _y2 = y; _z2 = z;
		_bInitialized=true;
		return;
	}

	if (x < _x1)
		_x1 = x;
	if (x > _x2)
		_x2 = x;

	if (y < _y1)
		_y1 = y;
	if (y > _y2)
		_y2 = y;

	if (z < _z1)
		_z1 = z;
	if (z > _z2)
		_z2 = z;
}

bool BoundingBox3::intersect_with(const BoundingBox3& b) const
{
	if (_x2 < b._x1)
		return false;

	if (_y2 < b._y1)
		return false;

	if (_z2 < b._z1)
		return false;

	if (b._x2 < _x1)
		return false;

	if (b._y2 < _y1)
		return false;

	if (b._z2 < _z1)
		return false;

	return true;
}
///////////////////////////////////////////////////////////////////////////

