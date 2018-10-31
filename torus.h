///////////////////////////////////////////////////////////
//  torus.h
//  Implementation of the Class Torus
//  Created on:      31-oct.-2018 10:04:27
//  Original author: e1853594
///////////////////////////////////////////////////////////

#if !defined(EA_04686388_47DS_43a5_8FD6_FCF2B104C036__INCLUDED_)
#define EA_04686388_47DS_43a5_8FD6_FCF2B104C036__INCLUDED_

#include "PrimitiveAbs.h"

class Torus : public PrimitiveAbs
{

public:
	Torus(const Point3D& pt, float r1, float r2);
	virtual ~Torus();
	virtual Torus* clone() const;

	virtual size_t getNbParameters() const;
	virtual PrimitiveParams getParameters() const;
	virtual void setParameter(size_t pIndex, float pValue);

private:
	virtual std::ostream& toStream(std::ostream& o) const;

	float m_radiuses[2];
};
#endif // !defined(EA_04686388_47DS_43a5_8FD6_FCF2B104C036__INCLUDED_)