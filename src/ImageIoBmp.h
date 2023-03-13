#ifndef _ImageIoBmp_
#define _ImageIoBmp_

#include "Image.h"

#include <string>
using namespace std;

class ImageIoBmp
{
public:
    static bool write(string sFilename,const Image* pImage);
    static bool read(string sFilename, Image* pImage);
};

#endif