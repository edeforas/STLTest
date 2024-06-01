#ifndef FaceBezierPatches_
#define FaceBezierPatches_

#include "Face.h"
#include "Mesh.h"

///////////////////////////////////////////////////////////////////////////
class FaceBezierPatches : public Face
{
public:
    FaceBezierPatches();
    virtual ~FaceBezierPatches();
    void clear();

    virtual void to_mesh(Mesh& m) override;

protected:
};
///////////////////////////////////////////////////////////////////////////

#endif