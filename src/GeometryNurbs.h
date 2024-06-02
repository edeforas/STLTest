#ifndef FaceNurbs_
#define FaceNurbs_

#include "Mesh.h"
#include "Face.h"

///////////////////////////////////////////////////////////////////////////
class SurfaceNurbs : public Face
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