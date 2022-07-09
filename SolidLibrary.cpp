#include "SolidLibrary.h"

namespace SolidLibrary
{
	Solid* create_cube()
	{
		auto s = new Solid();

		//+z face
		s->add_triangle(Triangle( 1, 1, 1, -1, 1, 1, 1, -1, 1));
		s->add_triangle(Triangle(-1, 1, 1, -1, -1, 1, 1, -1, 1));

		//-z face
		s->add_triangle(Triangle(-1, 1, -1, 1, 1, -1, 1, -1, -1));
		s->add_triangle(Triangle( -1, -1, -1, -1, 1, -1, 1, -1, -1));

		//+x face
		s->add_triangle(Triangle(  1, 1, 1, 1, -1, 1, 1, 1, -1));
		s->add_triangle(Triangle(1, -1, 1, 1, -1, -1, 1, 1, -1));

		//-x face
		s->add_triangle(Triangle(-1, -1, 1, -1,1, 1, -1,1, -1));
		s->add_triangle(Triangle( -1, -1, -1, -1, -1, 1, -1, 1, -1));

		//+y face
		s->add_triangle(Triangle( 1, 1, 1, 1, 1, -1, -1,  1, 1));
		s->add_triangle(Triangle(1, 1, -1, -1, 1, -1, -1, 1, 1));

		//-y face
		s->add_triangle(Triangle(1, -1, -1, 1, -1, 1, -1, -1, 1));
		s->add_triangle(Triangle( -1, -1, -1, 1, -1, -1, -1, -1, 1));

		return s;
	}


	Solid* create_octahedron()
	{
		auto s = new Solid();

		s->add_triangle(Triangle(1, 0, 0, 0, 1, 0, 0, 0, 1));
		s->add_triangle(Triangle( 0, 1, 0, -1, 0, 0, 0, 0, 1));
		s->add_triangle(Triangle( 0, -1, 0, 1, 0, 0, 0, 0, 1));
		s->add_triangle(Triangle( 0, 1, 0, 1, 0, 0, 0, 0, -1));
		s->add_triangle(Triangle(-1, 0, 0, 0, -1, 0, 0, 0, 1));
		s->add_triangle(Triangle(-1, 0, 0, 0, 1, 0, 0, 0, -1));
		s->add_triangle(Triangle(1, 0, 0, 0, -1, 0, 0, 0, -1));
		s->add_triangle(Triangle( 0, -1, 0, -1, 0, 0, 0, 0, -1));
			
		return s;
	}
}