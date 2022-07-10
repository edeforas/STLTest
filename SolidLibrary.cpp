#include "SolidLibrary.h"

namespace SolidLibrary
{
	Solid* create_tetrahedron()
	{
		auto s = new Solid();

		// from https://en.wikipedia.org/wiki/Tetrahedron#Formulas_for_a_regular_tetrahedron
		Point3 a(1, 1, 1), b(-1, -1, 1), c(-1, 1, -1), d(1, -1, -1);

		s->add_triangle(Triangle(b,a,c));
		s->add_triangle(Triangle(a,b,d));
		s->add_triangle(Triangle(c,a,d));
		s->add_triangle(Triangle(b,c,d));

		return s;
	}

	Solid* create_cube()
	{
		auto s = new Solid();

		Point3 a(1, 1, 1), b(-1, 1, 1), c(-1, -1, 1), d(1, -1, 1);
		Point3 e(1, 1, -1), f(-1, 1, -1), g(-1, -1, -1), h(1, -1, -1);
		
		s->add_quad(Quad(a,b,c,d));
		s->add_quad(Quad(h,g,f,e));

		s->add_quad(Quad(e,f,b,a));
		s->add_quad(Quad(d,c,g,h));

		s->add_quad(Quad(f,g,c,b));
		s->add_quad(Quad(a,d,h,e));

		return s;
	}

	Solid* create_octahedron()
	{
		auto s = new Solid();
		Point3 a(1,0,0), b(0,1,0), c(0,0,1), d(-1, 0, 0), e(0,-1,0), f(0,0,-1);

		s->add_triangle(Triangle(a,b,c));
		s->add_triangle(Triangle(d,c,b));
		s->add_triangle(Triangle(c,d,e));
		s->add_triangle(Triangle(a,c,e));

		s->add_triangle(Triangle(b,a,f));
		s->add_triangle(Triangle(f,d,b));
		s->add_triangle(Triangle(d,f,e));
		s->add_triangle(Triangle(f,a,e));

		return s;
	}
}