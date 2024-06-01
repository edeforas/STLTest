#ifndef FaceBezierTriangles_
#define FaceBezierTriangles_

#include "Mesh.h"
#include "Face.h"

///////////////////////////////////////////////////////////////////////////
class FaceBezierTriangles : public Face
{
public:
    FaceBezierTriangles();
    virtual ~FaceBezierTriangles();
    void clear();

    virtual void to_mesh(Mesh& m) override;

protected:
};
///////////////////////////////////////////////////////////////////////////

#endif