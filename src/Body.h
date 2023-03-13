#ifndef _Body_
#define _Body_

#include "Mesh.h"
#include "Transform.h"

#include "Face.h"

#include <vector>
using namespace std;

// todo: cleaner
#define RGB(a,b,c) ((a<<16)+(b<<8)+c)

///////////////////////////////////////////////////////////////////////////
class Body
{
public:
    Body();
    virtual ~Body();

    Transform& transform();
    virtual void set_precision(int iPrecision);
    void set_color(int iColor);
    virtual Mesh& mesh();
    
    vector<Face>& faces();

protected:
    virtual void compute_mesh() = 0;
    Mesh _mesh;
    int _iNbSegments;
    Transform _transform;
    int _iColor; // -1 for no custom color
	
	vector<Face> _faces;
};
///////////////////////////////////////////////////////////////////////////

#endif