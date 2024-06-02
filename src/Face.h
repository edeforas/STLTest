#ifndef _Face_
#define _Face_

#include "Mesh.h"
#include "Surface.h"

#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////////////
class Face
{
public:
    Face();
    virtual ~Face();

    void set_color(int iColor);

    virtual void add_to_mesh(Mesh& m,int iNbSegments)=0;

protected:
    int _iColor;
};
///////////////////////////////////////////////////////////////////////////

#endif