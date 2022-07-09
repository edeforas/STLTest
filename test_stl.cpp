#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////////
class Triangle
{
public:
	Triangle(float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3)
	{
        _x1 = x1;
        _y1 = y1;
        _z1 = z1;
            
        _x2 = x2;
        _y2 = y2;
        _z2 = z2;

        _x3 = x3;
        _y3 = y3;
        _z3 = z3;
	}
	
    float _x1, _y1, _z1, _x2, _y2, _z2, _x3, _y3, _z3;
};
///////////////////////////////////////////////////////////////////////////
class Solid
{
public:
	Solid()
	{}
        
    void add_triangle(Triangle t)
	{
        _all_triangles.push_back(t);
	}
	
    vector<Triangle> triangles()
	{
        return _all_triangles;
	}

    vector<Triangle> _all_triangles;
};
///////////////////////////////////////////////////////////////////////////
bool save_stl(string filename,Solid s)
{
    ofstream f(filename, ios::out | ios::binary);
    if (!f)
        return false;

    int32_t zero = 0;

    // write header
    for (int i = 0; i < 20; i++)
        f.write((char*)(&zero), 4);

    auto& a = s.triangles();
    auto nbt = a.size();
    f.write((char*)(&nbt), 4);

    for (int i = 0; i < nbt; i++)
    {
        // write normals
        for (int j = 0; j < 3; j++)
            f.write((char*)(&zero), 4);

        auto& t = a[i];
        f.write((char*)(&t._x1), 4);
        f.write((char*)(&t._y1), 4);
        f.write((char*)(&t._z1), 4);

        f.write((char*)(&t._x2), 4);
        f.write((char*)(&t._y2), 4);
        f.write((char*)(&t._z2), 4);

        f.write((char*)(&t._x3), 4);
        f.write((char*)(&t._y3), 4);
        f.write((char*)(&t._z3), 4);

        f.write((char*)(&zero), 2);
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////
void main()
{
	auto s=Solid();

    // save a octahedron
	s.add_triangle(Triangle(1,0,0, 0,1,0, 0,0,1));
    s.add_triangle(Triangle(-1, 0, 0, 0, 1, 0, 0, 0, 1));
    s.add_triangle(Triangle(1, 0, 0, 0, -1, 0, 0, 0, 1));
    s.add_triangle(Triangle(1, 0, 0, 0, 1, 0, 0, 0, -1));
    s.add_triangle(Triangle(-1, 0, 0, 0, -1, 0, 0, 0, 1));
    s.add_triangle(Triangle(-1, 0, 0, 0, 1, 0, 0, 0, -1));
    s.add_triangle(Triangle(1, 0, 0, 0, -1, 0, 0, 0, -1));
    s.add_triangle(Triangle(-1, 0, 0, 0, -1, 0, 0, 0, -1));

    save_stl("octahedron.stl",s);
}