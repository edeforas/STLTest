#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#include "OBJFile.h"

namespace OBJFile
{   
    bool save(const string& filename, const Mesh& to_mesh)
    {
		double colorR=0., colorG=0., colorB=0.;
		bool bHasColor = to_mesh.get_color() != -1;
		if (bHasColor)
		{
			colorR = (to_mesh.get_color() >> 16) / 255.;
			colorG = ((to_mesh.get_color()& 0xFF00) >> 8) / 255.;
			colorB = (to_mesh.get_color() & 0xFF) / 255.;
		}

        ofstream f(filename);
        if (!f)
            return false;
		
		// write vertices
		Point3 vertex;
		for (int i = 0; i < to_mesh.nb_vertices(); i++)
		{
			to_mesh.get_vertex(i, vertex);
			if(bHasColor)
				// save color as in: http://paulbourke.net/dataformats/obj/colour.html
				f << "v " << vertex._x << " " << vertex._y << " " << vertex._z << " " << colorR << " " << colorG << " " << colorB << endl;
			else
				f << "v " << vertex._x << " " << vertex._y << " " << vertex._z << endl;
		}
		f << endl;

		// write triangle vertices
		int iVertex1 = 0, iVertex2 = 0, iVertex3 = 0; 

		for (int i = 0; i < to_mesh.nb_triangles(); i++)
		{
			if (to_mesh.is_triangle_unlinked(i))
				continue;

			to_mesh.get_triangle_vertices(i, iVertex1, iVertex2, iVertex3);
			f << "f " << iVertex1 + 1 << " " << iVertex2 + 1 << " " << iVertex3 + 1 << endl;
		}

        return true;
    }
    ///////////////////////////////////////////////////////////////////////////
	// todo add vertex aliasing on load
	bool load(const string& filename, Mesh& to_mesh)
    {
        ifstream f(filename);
        if (!f)
            return false;
		
		to_mesh.clear();
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
				to_mesh.add_vertex(Point3(x,y,z));
			}
			
			// read facet
			if (sType=="f")
			{
				int i1, i2, i3;
				ss >> i1 >> i2 >> i3;

				to_mesh.add_triangle(i1-1,i2-1,i3-1);
			}
		}

        return true;
    }
    ///////////////////////////////////////////////////////////////////////////
}