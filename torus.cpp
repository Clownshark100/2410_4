///////////////////////////////////////////////////////////
//  torus.cpp
//  Implementation of the Class Torus
//  Created on:      31-oct.-2018 10:04:27
//  Original author: e1853594
///////////////////////////////////////////////////////////

#include "Torus.h"


Torus::Torus(const Point3D& pt, float r1, float r2) : PrimitiveAbs(pt)
{
	if (r1 < 0.0)
		throw std::range_error("Invalid radius value for sphere. Must be larger than 0");
	m_center = pt;
	m_radiuses[0] = r1;
	m_radiuses[1] = r2;
}

Torus::~Torus() {
}

Torus * Torus::clone() const
{
	return new Torus(m_center, m_radiuses[0], m_radiuses[1]);
}

size_t Torus::getNbParameters() const {
	return 2; //radius 1 and radius 2
}

PrimitiveParams Torus::getParameters() const {

	PrimitiveParams params;
	params.push_back(m_radiuses[0]);
	params.push_back(m_radiuses[1]);
	return params;
}

void Torus::setParameter(size_t pIndex, float pValue) {
	if (pIndex < 0 || pIndex > 1)
		throw std::range_error("Invalid parameter index for Torus. Must be between 0 and 1");

	if (pValue < 0.0)
		throw std::range_error("Invalid radius value for Torus. Must be larger than 0");

	m_radiuses[pIndex] = pValue;
}

std::ostream & Torus::toStream(std::ostream & o) const
{
	return o << "Torus: center = " << m_center << "; r1 = " << m_radiuses[0] << "; r2 = " << m_radiuses[1] << ";";
}
