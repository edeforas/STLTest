#ifndef _OBJFile_
#define _OBJFile_

#include <string>
using namespace std;

#include "Mesh.h"

namespace OBJFile
{
	bool save(const string& filename, const Mesh& mesh);
	bool load(const string& filename, Mesh& mesh);
}

#endif