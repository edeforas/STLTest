#ifndef SurfaceBezierPatches_
#define SurfaceBezierPatches_

#include "Surface.h"
#include "Mesh.h"

#include "Geometry.h"
#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////////////
class SurfaceBezierPatches : public Surface
{
public:
    SurfaceBezierPatches();
    virtual ~SurfaceBezierPatches();
    void clear();

    void set_P(const vector<Point3>& vP);

    virtual void add_to_mesh(Mesh& m, int iNbSegments) override;

protected:
    vector<Point3> _vP;

};
///////////////////////////////////////////////////////////////////////////

#endif