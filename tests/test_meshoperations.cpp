#include "BodyFactory.h"
#include "STLFile.h"

#include "Mesh.h"

#include <iostream>
#include <cstdlib>
using namespace std;

///////////////////////////////////////////////////////////////////////////
int main()
{
	cout << "Test Start." << endl;

	{
		// test triangles deleted
		BodyFactory::SphereUV sphere(100.);
		Mesh& m = sphere.mesh();
		for (int i = 0; i < m.nb_triangles(); i++)
		{
			if (rand() / (float)RAND_MAX > 0.5)
				m.unlink_triangle(i);
		}

		STLFile::save("sphere_triangles_deleted.stl", m);
	}

	{
		// test triangles subdivision
		BodyFactory::SphereGeodesic sphere(100.);
		Mesh& m = sphere.mesh();
		int iNbTriangles = m.nb_triangles(); // only changing the old triangles, not the created 
		for (int i = 0; i < iNbTriangles; i++)
		{
			Point3 p1, p2, p3, vCenter;
			m.get_triangle(i, p1, p2, p3);

			int iNewVertex = m.add_vertex((p1 + p2 + p3) / 3.);
			m.split_triangle_with_vertex(i, iNewVertex);
		}

		STLFile::save("sphere_triangles_subdiv.stl", m);
	}

	cout << "Test Finished.";
	return 0;
}
///////////////////////////////////////////////////////////////////////////