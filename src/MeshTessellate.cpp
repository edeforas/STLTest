#include "MeshTessellate.h"

///////////////////////////////////////////////////////////////////////////
MeshTessellate::MeshTessellate()
{ }

MeshTessellate::~MeshTessellate()
{ }

void MeshTessellate::compute( const Mesh & meshIn, int iLevel, Mesh& meshOut)
{
	meshOut = meshIn;
	for (int iL = 0; iL < iLevel; iL++)
	{
		int iNbOldTriangles = meshOut.nb_triangles();
		for (int i = 0; i < iNbOldTriangles; i++)
		{
			if (meshOut.is_triangle_deleted(i))
				continue;

			// create new 3x vertex
			int iA, iB, iC;
			Point3 a,b,c;
			meshOut.get_triangle(i, iA, iB, iC); //always replace first old trig
			meshOut.get_vertex(iA, a);
			meshOut.get_vertex(iB, b);
			meshOut.get_vertex(iC, c);

			// create new vertices
			meshOut.add_vertex((a + b) * 0.5);
			meshOut.add_vertex((a + c) * 0.5);
			meshOut.add_vertex((b + c) * 0.5);

			//replace face
			meshOut.delete_triangle(i);
			meshOut.add_triangle(iA, meshOut.nb_vertices()-3, meshOut.nb_vertices() - 2);
			meshOut.add_triangle(iB, meshOut.nb_vertices() - 1, meshOut.nb_vertices() - 3);
			meshOut.add_triangle(iC, meshOut.nb_vertices() - 2, meshOut.nb_vertices() - 1);
			meshOut.add_triangle( meshOut.nb_vertices() - 2, meshOut.nb_vertices() - 3, meshOut.nb_vertices() - 1);		
		}
	}
}
///////////////////////////////////////////////////////////////////////////