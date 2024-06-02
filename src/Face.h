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

    void to_mesh(Mesh& m);

private:
    int _iColor;
};
///////////////////////////////////////////////////////////////////////////

#endif