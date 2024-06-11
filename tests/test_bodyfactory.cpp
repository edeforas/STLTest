#include "BodyFactory.h"
#include "Mesh.h"
#include "STLFile.h"

///////////////////////////////////////////////////////////////////////////
int main()
{
	// build and save objects
	Mesh m,mTotal;
	
	BodyFactory::Tetrahedron tetrahedron(25.);
	tetrahedron.to_mesh(m);
	mTotal.add_mesh(m);

	BodyFactory::Box box(40., 50., 60.);
	box.transform().set_global_translation(Point3(100., 0., 0.));
	box.to_mesh(m);
	mTotal.add_mesh(m);

	BodyFactory::Cylinder cylinder(60., 50.);
	cylinder.transform().set_global_translation(Point3(200., 0., 0.));
	cylinder.to_mesh(m);
	mTotal.add_mesh(m);

	BodyFactory::Octahedron octahedron(40.);
	octahedron.transform().set_global_translation(Point3(0., 100., 0.));
	octahedron.to_mesh(m);
	mTotal.add_mesh(m);

	BodyFactory::Dodecahedron dodecahedron(20.);
	dodecahedron.transform().set_global_translation(Point3(100., 100., 0.));
	dodecahedron.to_mesh(m);
	mTotal.add_mesh(m);

	BodyFactory::Icosahedron icosahedron(30.);
	icosahedron.transform().set_global_translation(Point3(200, 100, 0.));
	icosahedron.to_mesh(m);
	mTotal.add_mesh(m);

	BodyFactory::SphereGeodesic sphere(30.);
	sphere.transform().set_global_translation(Point3(100., 200., 0));
	sphere.to_mesh(m);
	mTotal.add_mesh(m);

	BodyFactory::SphereUV sphereUV(30.);
	//sphereUV.set_precision(16);
	sphereUV.transform().set_global_translation(Point3(0., 200., 0));
	sphereUV.to_mesh(m);
	mTotal.add_mesh(m);

	BodyFactory::Torus torus(25.,10.);
	torus.transform().set_global_translation(Point3(200., 200., 0.));
	torus.to_mesh(m);
	mTotal.add_mesh(m);

	STLFile::save("body_factory.stl", mTotal);
	return 0;
}
///////////////////////////////////////////////////////////////////////////