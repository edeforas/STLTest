#ifndef SurfaceMesh_
#define SurfaceMesh_

#include "Mesh.h"
#include "Surface.h"

///////////////////////////////////////////////////////////////////////////
class SurfaceMesh : public Surface
{
public:
    SurfaceMesh();
    virtual ~SurfaceMesh();
    void clear();

    Mesh& mesh();
    virtual void add_to_mesh(Mesh& m, int iNbSegments) override;

protected:
    Mesh _mesh;
};
///////////////////////////////////////////////////////////////////////////

#endif