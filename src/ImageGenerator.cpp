
#include "ImageGenerator.h"

namespace ImageGenerator
{
	///////////////////////////////////////////////////////////////////////////
	void Shierpinsky(Image &img,int iWidth,int iHeight)
	{
		img.resize(iWidth, iHeight, 4); // 32bpp
		for (int w = 0; w < img.width(); w++)
			for (int h = 0; h < img.height(); h++)
				*(int*)(img.pixel(w, h)) = ((w & h) == 0) * ((1 << 25) - 1); //Sierpinsky
		
	}
	///////////////////////////////////////////////////////////////////////////
	void Mandelbrot(Image& img, int iWidth, int iHeight) //slow pixel by pixel algorithm
	{
		float xmin = -2., xmax = 2.;
		float ymin = -2., ymax = 2.;

		img.resize(iWidth, iHeight, 4); // 32bpp

		for (int w = 0; w < img.width(); w++)
			for (int h = 0; h < img.height(); h++)
			{
				float cx = xmin + (img.width() - w) / (float)img.width() * (xmax - xmin);
				float cy = xmin + (img.height() - h) / (float)img.height() * (ymax - ymin);

				int iterMax = 255;

				float fx = cx;
				float fy = cy;
				
				// iterate
				while (fx * fx + fy * fy < 4.)
				{
					float fxy = fx*fy;
					fx = (fx + fy) * (fx - fy) + cx;
					fy = fxy + fxy + cy;

					if (iterMax == 0.)
						break;
					else
						iterMax--;
				}

				int color = (255- iterMax) * (1*256*256 + 1*256 + 1); // todo nice color
				*((int*)img.pixel(w, h)) = color;
			}
	}
	///////////////////////////////////////////////////////////////////////////
}
