#ifndef _BodyFactory_
#define _BodyFactory_

#include "Body.h"

namespace BodyFactory
{
    ///////////////////////////////////////////////////////////////////////////
    class Tetrahedron : public Body
    {
    public:
        explicit Tetrahedron(double dSize);

        virtual void compute_faces() override;

    private:
        double _size;
    };
    ///////////////////////////////////////////////////////////////////////////
    class Box : public Body
    {
    public:
        explicit Box(double xSize, double ySize, double zSize);

        virtual void compute_faces() override;

    private:
        double _xSize, _ySize, _zSize;
    };
    ///////////////////////////////////////////////////////////////////////////
    class Octahedron : public Body
    {
    public:
        explicit Octahedron(double dSize);

        virtual void compute_faces() override;

    private:
        double _size;
    };
    ///////////////////////////////////////////////////////////////////////////
    class Dodecahedron : public Body
    {
    public:
        explicit Dodecahedron(double dSize);

        virtual void compute_faces() override;

    private:
        double _size;
    };    
	///////////////////////////////////////////////////////////////////////////
    class Icosahedron : public Body
    {
    public:
        explicit Icosahedron(double dSize);

        virtual void compute_faces() override;

    private:
        double _size;
    };
    ///////////////////////////////////////////////////////////////////////////
    class Cylinder : public Body
    {
    public:
        explicit Cylinder(double height, double diameter);

        virtual void compute_faces() override;

    private:
        double _height, _diameter;
    };
    ///////////////////////////////////////////////////////////////////////////
    class Sphere : public Body
    {
    public:
        explicit Sphere(double diameter, int iLevelOfDetails=3);

        virtual void compute_faces() override;

    private:
        double _diameter;
        int _iLevelOfDetails;
    };
    ///////////////////////////////////////////////////////////////////////////
    class Torus : public Body
    {
    public:
        Torus(double dMajorRadius, double dMinorRadius);

        virtual void compute_faces() override;

    private:
        double _dMajorRadius,_dMinorRadius;
    };
    ///////////////////////////////////////////////////////////////////////////
}
#endif