#ifndef FaceMesh_
#define FaceMesh_

#include "Mesh.h"
#include "Face.h"

///////////////////////////////////////////////////////////////////////////
class FaceMesh : public Face
{
public:
    FaceMesh();
    FaceMesh(const FaceMesh & f);
    virtual ~FaceMesh();

    void clear();

    Mesh& mesh();
    virtual void add_to_mesh(Mesh& m, int iNbSegments) override;

protected:
    Mesh _mesh;
};
///////////////////////////////////////////////////////////////////////////

#endif