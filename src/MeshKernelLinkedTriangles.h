#ifndef MeshKernelLinkedTriangles_
#define MeshKernelLinkedTriangles_

#include <vector>
using namespace std;

#include "MeshKernel.h"
#include "Geometry.h"

///////////////////////////////////////////////////////////////////////////
class TriangleLT
{
public:
    TriangleLT(int vertex1, int vertex2, int vertex3);
    int _vertex1, _vertex2, _vertex3;
    int _triangle1,_triangle2,_triangle3;
    int _unlinked; // 0 == linked , -1 == unlinked
    int _reserved;
};

///////////////////////////////////////////////////////////////////////////
class MeshKernelLinkedTriangles: public MeshKernel
{
public:
    MeshKernelLinkedTriangles();
    virtual ~MeshKernelLinkedTriangles() override;
    virtual void clear() override;

    virtual int nb_vertices() const override; // return the vertice id
    virtual int add_vertex(const Point3& vertex) override;
    virtual void set_vertex(int iVertex, const Point3& vertex) override;
    virtual void get_vertex(int iVertex, Point3& vertex) const override;

    virtual int nb_triangles() const override;
    virtual int add_triangle(int iVertex1, int iVertex2, int iVertex3) override; // return the triangle ID
    virtual void get_triangle_vertices(int iTriangle, int& iVertex1, int& iVertex2, int& iVertex3) const override;
    virtual void unlink_triangle(int iTriangle) override;
    virtual bool is_triangle_unlinked(int iTriangle) override;

    virtual void get_near_triangles(int iTriangle, int& iT1, int& iT2, int& iT3) const override;
    virtual bool get_triangles_near_edge(int iVertex1, int  iVertex2, int& iTriangle1, int& iTriangle2) const override;

private:
    vector<TriangleLT> _vTriangles;
	vector<Point3> _vVertices;
};
///////////////////////////////////////////////////////////////////////////

#endif