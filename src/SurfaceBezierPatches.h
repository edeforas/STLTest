#ifndef SurfaceBezierPatches_
#define SurfaceBezierPatches_

#include "Surface.h"
#include "Mesh.h"

///////////////////////////////////////////////////////////////////////////
class SurfaceBezierPatches : public Surface
{
public:
    SurfaceBezierPatches();
    virtual ~SurfaceBezierPatches();
    void clear();

    virtual void add_to_mesh(Mesh& m, int iNbSegments) override;

protected:
};
///////////////////////////////////////////////////////////////////////////

#endif