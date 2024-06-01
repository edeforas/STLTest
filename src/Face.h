#ifndef _Face_
#define _Face_

#include "Mesh.h"

///////////////////////////////////////////////////////////////////////////
class Face
{
public:
    Face();
    virtual ~Face();

    void set_color(int iColor);

    virtual void to_mesh(Mesh& m)=0;

private:
    int _iColor;
};
///////////////////////////////////////////////////////////////////////////

#endif