#include "stdafx.h"
#include "Parallelepiped.h"

double CParallelepiped::GetHeight() const
{
	return m_height;
}

double CParallelepiped::GetWidth() const
{
	return m_width;
}

double CParallelepiped::GetDepth() const
{
	return m_depth;
}

double CParallelepiped::GetVolume() const
{
	return m_depth * m_width * m_height;
}

CParallelepiped::CParallelepiped(double density, double width, double height, double depth)
	:m_depth(depth), m_height(height), m_width(width)
{
	if (depth <= 0)
	{
		throw std::invalid_argument("Can not to create parallelepiped with negative depth");
	}
	if (height <= 0)
	{
		throw std::invalid_argument("Can not to create parallelepiped with negative height");
	}
	if (width <= 0)
	{
		throw std::invalid_argument("Can not to create parallelepiped with negative width");
	}
	if (density <= 0)
	{
		throw std::invalid_argument("Can not to create parallelepiped with negative density");
	}
	m_density = density;
}

std::string CParallelepiped::NameToString() const
{
	return "Parallelepiped:";
}

std::string CParallelepiped::FieldsToString() const
{
	std::string result;
	result = result + ", depth = " + std::to_string(GetDepth()) + ",";
	result = result + " width = " + std::to_string(GetWidth()) + ",";
	result = result + " height = " + std::to_string(GetHeight());
	return result;
}

bool CParallelepiped::operator==(const CParallelepiped & arg) const
{
	return (arg.GetDensity() == GetDensity()) &&
		(arg.GetMass() == GetMass()) &&
		(arg.GetVolume() == GetVolume()) &&
		(arg.GetDepth() == GetDepth()) &&
		(arg.GetWidth() == GetWidth()) &&
		(arg.GetHeight() == GetHeight());
}