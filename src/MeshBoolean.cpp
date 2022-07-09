#include "MeshBoolean.h"

#include <cassert>


///////////////////////////////////////////////////////////////////////////
// for now: just disable the triangles to be splitted
// WIP
// slow, in O(n**2)

MeshBoolean::MeshBoolean()
{ }

void MeshBoolean::split_meshes(const Mesh& A, const Mesh& B, Mesh& Aoutside, Mesh& Boutside, Mesh& AInB, Mesh& BInA)
{
	vector<bool> vbKeepTriangleA(A.nb_triangles(), true);
	vector<bool> vbKeepTriangleB(B.nb_triangles(), true);

	for (int i = 0; i < A.nb_triangles(); i++)
	{
		if (A.is_triangle_deleted(i))
			continue;

		Triangle3 tA;
		A.get_triangle(i, tA);
		BoundingBox3 bA;
		bA.add(tA.p1());
		bA.add(tA.p2());
		bA.add(tA.p3());

		for (int j = 0; j < B.nb_triangles(); j++)
		{
			if (B.is_triangle_deleted(j))
				continue;

			Triangle3 tB;
			B.get_triangle(j, tB);
			BoundingBox3 bB;

			// test with BoundingBox
			bB.add(tB.p1());
			bB.add(tB.p2());
			bB.add(tB.p3());

			if (bA.intersect_with(bB) == false)
				continue;

			// triangle may intersect using BoundingBox, test more
			bool bACutted = tA.cutted_by(tB);
			if (bACutted)
			{
				bool tBCutted = tB.cutted_by(tA);
				if (tBCutted)
				{
					// if both cut each others:they may intersect. Remove triangle u and t; for now
					vbKeepTriangleA[i] = false;
					vbKeepTriangleB[j] = false;
				}
			}
		}
	}

	Aoutside = A;
	for (int i = 0; i<vbKeepTriangleA.size() ; i++)
	{
		if (vbKeepTriangleA[i] == false)
		{
			Aoutside.delete_triangle(i);
		}
	}

	Boutside = B;
	for (int i = 0; i<vbKeepTriangleB.size() ; i++)
	{
		if (vbKeepTriangleB[i] == false)
		{
			Boutside.delete_triangle(i);
		}
	}
}
///////////////////////////////////////////////////////////////////////////