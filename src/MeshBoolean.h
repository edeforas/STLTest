#ifndef _MeshBoolean_
#define _MeshBoolean_

#include "Mesh.h"

#include <vector>
using namespace std;

#include "Geometry.h"

///////////////////////////////////////////////////////////////////////////
class MeshBoolean
{
public:
    MeshBoolean();
    
    //split mesh into boolean Shells, WIP
    void split_meshes(const Mesh& A, const Mesh& B, Mesh& Aonly, Mesh& Bonly, Mesh& AInB, Mesh& BInA);

};
///////////////////////////////////////////////////////////////////////////

#endif