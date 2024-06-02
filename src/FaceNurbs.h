#ifndef FaceNurbs_
#define FaceNurbs_

#include "Mesh.h"
#include "Face.h"

///////////////////////////////////////////////////////////////////////////
class FaceNurbs : public Face
{
public:
    FaceNurbs();
    virtual ~FaceNurbs();
    void clear();

    virtual void add_to_mesh(Mesh& m, int iNbSegments) override;

protected:
};
///////////////////////////////////////////////////////////////////////////

#endif