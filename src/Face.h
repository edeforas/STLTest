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

    vector<Surface>& faces();

    void to_mesh(Mesh& m,int iNbSegments);

private:
    vector<Surface> _vSurfaces;
    int _iColor;
};
///////////////////////////////////////////////////////////////////////////

#endif