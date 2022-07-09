#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#include "OBJFile.h"

namespace OBJFile
{   
    bool save(const string& filename, const Mesh& mesh)
    {
        ofstream f(filename);
        if (!f)
            return false;
		
		// write vertices
		Point3 vertex;
		for (int i = 0; i < mesh.nb_vertices(); i++)
		{
			mesh.get_vertex(i, vertex);
			f << "v " << vertex._x << " " << vertex._y << " " << vertex._z << endl;
		}
		f << endl;

		// write triangle vertices
		int iVertex1 = 0, iVertex2 = 0, iVertex3 = 0; 
		for (int i = 0; i < mesh.nb_triangles(); i++)
		{
			if (mesh.is_triangle_deleted(i))
				continue;

			mesh.get_triangle(i, iVertex1, iVertex2, iVertex3);
			f << "f " << iVertex1 + 1 << " " << iVertex2 + 1 << " " << iVertex3 + 1 << endl;
		}

        return true;
    }
    ///////////////////////////////////////////////////////////////////////////
	// todo add vertex aliasing on load
	bool load(const string& filename, Mesh& mesh)
    {
        ifstream f(filename);
        if (!f)
            return false;
		
		mesh.clear();
		while(!f.eof())
		{
			string sType,sLine;
			getline(f,sLine);

			if (sLine.size() == 0)
				continue;

			stringstream ss(sLine);
			ss >> sType;
			
			// read vertice
			if (sType=="v")
			{
				double x,y,z;
				ss >> x >> y >> z;
				mesh.add_vertex(Point3(x,y,z));
			}
			
			// read facet
			if (sType=="f")
			{
				int i1, i2, i3;
				ss >> i1 >> i2 >> i3;

				mesh.add_triangle(i1-1,i2-1,i3-1);
			}
		}

        return true;
    }
    ///////////////////////////////////////////////////////////////////////////
}