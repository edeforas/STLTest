#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "STLFile.h"

namespace STLFile
{   
    bool save(const string& filename, const Mesh& mesh)
    {
        ofstream f(filename, ios::binary);
        if (!f)
            return false;

        int32_t zero = 0;
        float fzero=0.f;

        // write header
        for (int i = 0; i < 20; i++)
            f.write((char*)(&zero), 4);

        auto iNbTriangles = mesh.nb_triangles();

        // compute the number of valid triangles
        int iNbTrianglesValid = 0;
        for (int i = 0; i < mesh.nb_triangles();i++)
            if (!mesh.is_triangle_deleted(i))
                iNbTrianglesValid++;

        Triangle3 t;
        f.write((char*)(&iNbTrianglesValid), 4);

        for (int i = 0; i < iNbTriangles; i++)
        {
            if (mesh.is_triangle_deleted(i))
                continue;

            mesh.get_triangle(i, t);

            // write normals
            f.write((char*)(&fzero), 4);
            f.write((char*)(&fzero), 4);
            f.write((char*)(&fzero), 4);

            float p;
            p = (float)t.p1()._x; f.write((char*)(&p), 4);
            p = (float)t.p1()._y; f.write((char*)(&p), 4);
            p = (float)t.p1()._z; f.write((char*)(&p), 4);

            p = (float)t.p2()._x; f.write((char*)(&p), 4);
            p = (float)t.p2()._y; f.write((char*)(&p), 4);
            p = (float)t.p2()._z; f.write((char*)(&p), 4);

            p = (float)t.p3()._x; f.write((char*)(&p), 4);
            p = (float)t.p3()._y; f.write((char*)(&p), 4);
            p = (float)t.p3()._z; f.write((char*)(&p), 4);

            f.write((char*)(&zero), 2);
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////////
	bool load(const string& filename, Mesh& mesh)
    {
        mesh.clear();
        ifstream f(filename, ios::binary);
        if (!f)
            return false;

        //ignore header
        int32_t tmp = 0;
        for (int i = 0; i < 20; i++)
            f.read((char*)(&tmp), 4);

        int32_t nbFacet=0;
        f.read((char*)(&nbFacet), 4);

        // read facets
        float p1x = 0.f, p1y = 0.f, p1z = 0.f;
        float p2x = 0.f, p2y = 0.f, p2z = 0.f;
        float p3x = 0.f,p3y = 0.f,p3z = 0.f;
        float ftmp=0.f;
        for (int i = 0; i < nbFacet; i++)
        {
            //ignore normal
            f.read((char*)(&ftmp), 4);
            f.read((char*)(&ftmp), 4);
            f.read((char*)(&ftmp), 4);
            
            //read points
            f.read((char*)(&p1x), 4);
            f.read((char*)(&p1y), 4);
            f.read((char*)(&p1z), 4);
            f.read((char*)(&p2x), 4);
            f.read((char*)(&p2y), 4);
            f.read((char*)(&p2z), 4);
            f.read((char*)(&p3x), 4);
            f.read((char*)(&p3y), 4);
            f.read((char*)(&p3z), 4);

            //ignore color
            f.read((char*)(&tmp), 2);

			mesh.add_vertex(p1x, p1y, p1z);
			mesh.add_vertex(p2x, p2y, p2z);
			mesh.add_vertex(p3x, p3y, p3z);
            mesh.add_triangle(mesh.nb_vertices()-3, mesh.nb_vertices() - 2, mesh.nb_vertices() - 1);
        }

        return true;
    }
    ///////////////////////////////////////////////////////////////////////////
}