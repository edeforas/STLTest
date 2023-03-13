#include "BodyFactory.h"
#include "BodyUnion.h"
#include "BodyDifference.h"
#include "BodyIntersection.h"

#include "OBJFile.h"

///////////////////////////////////////////////////////////////////////////
int main()
{
	BodyFactory::SphereUV sphere(50.);
	BodyFactory::SphereUV sphere2(70.);

	sphere2.transform().set_global_translation(10., 25., 40.);

	sphere.set_color(RGB(255, 0, 0));
	sphere2.set_color(RGB(0, 255, 0));

	BodyUnion bu;
	bu.set(sphere, sphere2);
	OBJFile::save("two_spheres_union.obj", bu.mesh());

	BodyIntersection bi;
	bi.set(sphere, sphere2);
	OBJFile::save("two_spheres_intersection.obj", bi.mesh());

	BodyDifference bd;
	bd.set(sphere, sphere2);
	OBJFile::save("two_spheres_difference.obj", bd.mesh());

	return 0;
}
///////////////////////////////////////////////////////////////////////////