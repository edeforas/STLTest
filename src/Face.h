#ifndef _Face_
#define _Face_

///////////////////////////////////////////////////////////////////////////
class Face
{
public:
    Face();
    virtual ~Face();

    void set_color(int iColor);
private:
    int _iColor;
};
///////////////////////////////////////////////////////////////////////////

#endif