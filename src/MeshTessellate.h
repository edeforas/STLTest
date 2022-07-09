#ifndef _MeshTessellate
#define _MeshTessellate

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