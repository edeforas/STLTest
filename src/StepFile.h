#ifndef _STLFile_
#define _STLFile_

#include <string>
using namespace std;

#include "NurbsSurface.h"

namespace StepFile
{
	bool save(const string& filename, const NurbsSurface& surf);
	bool load(const string& filename, NurbsSurface& surf);
}

#endif