#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"

class figuraGeometrica{
protected:
    float r, g, b, a;
public:
    virtual ~figuraGeometrica(){}
    virtual void draw(Sculptor &s)=0;
};

#endif // FIGURAGEOMETRICA_H
