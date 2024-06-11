#include "Renderer.h"
#include "Image.h"
#include "ImageIoBmp.h"
#include "BodyFactory.h"

#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
int main()
{
	int iWidth = 1600;
	int iHeight = 1200;
	double dAngleX = 20., dAngleY = 10., dAhead = 50., dZoom = 2000.;
	
	BodyFactory::Torus torus(15, 3);
	torus.set_color(GREY);
	torus.set_mesh_precision(32);

	BodyFactory::SphereUV sphere(10);
	sphere.set_color(DARK_GREEN);
	sphere.set_mesh_precision(32);
	sphere.transform().set_global_translation(Point3(10, 0., 0.));

	Image img(iWidth, iHeight, 4);
	Renderer eng((int*)img.data(),iWidth, iHeight);
	eng.set_background(DARK_GREY);
	eng.add_ambient_light(GREY, 1.);
	eng.add_diffuse_light(RED, 1., Point3(1., 0., 1.));
	eng.add_diffuse_light(GREEN, 1., Point3(0., 1., 0.));
	eng.add_diffuse_light(BLUE, 1., Point3(0., 1., 1.));

	for (int i = 0; i < 360; i += 10)
	{
		eng.clear();
		eng.set_camera(0., 0., 0., dAhead, i, i/2., i/3., dZoom);
		eng.draw_mesh(torus.to_mesh());
		eng.draw_mesh(sphere.to_mesh());

		string sFile = string("solid_") + to_string(i) + ".bmp";

		cout << "Writing: " << sFile << endl;
		if (!ImageIoBmp::write(sFile, &img))
		{
			cout << "Unable to write rendered image" << sFile << ", good path and rights ? " << endl;
			return -1;
		}
	}

	cout << "Test Finished.";
	return 0;
}
/////////////////////////////////////////////////////////////////////////////