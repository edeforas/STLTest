#include <cmath>
using namespace std;

#include "RendererLight.h"

RendererLight::RendererLight()
{ }

////////////////////////////////////////////////////////////////////////////////
RendererLightAmbiant::RendererLightAmbiant(int iAmbiantColor, double dAmbiantFactor)
{
	_dAmbiantRed = dAmbiantFactor*((iAmbiantColor >> 16) & 0xff) / 256.;
	_dAmbiantGreen = dAmbiantFactor*((iAmbiantColor >> 8) & 0xff) / 256.;
	_dAmbiantBlue = dAmbiantFactor*((iAmbiantColor ) & 0xff) / 256.;
}

void RendererLightAmbiant::apply(double& dRed,double& dGreen, double& dBlue)
{
	dRed*=_dAmbiantRed;
	dGreen*=_dAmbiantGreen;
	dBlue*=_dAmbiantBlue;
}
////////////////////////////////////////////////////////////////////////////////
