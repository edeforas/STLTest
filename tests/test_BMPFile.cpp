#include <iostream>
using namespace std;

#include "Image.h"
#include "ImageGenerator.h"
#include "ImageIoBmp.h"

////////////////////////////////////////////////////////////////////////////////
int main()
{
	// test 32 bit bmp write: black and white Sierpinsky fractal
	Image imgSierpinsky;
	ImageGenerator::Shierpinsky(imgSierpinsky,512, 512);
	if (ImageIoBmp::write("Sierpinsky.bmp", &imgSierpinsky) == false)
	{
		cout << "Unable to write Sierpinsky.bmp, good path and rights?" << endl;
		return -1;
	}

	// test 32 bit bmp write: Mandelbrot fractal
	Image imgMandelbrot;
	ImageGenerator::Mandelbrot(imgMandelbrot, 512, 512);
	if (ImageIoBmp::write("Mandelbrot.bmp", &imgMandelbrot) == false)
	{
		cout << "Unable to write Mandelbrot.bmp, good path and rights?" << endl;
		return -1;
	}

	// test image I/O
	Image imgMandelbrot2;
	if (ImageIoBmp::read("Mandelbrot.bmp", &imgMandelbrot2) == false)
	{
		cout << "Unable to read Mandelbrot.bmp, good path ?" << endl;
		return -1;
	}

	if (ImageIoBmp::write("Mandelbrot2.bmp", &imgMandelbrot2) == false)
	{
		cout << "Unable to write Mandelbrot2.bmp, good path and rights?" << endl;
		return -1;
	}

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
