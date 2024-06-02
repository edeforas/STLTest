#ifndef SurfaceTriangles_
#define SurfaceTriangles_

#include "Mesh.h"
#include "Surface.h"

///////////////////////////////////////////////////////////////////////////
class SurfaceTriangles : public Surface
{
public:
    SurfaceTriangles();
    virtual ~SurfaceTriangles();
    void clear();

    virtual void add_to_mesh(Mesh& m, int iNbSegments) override;

protected:
};
///////////////////////////////////////////////////////////////////////////

#endif