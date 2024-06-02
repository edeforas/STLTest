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

    virtual void add_to_mesh(Mesh& m, int iNbSegments) override;

protected:

};
///////////////////////////////////////////////////////////////////////////

#endif