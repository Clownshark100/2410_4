///////////////////////////////////////////////////////////
//  Cylinder.cpp
//  Implementation of the Class Cylinder
//  Created on:      25-oct.-2018 20:47:26
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Cylinder.h"

Cylinder::Cylinder(const Point3D& pt, float r, float ht)
: PrimitiveAbs(pt)
{
	if (r < 0.0 || ht < 0.0)
		throw std::range_error("Invalid parameter value for cylinder. Must be larger than 0");
	m_center = pt;
	m_dimensions[0] = r; // radius
	m_dimensions[1] = ht; // height
}

Cylinder::~Cylinder(){
}

Cylinder * Cylinder::clone() const
{
	return new Cylinder(m_center,m_dimensions[0],m_dimensions[1]);
}

size_t Cylinder::getNbParameters() const {

	return 2;
}

PrimitiveParams Cylinder::getParameters() const
{
	PrimitiveParams parameters;
	parameters.push_back(m_dimensions[0]);
	parameters.push_back(m_dimensions[1]);
	return parameters;
}

void Cylinder::setParameter(size_t pIndex, float pValue){
	if (pIndex < 0 || pIndex > 1)
		throw std::range_error("Invalid parameter index for cylinder. Must be between 0 and 1");

	if (pValue < 0.0)
		throw std::range_error("Invalid parameter value for cylinder. Must be larger than 0");
	switch (pIndex)
	{
	case 0:
		m_dimensions[0] = pValue;
		break;
	case 1:
		m_dimensions[1] = pValue;
		break;
	default:
		throw std::range_error("Invalid parameter value for cylinder. Must be smaller than 2");
		break;
	}
}

std::ostream & Cylinder::toStream(std::ostream & o) const
{
	return o << "Cylinder:  center = " << m_center
		<< "; r = " << m_dimensions[0]
		<< "; ht = " << m_dimensions[1] << ";";
}
