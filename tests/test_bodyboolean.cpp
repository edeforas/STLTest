#include "BodyFactory.h"
#include "BodyUnion.h"
#include "BodyIntersection.h"

#include "STLFile.h"

///////////////////////////////////////////////////////////////////////////
int main()
{
	BodyFactory::Sphere sphere(100.);
	BodyFactory::Sphere sphere2(150.);

	sphere2.transform().set_global_translation(60., 10., 20.);

	BodyUnion bu;
	bu.set(sphere, sphere2);
	STLFile::save("two_spheres_union.stl", bu.mesh());

	BodyIntersection bi;
	bi.set(sphere, sphere2);
	STLFile::save("two_spheres_intersection.stl", bi.mesh());

	return 0;
}
///////////////////////////////////////////////////////////////////////////