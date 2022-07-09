#include "BodyFactory.h"

#include "MeshTessellate.h"

#include <cmath> // sin, cos for Cylinder and Sphere
using namespace std;

namespace BodyFactory
{
	///////////////////////////////////////////////////////////////////////////
	Tetrahedron::Tetrahedron(double dSize)
	{
		_size = dSize;
	}
	void Tetrahedron::compute_faces()
	{
		if (!_mesh.empty())
			return;

		_mesh.add_vertex(_size, _size, _size);
		_mesh.add_vertex(-_size, -_size, _size);
		_mesh.add_vertex(_size, -_size, -_size);
		_mesh.add_vertex(-_size, _size, -_size);

		_mesh.add_triangle(0, 1, 2);
		_mesh.add_triangle(1, 3, 2);
		_mesh.add_triangle(0, 3, 1);
		_mesh.add_triangle(0, 2, 3);

		_transform.apply(_mesh);
	}
	///////////////////////////////////////////////////////////////////////////
	Box::Box(double xSize, double ySize, double zSize)
	{
		_xSize = xSize; _ySize = ySize; _zSize = zSize;
	}
	void Box::compute_faces()
	{
		if (!_mesh.empty())
			return;

		double x = _xSize * 0.5;
		double y = _ySize * 0.5;
		double z = _zSize * 0.5;

		_mesh.add_vertex(x, y, z);
		_mesh.add_vertex(-x, y, z);
		_mesh.add_vertex(-x, -y, z);
		_mesh.add_vertex(x, -y, z);
		_mesh.add_vertex(x, y, -z);
		_mesh.add_vertex(-x, y, -z);
		_mesh.add_vertex(-x, -x, -z);
		_mesh.add_vertex(x, -x, -z);

		_mesh.add_quad(0, 1, 2, 3);
		_mesh.add_quad(7, 6, 5, 4);
		_mesh.add_quad(4, 5, 1, 0);
		_mesh.add_quad(3, 2, 6, 7);
		_mesh.add_quad(5, 6, 2, 1);
		_mesh.add_quad(0, 3, 7, 4);

		_transform.apply(_mesh);
	}
	///////////////////////////////////////////////////////////////////////////
	Octahedron::Octahedron(double dSize)
	{
		_size = dSize;
	}
	void Octahedron::compute_faces()
	{
		if (!_mesh.empty())
			return;

		_mesh.add_vertex(_size, 0, 0);
		_mesh.add_vertex(0., _size, 0);
		_mesh.add_vertex(0., 0., _size);
		_mesh.add_vertex(-_size, 0, 0);
		_mesh.add_vertex(0, -_size, 0.);
		_mesh.add_vertex(0., 0, -_size);

		_mesh.add_triangle(0, 1, 2);
		_mesh.add_triangle(1, 0, 5);
		_mesh.add_triangle(2, 1, 3);
		_mesh.add_triangle(0, 2, 4);
		_mesh.add_triangle(4, 3, 5);
		_mesh.add_triangle(3, 4, 2);
		_mesh.add_triangle(5, 3, 1);
		_mesh.add_triangle(4, 5, 0);

		_transform.apply(_mesh);
	}
	///////////////////////////////////////////////////////////////////////////
	Dodecahedron::Dodecahedron(double dSize)
	{
		_size = dSize;
	}
	void Dodecahedron::compute_faces()
	{
		if (!_mesh.empty())
			return;

		// coordinate from: https://en.wikipedia.org/wiki/Regular_dodecahedron

		double u = _size;
		double t1 = (std::sqrt(5.) + 1.) / 2.;
		double t2 = 1./t1;
		t1*=_size;
		t2*=_size;

		_mesh.add_vertex(u, u, u);
		_mesh.add_vertex(u, u, -u);
		_mesh.add_vertex(u, -u, u);
		_mesh.add_vertex(u, -u, -u);
		_mesh.add_vertex(-u, u, u);
		_mesh.add_vertex(-u, u, -u);
		_mesh.add_vertex(-u, -u, u);
		_mesh.add_vertex(-u, -u, -u);

		_mesh.add_vertex(0, t1, t2);
		_mesh.add_vertex(0, t1, -t2);
		_mesh.add_vertex(0, -t1, t2);
		_mesh.add_vertex(0, -t1, -t2);

		_mesh.add_vertex(t2, 0, t1);
		_mesh.add_vertex(t2, 0, -t1);
		_mesh.add_vertex(-t2, 0, t1);
		_mesh.add_vertex(-t2, 0, -t1);

		_mesh.add_vertex(t1, t2, 0); 
		_mesh.add_vertex(t1, -t2, 0);
		_mesh.add_vertex(-t1, t2, 0);
		_mesh.add_vertex(-t1, -t2, 0);

		_mesh.add_pentagon(0, 12, 2, 17, 16);
		_mesh.add_pentagon(19, 18, 5, 15, 7);

		_mesh.add_pentagon(12, 0, 8, 4, 14);
		_mesh.add_pentagon(13, 3, 11, 7, 15);

		_mesh.add_pentagon(2, 12, 14, 6, 10);
		_mesh.add_pentagon(9, 1, 13, 15, 5);

		_mesh.add_pentagon(18, 19, 6, 14, 4);
		_mesh.add_pentagon(3, 13, 1, 16, 17);
	
		_mesh.add_pentagon(1, 9, 8, 0, 16);
		_mesh.add_pentagon(19, 7, 11, 10, 6);
		
		_mesh.add_pentagon(18, 4, 8, 9, 5);
		_mesh.add_pentagon(2, 10, 11, 3, 17);

		_transform.apply(_mesh);
	}
	///////////////////////////////////////////////////////////////////////////
	Icosahedron::Icosahedron(double dSize)
	{
		_size = dSize;
	}
	void Icosahedron::compute_faces()
	{
		if (!_mesh.empty())
			return;

		// from "Beyond the Third Dimension" by Banchoff, p.168.
		double u = _size;
		double t = (std::sqrt(5.) - 1.) / 2.*_size;

		_mesh.add_vertex(u, 0., t); //0
		_mesh.add_vertex(u, 0., -t);
		_mesh.add_vertex(-u, 0., t);
		_mesh.add_vertex(-u, 0., -t);

		_mesh.add_vertex(0., t, u); //4
		_mesh.add_vertex(0., -t, u);
		_mesh.add_vertex(0., t, -u);
		_mesh.add_vertex(0., -t, -u);

		_mesh.add_vertex(t, u, 0.); //8
		_mesh.add_vertex(-t, u, 0.);
		_mesh.add_vertex(t, -u, 0.);
		_mesh.add_vertex(-t, -u, 0.);

		_mesh.add_triangle(0, 1, 8);
		_mesh.add_triangle(0, 10, 1);
		_mesh.add_triangle(2, 3, 11);
		_mesh.add_triangle(2, 9, 3);

		_mesh.add_triangle(4, 5, 0);
		_mesh.add_triangle(4, 2, 5);
		_mesh.add_triangle(6, 7, 3);
		_mesh.add_triangle(6, 1, 7);

		_mesh.add_triangle(8, 9, 4);
		_mesh.add_triangle(8, 6, 9);
		_mesh.add_triangle(10, 11, 7);
		_mesh.add_triangle(10, 5, 11);

		_mesh.add_triangle(0, 8, 4);
		_mesh.add_triangle(3, 7, 11);

		_mesh.add_triangle(10, 0, 5);
		_mesh.add_triangle(9, 6, 3);

		_mesh.add_triangle(1, 6, 8);
		_mesh.add_triangle(2, 11, 5);

		_mesh.add_triangle(2, 4, 9);
		_mesh.add_triangle(1, 10, 7);

		_transform.apply(_mesh);
	}
	///////////////////////////////////////////////////////////////////////////
	Cylinder::Cylinder(double height, double diameter)
	{
		_height = height; _diameter = diameter;
	}
	void Cylinder::compute_faces()
	{
		if (!_mesh.empty())
			return;

		double PI = 3.14159265358979323846264338; // TODO
		double z = _height / 2.;

		int iNbSegmentLongitude = _iNbSegments / 2;
		// create vertices
		for (int i = 0; i < iNbSegmentLongitude; i++)
		{
			double x = std::cos((double)i / iNbSegmentLongitude * 2. * PI) * _diameter / 2.;
			double y = std::sin((double)i / iNbSegmentLongitude * 2. * PI) * _diameter / 2.;

			_mesh.add_vertex(x, y, z);
			_mesh.add_vertex(x, y, -z);
		}
		_mesh.add_vertex(0, 0, z);
		_mesh.add_vertex(0, 0, -z);

		// associates triangles, edge 
		for (int i = 0; i < iNbSegmentLongitude - 1; i++)
		{
			_mesh.add_quad(2 * i, 2 * i + 1, 2 * i + 3, 2 * i + 2);
		}
		_mesh.add_quad(2 * iNbSegmentLongitude - 2, 2 * iNbSegmentLongitude - 1, 1, 0);

		// associates triangles, up face 
		for (int i = 0; i < iNbSegmentLongitude; i++)
		{
			_mesh.add_triangle(iNbSegmentLongitude * 2, 2 * i, 2 * i + 2);
		}
		_mesh.add_triangle(iNbSegmentLongitude * 2, 2 * iNbSegmentLongitude - 2, 0);

		// associates triangles, down face 
		for (int i = 0; i < iNbSegmentLongitude; i++)
		{
			_mesh.add_triangle(iNbSegmentLongitude * 2 + 1, 2 * i + 3, 2 * i + 1);
		}
		_mesh.add_triangle(iNbSegmentLongitude * 2 + 1, 1, 2 * iNbSegmentLongitude - 1);

		_transform.apply(_mesh);
	}
	///////////////////////////////////////////////////////////////////////////
	Sphere::Sphere(double diameter, int iLevelOfDetails)
	{
		_diameter = diameter;
		_iLevelOfDetails = iLevelOfDetails;
	}
	void Sphere::compute_faces()
	{
		if (!_mesh.empty())
			return;

		Mesh m;
		Icosahedron ico(1.);
		MeshTessellate mt;
		mt.compute(ico.mesh(), _iLevelOfDetails, _mesh);

		//scale _mesh vertices
		for (int i = 0; i < _mesh.nb_vertices(); i++)
		{
			Point3 v;
			_mesh.get_vertex(i, v);
			v = v.normalized() * (_diameter / 2.);
			_mesh.set_vertex(i, v);
		}

		_transform.apply(_mesh);
	}
	///////////////////////////////////////////////////////////////////////////
	Torus::Torus(double dMajorRadius,double dMinorRadius)
	{
		_dMajorRadius = dMajorRadius;	_dMinorRadius = dMinorRadius;
	}
	void Torus::compute_faces()
	{
		if (!_mesh.empty())
			return;

		double PI = 3.14159265358979323846264338; // TODO

		int iNbSegmentLongitude = _iNbSegments / 2;
		int iNbSegmentLatitude = _iNbSegments / 4;

		// create vertices
		for (int longitude = 0; longitude < iNbSegmentLongitude; longitude++) //longitude
		{
			double upi = (double)longitude / iNbSegmentLongitude * 2. * PI;

			for (int latitude = 0; latitude < iNbSegmentLatitude; latitude++) //latitude
			{
				double vpi = (double)latitude / iNbSegmentLatitude * 2.* PI;

				// compute parametric point from: https://en.wikipedia.org/wiki/Torus
				Point3 p;
				p._x = (_dMajorRadius + _dMinorRadius * std::cos(vpi)) * std::cos(upi);
				p._y = (_dMajorRadius + _dMinorRadius * std::cos(vpi)) * std::sin(upi);
				p._z = _dMinorRadius * std::sin(vpi);

				_mesh.add_vertex(p);
			}
		}

		// associates quads
		for (int longitude = 0; longitude < iNbSegmentLongitude; longitude++)
		{
			for (int latitude = 0; latitude < iNbSegmentLatitude; latitude++)
			{
				int longitude2 = (longitude + 1) % iNbSegmentLongitude;
				int latitude2 = (latitude + 1) % iNbSegmentLatitude;
				_mesh.add_quad(
					longitude2 * iNbSegmentLatitude + latitude,
					longitude2 * iNbSegmentLatitude + latitude2,
					longitude * iNbSegmentLatitude + latitude2,
					longitude * iNbSegmentLatitude + latitude);
			}
		}

		_transform.apply(_mesh);
	}
	///////////////////////////////////////////////////////////////////////////
}
