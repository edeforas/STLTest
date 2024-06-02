#ifndef SurfaceNurbs_
#define SurfaceNurbs_

#include "Mesh.h"
#include "Surface.h"

///////////////////////////////////////////////////////////////////////////
class SurfaceNurbs : public Surface
{
public:
    SurfaceNurbs();
    virtual ~SurfaceNurbs();
    void clear();

    virtual void add_to_mesh(Mesh& m, int iNbSegments) override;

protected:
};
///////////////////////////////////////////////////////////////////////////

#endif