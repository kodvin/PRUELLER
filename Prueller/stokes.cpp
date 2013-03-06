#include "stokes.h"

Stokes::Stokes()
{
}

void Stokes::populate(complex<float> a11, complex<float> a21, complex<float> a31, complex<float> a41)
{
    complex<float> zero(0.0,0.0);
    A11 = a11; A12 = zero; A13 = zero; A14 = zero;
    A21 = a21; A22 = zero; A23 = zero; A24 = zero;
    A31 = a31; A32 = zero; A33 = zero; A34 = zero;
    A41 = a41; A42 = zero; A43 = zero; A44 = zero;
}

