#ifndef _STLWriter_
#define _STLWriter_

#include <string>
using namespace std;

#include "Solid.h"
namespace STLWriter
{
	bool save(string filename, const Solid& s);
}

#endif