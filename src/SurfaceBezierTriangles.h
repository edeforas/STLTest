#ifndef SurfaceBezierTriangles_
#define SurfaceBezierTriangles_

#include "Mesh.h"
#include "Surface.h"

///////////////////////////////////////////////////////////////////////////
class SurfaceBezierTriangles : public Surface
{
public:
    SurfaceBezierTriangles();
    virtual ~SurfaceBezierTriangles();
    void clear();

    virtual void add_to_mesh(Mesh& m, int iNbSegments) override;

protected:
};
///////////////////////////////////////////////////////////////////////////

#endif