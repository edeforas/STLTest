#ifndef BodyIntersection_
#define BodyIntersection_

#include "Body.h"

///////////////////////////////////////////////////////////////////////////
class BodyIntersection: public Body
{
public:
    BodyIntersection();
    virtual ~BodyIntersection();

    void set(Body& A,Body& B);

    virtual void compute_faces() override;

private:
    Body* _A;
    Body* _B;
};
///////////////////////////////////////////////////////////////////////////

#endif