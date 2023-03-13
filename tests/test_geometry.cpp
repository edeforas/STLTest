#include "Geometry.h"

#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////
void test_plane_segment_intersection()
{
	Point3 p1(1., 0., 0.);
	Point3 p2(0., 1., 0.);
	Point3 p3(0., 0., 1.);
	Plane3 plane1(p1, p2, p3);

	Point3 p4(0., 0., 0.); // cube diagonal
	Point3 p5(1., 1., 1.);
	Point3 intersection;

	bool bSucceded=plane1.intersect_with(Segment3(p4,p5), intersection);
	cout << "Intersect (must be 1 at (1/3,1/3,1/3))?:"  << bSucceded << " intersection: x=" << intersection._x << " y=" << intersection._y << " z=" << intersection._z << endl;
}

///////////////////////////////////////////////////////////////////////////
void test_plane_point_projection()
{
	Point3 p1(1., 0., 0.);
	Point3 p2(0., 1., 0.);
	Point3 p3(0., 0., 1.);
	Plane3 plane1(p1, p2, p3);

	Point3 p5(1., 1., 1.);
	Point3 projected;

	plane1.project_point(p5,projected);

	cout << "Projected must be at (1/3,1/3,1/3)?: x=" << projected._x << " y=" << projected._y << " z=" << projected._z << endl;
}
///////////////////////////////////////////////////////////////////////////
void test_point_in_triangle()
{
	Point3 p1(1., 0., 0.);
	Point3 p2(0., 1., 0.);
	Point3 p3(0., 0., 1.);
	Triangle3 t3(p1, p2, p3);

	Point3 pA(0.33, 0.33, 0.33);
	cout << "Point A inside (must be 1)?: " << t3.contains(pA) << endl;

	Point3 pB(1., 1., -1.); //out of plane
	cout << "Point B inside (must be 0)?: " << t3.contains(pB) << endl;
}
///////////////////////////////////////////////////////////////////////////
void test_triangle_triangle_intersection()
{
	// triangles nearly touching by the (0,0,0) point
	{
		Point3 pA1(0., 1., 0.);
		Point3 pA2(0., -1., 0.);
		Point3 pA3(-1., 0., 0.);
		Triangle3 tA(pA1, pA2, pA3);

		Point3 pB1(0.1, 0., 1.);
		Point3 pB2(0.1, 0., -1.);
		Point3 pB3(1., 0., 0.);
		Triangle3 tB(pB1, pB2, pB3);

		cout << "Triangle1 and triangle2 intersect (must be 0)?: " << tA.intersect_with(tB) << endl;
	}
	{
		Point3 pA1(0., 1., 0.);
		Point3 pA2(0., -1., 0.);
		Point3 pA3(-1., 0., 0.);
		Triangle3 tA(pA1, pA2, pA3);

		Point3 pB1(-0.1, 0., 1.);
		Point3 pB2(-0.1, 0., -1.);
		Point3 pB3(1., 0., 0.);
		Triangle3 tB(pB1, pB2, pB3);

		cout << "Triangle1 and triangle2 intersect (must be 1)?: " << tA.intersect_with(tB) << endl;
	}
}
///////////////////////////////////////////////////////////////////////////
int main()
{
	test_plane_point_projection();
	test_plane_segment_intersection();
	test_point_in_triangle();
	test_triangle_triangle_intersection();

	return 0;
}