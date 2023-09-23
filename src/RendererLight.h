#ifndef _RendererLight_
#define _RendererLight_

#include "Geometry.h"

class RendererLight
{
public:
	RendererLight();
	
	virtual void apply(double& dRed,double& dGreen, double& dBlue) =0;
};

class RendererLightAmbiant: public RendererLight
{
public:
	RendererLightAmbiant(int iAmbiantColor =0x808080, double dAmbiantFactor = 1.);

	virtual void apply(double& dRed, double& dGreen, double& dBlue) override;

private:
	double _dAmbiantRed,_dAmbiantGreen,_dAmbiantBlue;
};

#endif
