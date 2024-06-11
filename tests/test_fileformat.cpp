#include "BodyFactory.h"
#include "BodyUnion.h"

#include "STLFile.h"
#include "OBJFile.h"

///////////////////////////////////////////////////////////////////////////
int main()
{
	// build object
	BodyFactory::Cylinder cylinder(100., 40.);
	BodyFactory::SphereUV sphere(70.);

	BodyUnion bu;
	bu.set(cylinder,sphere);

	//test save
	STLFile::save("capsule.stl", bu.to_mesh());
	OBJFile::save("capsule.obj", bu.to_mesh());

	//test load and save stl
	Mesh m1;
	STLFile::load("capsule.stl", m1);
	STLFile::save("capsule2.stl", m1);

	//test load and save obj
	Mesh m2;
	OBJFile::load("capsule.obj", m2);
	OBJFile::save("capsule2.obj", m2);

	return 0;
}
///////////////////////////////////////////////////////////////////////////