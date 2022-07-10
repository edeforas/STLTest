#include "SolidLibrary.h"
#include "STLWriter.h"

///////////////////////////////////////////////////////////////////////////
void main()
{
	Solid s;
	auto octa=SolidLibrary::create_octahedron();
	auto tetra = SolidLibrary::create_tetrahedron();

	s.add_solid(octa);
	s.add_solid(tetra);
	STLWriter::save("two_solids.stl",s);
}