#ifndef _Body_
#define _Body_

#include "Mesh.h"
#include "Transform.h"

///////////////////////////////////////////////////////////////////////////
class Body
{
public:
    Body();
    virtual ~Body();

    Transform& transform();

    virtual void set_precision(int iPrecision);

    virtual void compute_faces() =0;
    virtual Mesh& mesh();
    
protected:
    Mesh _mesh;
    int _iNbSegments;
    Transform _transform;
};
///////////////////////////////////////////////////////////////////////////

#endif