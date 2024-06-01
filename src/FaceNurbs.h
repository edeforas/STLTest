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

    virtual void to_mesh(Mesh& m) override;

protected:
};
///////////////////////////////////////////////////////////////////////////

#endif