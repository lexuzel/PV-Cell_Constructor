#ifndef PVLAYER_H
#define PVLAYER_H

#include "Builders/Builder.h"


class PVLayer
{
public:
    PVLayer();
    void setBuilder(const Builder &builder);

private:
    Builder* m_builder;
//  double ph_current;
//	double rec_current;
//	double minor_current;
//	double equ_current;
};

#endif // PVLAYER_H
