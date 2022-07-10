#include <fstream>
#include <string>
using namespace std;

#include "Solid.h"

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
        f.write((char*)(&t._p1._x), 4);
        f.write((char*)(&t._p1._y), 4);
        f.write((char*)(&t._p1._z), 4);

        f.write((char*)(&t._p2._x), 4);
        f.write((char*)(&t._p2._y), 4);
        f.write((char*)(&t._p2._z), 4);

        f.write((char*)(&t._p3._x), 4);
        f.write((char*)(&t._p3._y), 4);
        f.write((char*)(&t._p3._z), 4);

        f.write((char*)(&zero), 2);
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////
