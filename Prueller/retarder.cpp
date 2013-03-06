#include "retarder.h"

retarder::retarder(float angle)
{
    recalc(angle);
}

void retarder::recalc(float angle)
{
    complex<float> zero(0.0,0.0);
    complex<float> one(1.0,0.0);
    complex<float> C = cos(2*angle);
    complex<float> S = sin(2*angle);
    A11 = one; A12 = zero; A13 = zero; A14 = zero;
    A21 = zero; A22 = C*C; A23 = C*S; A24 = -S;
    A31 = zero; A32 = C*S; A33 = S*S; A34 = C;
    A41 = zero; A42 = S; A43 = -C; A44 = zero;
}
