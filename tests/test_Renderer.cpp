#include "Renderer.h"
#include "Image.h"
#include "ImageIoBmp.h"
#include "BodyFactory.h"

/////////////////////////////////////////////////////////////////////////////
int main()
{
	int iWidth = 1024;
	int iHeight = 1024;
	double dAngleX = 20., dAngleY = 10., dAhead = 50., dZoom = 1000.;
	
	BodyFactory::Torus torus(15, 3);
	torus.set_color(PIXELRGB(128, 128, 128));
	torus.set_precision(32);

	BodyFactory::SphereUV sphere(10);
	sphere.set_color(PIXELRGB(64, 64, 255));
	sphere.set_precision(32);

	Image img(iWidth, iHeight, 4);
	Renderer eng((int*)img.data(),iWidth, iHeight);
	eng.add_ambient_light(0x808080, 1.);
	eng.add_diffuse_light(0xFF0000, 1., Point3(1., 0., 1.));
	eng.add_diffuse_light(0x00FF00, 1., Point3(0., 1., 0.));
	eng.add_diffuse_light(0x0000FF, 1., Point3(0., 1., 1.));

	for (int i = 0; i < 360; i += 10)
	{
		eng.set_camera(0., 0., 0., dAhead, +i, i/2., i/3., dZoom);
		eng.clear(); 
		eng.draw_mesh(torus.mesh());
		eng.draw_mesh(sphere.mesh());
		ImageIoBmp::write(string("cube_")+to_string(i)+".bmp", &img);
	}

	return 0;
}
/////////////////////////////////////////////////////////////////////////////