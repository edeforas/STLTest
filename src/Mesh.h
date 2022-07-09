#ifndef _Mesh_
#define _Mesh_

#include <vector>
using namespace std;

#include "Geometry.h"

///////////////////////////////////////////////////////////////////////////
class Triangle
{
public:
    Triangle(int vertex1, int vertex2, int vertex3);

    bool is_triangle_deleted() const;
    void flip(); // used to inverse the normal

    int vertex1, vertex2, vertex3;
    int state; // 1=ok, 0=deleted todo more
};

class VertexTriangles
{
public:
    Point3 vertex;

    vector<int> triangles;

    void remove_triangle(int iTriangle);
};

///////////////////////////////////////////////////////////////////////////
class Mesh
{
public:
    Mesh();
    ~Mesh();

    void add_mesh(const Mesh& f);


    int nb_vertices() const;
    int add_vertex(const Point3& vertex);
    void add_vertex(double a, double b, double c);
    void set_vertex(int iVertex, const Point3& vertex);
    void get_vertex(int iVertex, Point3& vertex) const;

    int add_triangle(int iVertex1, int iVertex2, int iVertex3); // return the triangle ID
    void get_triangle(int iTriangle, Triangle3& f) const;
    void get_triangle(int iTriangle, int& iVertex1, int& iVertex2, int& iVertex3) const;
    void get_triangle(int iTriangle, Point3& p1, Point3& p2, Point3& p3) const;
    int nb_triangles() const;
    bool is_triangle_deleted(int iTriangle) const;
    void delete_triangle(int iTriangle); // unlink, but keep triangles
    void split_triangle_with_vertex(int iTriangle, int iVertex); //create 3 triangles with edges and new vertex, remove iTriangle
    void flip_triangle(int iTriangle); //flip triangle so normal is opposed

    void add_quad(int iVertex1, int iVertex2, int iVertex3, int iVertex4);
    void add_pentagon(int iVertex1, int iVertex2, int iVertex3, int iVertex4, int iVertex5);      

    void clear();
    bool empty();

private:
    vector<Triangle> _vTriangles;
	vector<VertexTriangles> _vVertices;
};
///////////////////////////////////////////////////////////////////////////

#endif