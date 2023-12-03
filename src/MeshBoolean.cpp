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
	Aoutside = A;
	Boutside = B;

	//slow for now
	for (int i = 0; i < A.nb_triangles(); i++)
	{
		if (A.is_triangle_unlinked(i))
			continue;

		Triangle3 tA;
		A.get_triangle(i, tA);
		BoundingBox3 bA(tA);
		Plane3 pA(tA);

		for (int j = 0; j < B.nb_triangles(); j++)
		{
			if (B.is_triangle_unlinked(j))
				continue;

			Triangle3 tB;
			B.get_triangle(j, tB);
			BoundingBox3 bB(tB);

			Point3 pIntersection;

			if (bA.intersect_with(bB) == false)
				continue;

			Plane3 pB(tB); // slow: we recompute the plan each time
			if (tA.cut_by(pB) == false)
				continue;

			if (tB.cut_by(pA) == false)
				continue;

			//compute if any segment cut any triangles, save
			vector<Point3> pointBCutA;
			if (tA.intersect_with(Segment3(tB.p1(), tB.p2()), pIntersection))
				pointBCutA.push_back(pIntersection);

			if (tA.intersect_with(Segment3(tB.p1(), tB.p3()), pIntersection))
				pointBCutA.push_back(pIntersection);

			if (tA.intersect_with(Segment3(tB.p2(), tB.p3()), pIntersection))
				pointBCutA.push_back(pIntersection);

			if (pointBCutA.size() > 0)
			{
				assert(pointBCutA.size() <= 2); // two triangle cannot intersect more than 2 times

				const auto& p = pointBCutA[0];
				int iVertice = Aoutside.add_vertex(p);
				Aoutside.split_triangle_with_vertex(i, iVertice); // new triangles are created at the end

				if (pointBCutA.size() > 1)
				{
					const auto& p = pointBCutA[1];
					int iVertice = Aoutside.add_vertex(p);

					Aoutside.get_triangle(Aoutside.nb_triangles() - 3, tA);
					if (tA.contains(p)) //todo add bounding box ... tests
					{
						Aoutside.split_triangle_with_vertex(Aoutside.nb_triangles() - 3, iVertice); // new triangles are created at the end
					}
					else //only 2 point max are possible
					{
						Aoutside.get_triangle(Aoutside.nb_triangles() - 2, tA);
						if (tA.contains(p)) //todo add bounding box ... tests
							Aoutside.split_triangle_with_vertex(Aoutside.nb_triangles() - 2, iVertice); // new triangles are created at the end
						else
							Aoutside.split_triangle_with_vertex(Aoutside.nb_triangles() - 1, iVertice); // new triangles are created at the end
					}
				}
			}

			vector<Point3> pointACutB;
			if (tB.intersect_with(Segment3(tA.p1(), tA.p2()), pIntersection))
				pointACutB.push_back(pIntersection);

			if (tB.intersect_with(Segment3(tA.p1(), tA.p3()), pIntersection))
				pointACutB.push_back(pIntersection);

			if (tB.intersect_with(Segment3(tA.p2(), tA.p3()), pIntersection))
				pointACutB.push_back(pIntersection);

			if (pointACutB.size() > 0)
			{
				assert(pointACutB.size() <= 2); // two triangle cannot intersect more than 2 times

				const auto& p = pointACutB[0];
				int iVertice = Boutside.add_vertex(p);
				Boutside.split_triangle_with_vertex(j, iVertice); // new triangles are created at the end

				if (pointACutB.size() > 1)
				{
					const auto& p = pointACutB[1];
					int iVertice = Boutside.add_vertex(p);

					Boutside.get_triangle(Boutside.nb_triangles() - 3, tB);
					if (tB.contains(p)) //todo add bounding box tests
					{
						Boutside.split_triangle_with_vertex(Boutside.nb_triangles() - 3, iVertice); // new triangles are created at the end
					}
					else //only 2 point max are possible
					{
						Boutside.get_triangle(Boutside.nb_triangles() - 2, tB);
						if (tB.contains(p)) //todo add bounding box ... tests
							Boutside.split_triangle_with_vertex(Boutside.nb_triangles() - 2, iVertice); // new triangles are created at the end
						else
							Boutside.split_triangle_with_vertex(Boutside.nb_triangles() - 1, iVertice); // new triangles are created at the end
					}
				}
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////