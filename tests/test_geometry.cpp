#include "Geometry.h"

#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////
void test_intersection()
{
	Point3 p1(1., 0., 0.);
	Point3 p2(0., 1., 0.);
	Point3 p3(0., 0., 1.);
	Plane3 plane1(p1, p2, p3);

	Point3 segment1(0., 0., 0.);
	Point3 segment2(1., 1., 1.);
	Point3 intersection;

	bool bSucceded=plane1.intersect_with_segment(segment1, segment2, intersection);

	cout << "Intersect?"  << bSucceded << " intersection: x=" << intersection._x << " y=" << intersection._y << " z=" << intersection._z << endl;
}
///////////////////////////////////////////////////////////////////////////
void test_point_in_triangle()
{
	Point3 p1(1., 0., 0.);
	Point3 p2(0., 1., 0.);
	Point3 p3(0., 0., 1.);
	Triangle3 t3(p1, p2, p3);

	Point3 pA(0.33, 0.33, 0.33);
	cout << "Is pA inside: " << t3.is_inside(pA) << endl;

	Point3 pB(2, 0, 0); //out of plane anyway
	cout << "Is pB inside: " << t3.is_inside(pB) << endl;

	// todo add test with barycentric point creation
}
///////////////////////////////////////////////////////////////////////////
int main()
{
	test_intersection();
	test_point_in_triangle();
	return 0;
}