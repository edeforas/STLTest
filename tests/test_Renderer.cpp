#include <cstdlib>
#include <cmath>

#include "Renderer.h"
#include "Image.h"
#include "ImageIoBmp.h"

////////////////////////////////////////////////////////////////////////////////
void draw(Renderer& eng,Image& img)
{
	eng.clear();
	
	Point3 a;
	srand(0);
	for (int point = 0; point < 2000; point++)
	{
		a.x() = (rand() % 1000) / 200.;
		a.y() = (rand() % 1000) / 200.;
		a.z() = (rand() % 1000) / 200.;

		int color = point * 30000;

		eng.draw_pixel(a, color);
	}
	
	eng.draw_triangle_1color(Point3(10, 10, 10), Point3(10, 10, -10), Point3(10, -10, 10), PIXELRGB(255, 0, 0));

	//draw cube edges
	eng.draw_line(Point3(10, 10, -10), Point3(10, 10, 10), PIXELRGB(255, 255, 255));
	eng.draw_line(Point3(10, -10, -10), Point3(10, -10, 10), PIXELRGB(255, 255, 255));
	eng.draw_line(Point3(-10, 10, -10), Point3(-10, 10, 10), PIXELRGB(255, 255, 255));
	eng.draw_line(Point3(-10, -10, -10), Point3(-10, -10, 10), PIXELRGB(255, 255, 255));

	eng.draw_line(Point3(10, -10, 10), Point3(10, 10, 10), PIXELRGB(255, 255, 255));
	eng.draw_line(Point3(-10, -10, 10), Point3(-10, 10, 10), PIXELRGB(255, 255, 255));
	eng.draw_line(Point3(10, -10, -10), Point3(10, 10, -10), PIXELRGB(255, 255, 255));
	eng.draw_line(Point3(-10, -10, -10), Point3(-10, 10, -10), PIXELRGB(255, 255, 255));
}
/////////////////////////////////////////////////////////////////////////////
int main()
{
	int iWidth = 1024;
	int iHeight = 1024;
	double dAngleX = 20., dAngleY = 10., dAhead = 25., dZoom = 500.;

	Image img(iWidth, iHeight, 4);
	Renderer eng((int*)img.data(),iWidth, iHeight);
	for (int i = 0; i < 180; i += 10)
	{
		eng.set_camera(0., 0., 0., dAhead, i, 10.-i/2., i/3., dZoom);
		draw(eng, img);
		ImageIoBmp::write(string("cube_")+to_string(i)+".bmp", &img);
	}

	return 0;
}
/////////////////////////////////////////////////////////////////////////////