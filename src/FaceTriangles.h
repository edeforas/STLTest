#ifndef FaceTriangles_
#define FaceTriangles_

#include "Mesh.h"
#include "Face.h"

///////////////////////////////////////////////////////////////////////////
class FaceTriangles : public Face
{
public:
    FaceTriangles();
    virtual ~FaceTriangles();
    void clear();

    virtual void to_mesh(Mesh& m) override;

protected:
};
///////////////////////////////////////////////////////////////////////////

#endif