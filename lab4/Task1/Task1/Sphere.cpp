#include "stdafx.h"
#include "Sphere.h"

double CSphere::GetRadius() const
{
	return m_radius;
}


double CSphere::GetVolume() const
{
	return 4 * m_radius *  m_radius * m_radius * M_PI / 3;
}

CSphere::CSphere(double density, double radius)
	:m_radius(radius)
{
	if (radius <= 0)
	{
		throw std::invalid_argument("Can not to create sphere with negative radius");
	}
	if (density <= 0)
	{
		throw std::invalid_argument("Can not to create sphere with negative density");
	}
	m_density = density;
}

std::string CSphere::ToString() const
{
	std::string result = "Sphere:";
	result = result + " mass = " + std::to_string(GetMass()) + ",";
	result = result + " density = " + std::to_string(GetDensity()) + ",";
	result = result + " volume = " + std::to_string(GetVolume()) + ",";
	result = result + " radius = " + std::to_string(GetRadius());
	return result;
}

bool CSphere::operator==(const CSphere & arg) const
{
	return (arg.GetDensity() == GetDensity()) &&
		(arg.GetMass() == GetMass()) &&
		(arg.GetVolume() == GetVolume()) &&
		(arg.GetRadius() == GetRadius());
}