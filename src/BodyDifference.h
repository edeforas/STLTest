#ifndef BodyDifference_
#define BodyDifference_

#include "Body.h"

///////////////////////////////////////////////////////////////////////////
class BodyDifference: public Body
{
public:
    BodyDifference();
    virtual ~BodyDifference();

    void set(Body& A,Body& B);

    virtual void compute_mesh() override;

private:
    Body* _A;
    Body* _B;
};
///////////////////////////////////////////////////////////////////////////

#endif