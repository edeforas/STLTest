#ifndef _Face_
#define _Face_

#include "Mesh.h"

///////////////////////////////////////////////////////////////////////////
class Face
{
public:
    Face();
    virtual ~Face();

    virtual Face* clone() const =0;
    void set_color(int iColor);

    virtual void add_to_mesh(Mesh& m,int iNbSegments)=0;

protected:
    int _iColor;
};
///////////////////////////////////////////////////////////////////////////

#endif