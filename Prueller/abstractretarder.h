#ifndef ABSTRACTRETARDER_H
#define ABSTRACTRETARDER_H
#include <commatrix.h>
class abstractRetarder : public comMatrix
{
    float ro;
    float delta;
public:
    abstractRetarder(float angle,float phaseShift){ro =angle;
                                                   delta=phaseShift;}
    void recalc();
    void setRo(float angle){ro = angle;}// sets the fast axis orentation variable
    void setDelta(float angle){delta = angle;}// sets the faze shift of the retarder
};

#endif // ABSTRACTRETARDER_H
