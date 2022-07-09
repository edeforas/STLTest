#include "SolidLibrary.h"
#include "STLWriter.h"

///////////////////////////////////////////////////////////////////////////
void main()
{
	auto s=SolidLibrary::create_octahedron();
    save_stl("octahedron.stl",*s);
	delete s;
}