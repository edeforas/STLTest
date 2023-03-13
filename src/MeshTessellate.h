#ifndef _MeshTessellate_
#define _MeshTessellate_

#include "Mesh.h"

///////////////////////////////////////////////////////////////////////////
class MeshTessellate
{
public:
    MeshTessellate();
    virtual ~MeshTessellate();

    void compute(const Mesh & meshIn, int iLevel, Mesh& meshOut);
};
///////////////////////////////////////////////////////////////////////////

#endif