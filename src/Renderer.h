#ifndef _Renderer_
#define _Renderer_

//very old code

#include "Geometry.h"

class Camera
{
public:
	Camera();
	void set_angles(double yaw, double pitch, double roll);
	void set_origin(double x, double y, double z, double ahead);
	void set_screen(int width, int height, double zoom);
	Point3 local_ref(const Point3& pc) const;
	bool project(const Point3& pPixels, double& screenx, double& screeny, double& w); //w =1/z
	
private:
	//rotation angles
	double _yawCos, _yawSin, _pitchCos, _pitchSin, _rollCos, _rollSin;
	double _yaw, _pitch, _roll; 

	//camera position
	double _x, _y, _z, _ahead; 

	// screen properties
	double _zoomFactor;
	int _screenCenterX, _screenCenterY;
};

class Renderer
{
public:
	Renderer(int* pBuffer, int width, int height);
	~Renderer();

	void clear();
	void set_camera(double ox, double oy, double oz, double ahead, double yaw, double pitch, double roll, double zoom);

	void draw_triangle_1color(const Point3& A, const Point3& B, const Point3& C, int color);
	void draw_line(const Point3& p1, const Point3& p2, int color);
	void draw_pixel(const Point3& pPixels, int color);

private:
	void draw_trapeze(double ax, double aw, double bx, double bw, double ay, double cx, double cw, double dx, double dw, double cy, int color);
	void draw_horizontal_line(double ax, double aw, double bx, double bw, double y, int color);

	Camera _camera;
	int* _pixelBuffer;
	float* _wbuffer;
	int _Xmax, _Ymax;
};

#endif
