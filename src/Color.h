#ifndef _Color_
#define _Color_

#define PIXELRGB(r,g,b) ((r<<16)+(g<<8)+b)

#define BLUE PIXELRGB(0xff,0,0)
#define GREEN PIXELRGB(0,0xff,0)
#define RED PIXELRGB(0,0,0xff)

#define GREY PIXELRGB(0x80,0x80,0x80)

#define DARK_GREEN PIXELRGB(0x80,0xff,0x80)


#endif
