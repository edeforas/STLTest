#include <cmath>
#include <cassert>
using namespace std;

#include "Renderer.h"
#include "Mesh.h"

//very old code!!

#define MAXINT (1<<28)

// used by mapfacet
#define my_swap(a,b,t) { t=a; a=b; b=t; }

////////////////////////////////////////////////////////////////////////////////
Camera::Camera()
{
	set_angles(0., 0., 0.);
	set_origin(0., 0., 0., 0.);
	set_screen(0, 0, 0.);
}
////////////////////////////////////////////////////////////////////////////////
void Camera::set_angles(double yaw, double pitch, double roll)
{
	double dDegToRad = 2. * 3.14159265359 / 360.;

	_yaw = yaw;
	_pitch = pitch;
	_roll = roll;

	_yawCos = cos(_yaw * dDegToRad);
	_yawSin = sin(_yaw * dDegToRad);
	_pitchCos = cos(_pitch * dDegToRad);
	_pitchSin = sin(_pitch * dDegToRad);
	_rollCos = cos(_roll * dDegToRad);
	_rollSin = sin(_roll * dDegToRad);
}
////////////////////////////////////////////////////////////////////////////////
void Camera::set_origin(double x, double y, double z, double ahead)
{
	_x = x; _y = y; _z = z;
	_ahead = ahead;
}
////////////////////////////////////////////////////////////////////////////////
void Camera::set_screen(int width, int height, double zoom)
{
	_screenCenterX = width / 2;
	_screenCenterY = height / 2;
	_zoomFactor = zoom;
}
////////////////////////////////////////////////////////////////////////////////
Point3 Camera::local_ref(const Point3& pc) const
{
	Point3 pLocal;
	pLocal.x() = pc.x();
	pLocal.y() = pc.y();
	pLocal.z() = pc.z();

	//origin translation
	pLocal.x() -= _x;
	pLocal.y() -= _y;
	pLocal.z() -= _z;

	//yaw rotation
	double tmp = pLocal.x();
	pLocal.x() = pLocal.x() * _yawCos + pLocal.z() * _yawSin;
	pLocal.z() = pLocal.z() * _yawCos - tmp * _yawSin;

	//pitch rotation
	tmp = pLocal.y();
	pLocal.y() = pLocal.z() * _pitchSin - pLocal.y() * _pitchCos;
	pLocal.z() = pLocal.z() * _pitchCos + tmp * _pitchSin;

	//roll rotation
	tmp = pLocal.x();
	pLocal.x() = pLocal.x() * _rollCos + pLocal.y() * _rollSin;
	pLocal.y() = pLocal.y() * _rollCos - tmp * _rollSin;

	// ahead move
	pLocal.z() = pLocal.z() + _ahead;

	return pLocal;
}
////////////////////////////////////////////////////////////////////////////////
bool Camera::project(const Point3& pPixels, double& screenx, double& screeny, double& w)
{
	Point3 pc = local_ref(pPixels);

	screenx = pc.x() * _zoomFactor / pc.z() + _screenCenterX;
	screeny = pc.y() * _zoomFactor / pc.z() + _screenCenterY;

	if ((screenx < 0) || (screenx >= _screenCenterX * 2) || (screeny < 0) || (screeny >= _screenCenterY * 2))
		return false;

	if (pc.z() != 0.)
		w = 1. / pc.z();
	else
		w = 0.;

	return true;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Renderer::set_camera(double ox, double oy, double oz, double ahead, double yaw, double pitch, double roll, double zoom)
{
	_camera.set_origin(ox, oy, oz, ahead);
	_camera.set_angles(yaw, pitch, roll);
	_camera.set_screen(_Xmax, _Ymax, zoom);
}
////////////////////////////////////////////////////////////////////////////////
Renderer::Renderer(int* pBuffer,int xm, int ym)
{
	_Xmax = xm;
	_Ymax = ym;
	_pixelBuffer = pBuffer;

	_wbuffer = new float[_Xmax * _Ymax];

	clear();
}
////////////////////////////////////////////////////////////////////////////////
Renderer::~Renderer()
{
	delete[] _wbuffer;
}
////////////////////////////////////////////////////////////////////////////////
void Renderer::draw_mesh(const Mesh& m,int color, bool bDrawEdges)
{
	for (int i = 0; i < m.nb_triangles(); i++)
	{
		if (m.is_triangle_unlinked(i))
			continue;

		Triangle3 t;
		m.get_triangle(i, t);
		bool bDrawed=draw_triangle_1color(t.p1(), t.p2(), t.p3(), color);
		
		if (bDrawEdges && bDrawed) //todo custom color, clean zbuffer , etc
		{
			draw_line(t.p1(), t.p2(), (0)); //RGB(0,0,0)
			draw_line(t.p1(), t.p3(), (0)); //RGB(0,0,0)
			draw_line(t.p2(), t.p3(), (0)); //RGB(0,0,0)
		}
	}
}
////////////////////////////////////////////////////////////////////////////////
bool Renderer::draw_triangle_1color(const Point3& A, const Point3& B, const Point3& C, int color,bool bTwofaces)
{
	double ax,ay,aw, bx,by,bw, cx,cy,cw;
	_camera.project(A, ax, ay, aw);
	_camera.project(B, bx, by, bw);
	_camera.project(C, cx, cy, cw);

	// test if seeing the back of the facet
	if(bTwofaces==false)
	{
		Point3 norm = (Point3(ax - bx, ay - by, 0.)).cross_product(Point3(ax - cx, ay - cy, 0.));
		if (norm.z() <= 0.)
			return false;
	}

	//exit if triangle is trivially out of screen
	if ((ax <= 0.) && (bx <= 0.) && (cx <= 0.))
		return false;
	if ((ay <= 0.) && (by <= 0.) && (cy <= 0.))
		return false;
	if ((ax >= _Xmax) && (bx >= _Xmax) && (cx >= _Xmax))
		return false;
	if ((ay >= _Xmax) && (by >= _Xmax) && (cy >= _Xmax))
		return false;

	//order points in y axis
	if ((by <= ay) && (by <= cy))
	{
		//exchange B and A
		double tmpx = ax; ax = bx; bx = tmpx;
		double tmpy = ay; ay = by; by = tmpy;
		double tmpw = aw; aw = bw; bw = tmpw;
	}
	else
		if ((cy <= ay) && (cy <= by))
		{
			//exchange C and A
			double tmpx = ax; ax = cx; cx = tmpx;
			double tmpy = ay; ay = cy; cy = tmpy;
			double tmpw = aw; aw = cw; cw = tmpw;
		}

	if (cy < by)
	{
		//exchange C and B
		double tmpx = bx; bx = cx; cx = tmpx;
		double tmpy = by; by = cy; cy = tmpy;
		double tmpw = bw; bw = cw; cw = tmpw;
	}

	//split in two trapeze, compute D= the horizontal intersection of B with AC
	double t = (by - ay) / (cy - ay);
	assert(t >= 0.);
	assert(t <= 1.);

	double dx = cx * t + (1. - t)*ax;
	double dy = cy * t + (1. - t)*ay;
	double dw = cw * t + (1. - t)*aw;

	//reorder in x such that bx<dx
	if ((dx < bx))
	{
		//exchange D and B
		double tmpx = bx; bx = dx; dx = tmpx;
		double tmpy = by; by = dy; dy = tmpy;
		double tmpw = bw; bw = dw; dw = tmpw;
	}

	assert(bx <= dx);
	assert(ay <= by);
	assert(by <= cy);

	//draw each trapez
	bool b1 =draw_trapeze(ax, aw, ax, aw, (int)ay, bx, bw, dx, dw, (int)by, color);
	bool b2 =draw_trapeze(bx, bw, dx, dw, (int)by, cx, cw, cx, cw, (int)cy, color);
	
	return b1 || b2;
}
////////////////////////////////////////////////////////////////////////////////
bool Renderer::draw_trapeze(double ax, double aw, double bx, double bw, int ay, double cx, double cw, double dx, double dw, int cy, int color)
{
	assert(ax <= bx);
	assert(cx <= dx);
	assert(ay <= cy);

	if (cy < 0.)
		return false;

	if (ay > _Ymax)
		return false;

	//reduce facet y
	if (ay < 0)
	{
		double t = (double)(0. -ay) / (cy - ay);
		assert(t >= 0.);
		assert(t <= 1.);

		ay = 0;
		ax = cx * t + (1. - t)*ax;
		aw = cw * t + (1. - t)*aw;
		bx = cx * t + (1. - t)*bx;
		bw = cw * t + (1. - t)*bw;
	}
	if (cy > _Ymax )
	{
		double t = (double)(cy - _Ymax) / (cy - ay);
		assert(t >= 0.);
		assert(t <= 1.);

		cy = _Ymax;
		cx = cx * t + (1. - t)*ax;
		cw = cw * t + (1. - t)*aw;
		dx = dx * t + (1. - t)*bx;
		dw = dw * t + (1. - t)*bw;
	}

	//plot trapeze
	assert(ay <= cy);
	for (int y = ay; y < cy; y++)
	{
		//plot line
		double t = (double)(y - ay) / (cy - ay);
		assert(t >= 0.);
		assert(t <= 1.);

		int p1x = (int)(cx * t + ax * (1. - t));
		double p1w = (cw * t + aw * (1. - t));
		int p2x = (int)(dx * t + bx * (1. - t));
		double p2w = (dw * t + bw * (1. - t));

		assert(p1x <= p2x);
		draw_horizontal_line(p1x, p1w, p2x, p2w, y, color);
	}
	return true;
}
////////////////////////////////////////////////////////////////////////////////
void Renderer::draw_horizontal_line(int ax, double aw, int bx, double bw, int y, int color)
{
	assert(ax <= bx);

	if (bx < 0)
		return;
	if (ax > _Xmax)
		return;

	if (y < 0)
		return;
	if (y > _Xmax)
		return;

	// cut the line if out of screen
	if (ax < 0)
	{
		double t = (double)(bx-0) / (bx - ax);
		assert(t >= 0.);
		assert(t <= 1.);

		ax = 0; // bx* t + (1. - t) * ax;
		aw = bw * t + (1. - t)*aw;
	}
	if (bx > _Xmax)
	{
		double t = (float)(bx - _Xmax) / (bx - ax);
		assert(t >= 0.);
		assert(t <= 1.);

		bx = _Xmax; // ax* t + (1. - t) * bx;
		bw = aw * t + (1. - t)*bw;
	}

	int *pLine = _pixelBuffer + y * _Xmax;
	float *pWBuffer = _wbuffer + y * _Xmax;

	for (int i = ax; i<bx; i++)
	{
		float t = (float)(i-ax) / (bx - ax);
		assert(t >= 0.f);
		assert(t <= 1.f);

		float w = bw * t + aw*(1.f - t);

		if (pWBuffer[i] < w)
		{
			pWBuffer[i] = w;
			pLine[i] = color;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////
void Renderer::clear()
{
	for (int j = 0; j < _Ymax; j++)
	{
		int* pixels = j * _Xmax + _pixelBuffer;
		float* w = j * _Xmax + _wbuffer;
		for (int i = 0; i < _Xmax; i++)
		{
			pixels[i] = 0;
			w[i] = 0.; // z=inf -> w=0
		}
	}
}
////////////////////////////////////////////////////////////////////////////////
void Renderer::draw_line(const Point3& p1, const Point3& p2, int color)
{
	//todo optimize
	double x1, y1, x2, y2;
	double fx, fy, dx, dy;
	int i, im,decal;
	double zp1, zp2, fz, dz;
	double wEpsilon = 1.e-2; // todo exact formula

	_camera.project(p1, x1, y1, zp1);
	_camera.project(p2, x2, y2, zp2);

	dx = x2 - x1;
	dy = y2 - y1;
	if (fabs(dx) > fabs(dy))
		im = int(fabs(dx));
	else
		im = int(fabs(dy));

	if (im < 1)
		return;

	fx = x1;
	dx = dx / im;
	fy = y1;
	dy = dy / im;
	fz = zp1;
	dz = (zp2 - zp1) / im;

	for (i = 0; i < im; i++)
	{
		if ((fx >= 0) && (fx < _Xmax) && (fy >= 0) && (fy < _Ymax))// && (fz>0) )
		{
			decal = int(fx) + int(fy) * _Xmax;

			if (_wbuffer[decal] < fz+wEpsilon)
			{
				_wbuffer[decal] = (float)fz;
				_pixelBuffer[decal] = color;
			}
		}
		fx += dx;
		fy += dy;
		fz += dz;
	}
}
////////////////////////////////////////////////////////////////////////////////
void Renderer::draw_pixel(const Point3& pPixels, int col)
{
	double ix, iy;
	double zpx;
	float* zp;

	if (!_camera.project(pPixels, ix, iy, zpx))
		return;

	//teste if visible in wbuffer
	zp = _wbuffer + (int)ix + (int)iy * _Xmax;

	//compare with wbuffer and write if nearer
	if ((*zp) < zpx)
	{
		*zp = (float)zpx;
		_pixelBuffer[(int)ix + (int)iy * _Xmax] = col;
	}
}
////////////////////////////////////////////////////////////////////////////////
