#include "BodyFactory.h"
#include "BodyUnion.h"
#include "BodyDifference.h"
#include "BodyIntersection.h"

#include "OBJFile.h"

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////
int main()
{
	cout << "Test Boolean Start..." << endl;

	BodyFactory::SphereUV sphere(50.);
	BodyFactory::SphereUV sphere2(70.);

	sphere2.transform().set_global_translation(10., 25., 40.);
	sphere.set_color(RGB(255, 0, 0));
	sphere2.set_color(RGB(0, 255, 0));

	cout << "Computing Union..." << endl;
	BodyUnion bu;
	bu.set(sphere, sphere2);
	if (!OBJFile::save("two_spheres_union.obj", bu.mesh()))
	{
		cout << "Unable to set two_spheres_union.obj, check path and rights." << endl;
		return -1;
	}

	cout << "Computing Intersection..." << endl;
	BodyIntersection bi;
	bi.set(sphere, sphere2);
	if (!OBJFile::save("two_spheres_intersection.obj", bi.mesh()))
	{
		cout << "Unable to save two_spheres_intersection.obj, check path and rights." << endl;
		return -1;
	}

	cout << "Computing Difference..." << endl;
	BodyDifference bd;
	bd.set(sphere, sphere2);
	if (!OBJFile::save("two_spheres_difference.obj", bd.mesh()))
	{
		cout << "Unable to save two_spheres_difference.obj, check path and rights." << endl;
		return -1;
	}

	cout << "Test Boolean Finished.";
	return 0;
}
///////////////////////////////////////////////////////////////////////////