#include "SolidLibrary.h"

namespace SolidLibrary
{
	Solid* create_octahedron()
	{
		auto s=new Solid();

		s->add_triangle(Triangle(1,0,0, 0,1,0, 0,0,1));
		s->add_triangle(Triangle(-1, 0, 0, 0, 1, 0, 0, 0, 1));
		s->add_triangle(Triangle(1, 0, 0, 0, -1, 0, 0, 0, 1));
		s->add_triangle(Triangle(1, 0, 0, 0, 1, 0, 0, 0, -1));
		s->add_triangle(Triangle(-1, 0, 0, 0, -1, 0, 0, 0, 1));
		s->add_triangle(Triangle(-1, 0, 0, 0, 1, 0, 0, 0, -1));
		s->add_triangle(Triangle(1, 0, 0, 0, -1, 0, 0, 0, -1));
		s->add_triangle(Triangle(-1, 0, 0, 0, -1, 0, 0, 0, -1));
			
		return s;
	}
}