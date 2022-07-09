#ifndef _STLFile_
#define _STLFile_

#include <string>
using namespace std;

#include "Mesh.h"

namespace STLFile
{
	bool save(const string& filename, const Mesh& mesh);
	bool load(const string& filename, Mesh& mesh);
}

#endif