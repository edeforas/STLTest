#ifndef _Transform_
#define _Transform_

#include "Mesh.h"

class Transform
{
public:
    Transform();

    void set_global_translation(const Point3& translation);
    void set_global_translation(double x, double y, double z);
    void reset();

    void apply(Mesh& m);

private:
    Point3 _translation;
};

#endif