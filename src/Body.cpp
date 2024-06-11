#include "Body.h"

///////////////////////////////////////////////////////////////////////////
Body::Body()
{
	clear();
}

Body::~Body()
{ 
	for (auto f : _faces)
		delete f;
}

void Body::clear()
{
	_faces.clear();
	_iNbSegments = 4;
	_iColor = -1;
}

Transform& Body::transform()
{
	return _transform;
}

void Body::to_mesh(Mesh& m)
{
	//compute_mesh();
//	if(_iColor!=-1)
//		_mesh.set_color(_iColor);

	for (auto& f : _faces)
		f->add_to_mesh(m, _iNbSegments);


	
}

vector<Face*>& Body::faces()
{
	return _faces;
}

void Body::add_face(const Face& f)
{
	_faces.push_back(f.clone());
}

void Body::set_mesh_precision(int iNbSegments)
{
	_iNbSegments = iNbSegments;
	_mesh.clear(); // must recompute everything next time
}

void Body::set_color(int iColor)
{
	_iColor = iColor;
	_mesh.set_color(_iColor);

	auto& f = faces();
	for (auto& fa : f)
	{
		fa->set_color(iColor);
	}
}

///////////////////////////////////////////////////////////////////////////

void Body::compute_mesh()
{}