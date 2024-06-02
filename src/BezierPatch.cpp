#include "BezierPatch.h"

#include "Mesh.h"
///////////////////////////////////////////////////////////////////////////

BezierPatch::BezierPatch()
{ }

BezierPatch::~BezierPatch()
{ }

void BezierPatch::set_P(const vector<Point3>& vP)
{
	_vP = vP;
}

void BezierPatch::clear()
{
	_vP.clear();
}

void BezierPatch::add_to_mesh(Mesh& m)
{
	m.clear();

	//todo


}

///////////////////////////////////////////////////////////////////////////