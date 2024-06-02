#ifndef SurfaceBezierTriangles_
#define SurfaceBezierTriangles_

#include "Mesh.h"
#include "Surface.h"

///////////////////////////////////////////////////////////////////////////
class SurfaceBezierTriangles : public Surface
{
public:
    SurfaceBezierTriangles();
    virtual ~SurfaceBezierTriangles();
    void clear();

    void set_points(const Point3& P1, const Point3& P2, const Point3& P3);
    void set_control_P(const Point3& controlP1P2, const Point3& controlP2P1, const Point3& controlP1P3, const Point3& controlP3P1, const Point3& controlP2P3, const Point3& controlP3P2);
    void set_control_center(const Point3& controlCenter);
    void set_normals(const Point3& normalP1, const Point3& normalP2, const Point3& normalP3);

    virtual void add_to_mesh(Mesh& m, int iNbSegments) override;

protected:
    Point3 _P1, _P2, _P3;
    Point3 _controlP1P2, _controlP2P1;
    Point3 _controlP1P3, _controlP3P1;
    Point3 _controlP2P3, _controlP3P2;
    Point3 _controlCenter;
};
///////////////////////////////////////////////////////////////////////////

#endif