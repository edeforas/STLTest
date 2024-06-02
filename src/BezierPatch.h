#ifndef _BezierPatch_
#define _BezierPatch_

#include "Geometry.h"
#include <vector>
using namespace std;

#include "Mesh.h"

///////////////////////////////////////////////////////////////////////////
// deg3 -> 16 control point needed
class BezierPatch
{
public:
    BezierPatch();
    virtual ~BezierPatch();

    void set_P(const vector<Point3>& vP);

    void clear();

    void add_to_mesh(Mesh& m);

protected:
    vector<Point3> _vP;
};
///////////////////////////////////////////////////////////////////////////

#endif