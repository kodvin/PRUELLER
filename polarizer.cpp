#include "polarizer.h"

void polarizer::recalc()
{    
    complex<float> zero(0.0,0.0);
    complex<float> one(1.0,0.0);
    complex<float> C(cos(2*a),0.0);
    complex<float> S(sin(2*a),0.0);
    complex<float> x(0.5f,0.0);
    A11 = x*one; A12 = x*C; A13 = x*S; A14 = zero;
    A21 = x*C; A22 = x*C*C; A23 = x*S*C; A24 = zero;
    A31 = x*S; A32 = x*S*C; A33 = x*S*S; A34 = zero;
    A41 = zero; A42 = zero; A43 = zero; A44 = zero;
}
