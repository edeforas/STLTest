#include "BodyFactory.h"
#include "OBJFile.h"
#include "Mesh.h"

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////
int main()
{
	Mesh m;

	for (int iLevel = 2; iLevel < 7; iLevel++)
	{
		cout << "Generating sphere with level of details=" << iLevel << endl;
		BodyFactory::SphereUV sphere(50); // for now sphereUV, will be replaced by sphere geodesic
		sphere.set_mesh_precision(2<<iLevel);
		sphere.transform().set_global_translation(Point3(120.*iLevel, 0., 0.));
		m.add_mesh(sphere.to_mesh());
	}

	cout << "Saving: spheres_level_of_details.obj" << endl;
	OBJFile::save("spheres_level_of_details.obj", m);

	cout << "Test Finished.";
	return 0;
}
///////////////////////////////////////////////////////////////////////////