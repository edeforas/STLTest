#ifndef _Geometry_
#define _Geometry_

///////////////////////////////////////////////////////////////////////////
class Point3
{
public:
	Point3();
    Point3(double x, double y, double z);

    Point3& operator+=(const Point3& p);
	Point3& operator-=(const Point3& p);
	Point3 operator+(const Point3& p) const;
	Point3 operator*(double d) const;
	Point3 operator/(double d) const;
    Point3 operator-(const Point3& p) const;

    double distance_square(const Point3& p) const;
    double dot_product(const Point3& p) const;
    Point3 cross_product(const Point3& p) const;
	double norm() const;
	Point3 normalized() const;

    double _x, _y, _z;
};
///////////////////////////////////////////////////////////////////////////
class Triangle3
{
public:
    Triangle3();
    Triangle3(const Point3& p1, const Point3& p2, const Point3& p3);
	
	Point3 p1() const;
	Point3 p2() const;
	Point3 p3() const;

	void set_p1(const Point3& p);
	void set_p2(const Point3& p);
	void set_p3(const Point3& p);

	bool cutted_by(const Triangle3& t) const;
	bool is_inside(const Point3& p) const;

private:
	Point3 _p1, _p2, _p3;
};
///////////////////////////////////////////////////////////////////////////
class Plane3
{
public:
	
	Plane3();
	Plane3(const Point3& p1, const Point3& p2, const Point3& p3);

	void compute_using(const Point3& p1, const Point3& p2, const Point3& p3);
	void compute_using(const Triangle3& t);
	
	double relative_distance(const Point3& p) const;
	double absolute_distance(const Point3& p) const;

	void get(double& a, double& b, double& c, double& d);
	
	bool intersect_with_segment(const Point3& p1, const Point3& p2, Point3& pIntersection);

	Point3 normal() const;

private:
		double _a, _b, _c, _d;
};
///////////////////////////////////////////////////////////////////////////

class BoundingBox3 // AABB: Axis Aligned Bounding Box
{
public:
	BoundingBox3();

	void add(const Point3& p1);

	bool intersect_with(const BoundingBox3& b) const;

private:
	double _x1, _y1, _z1;
	double _x2, _y2, _z2;
	bool _bInitialized;
};
///////////////////////////////////////////////////////////////////////////
#endif