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
		// test triangles fliped and deleted
		BodyFactory::Sphere sphere(100., 5);
		Mesh& m = sphere.mesh();
		for (int i = 0; i < m.nb_triangles(); i++)
		{
			if (rand() / (float)RAND_MAX > 0.5)
				m.flip_triangle(i);

			if (rand() / (float)RAND_MAX > 0.5)
				m.delete_triangle(i); //does not delete, only unlink
		}
		STLFile::save("sphere_triangles_flipped_deleted.stl", m);
	}

	{
		// test triangles subdivision
		BodyFactory::Sphere sphere(100.);
		Mesh& m = sphere.mesh();

		int iNbTriangles = m.nb_triangles(); // only changing the old triangles, not the created 
		for (int i = 0; i < iNbTriangles; i++)
		{
			Point3 p1, p2, p3, vCenter;
			m.get_triangle(i, p1, p2, p3);

			int iNewVertex = m.add_vertex((p1 + p2 + p3) / 3.);
			m.split_triangle_with_vertex(i, iNewVertex);
		}

		STLFile::save("sphere_triangles_subdivflat.stl", m);
	}

	cout << "Test Finished.";
	return 0;
}
///////////////////////////////////////////////////////////////////////////