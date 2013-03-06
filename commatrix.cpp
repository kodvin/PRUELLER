#include "commatrix.h"
#include <iostream>

comMatrix::comMatrix()
{
    initialize();
}

void comMatrix::initialize()
{
    complex<float> zero(0.0,0.0);
    A11 = zero; A12 = zero; A13 = zero; A14 = zero;
    A21 = zero; A22 = zero; A23 = zero; A24 = zero;
    A31 = zero; A32 = zero; A33 = zero; A34 = zero;
    A41 = zero; A42 = zero; A43 = zero; A44 = zero;
}
//matix multiplication R - result, a first matrix b second matrix. so the R =a*b;
//you use this method with a and multiply by b.
comMatrix comMatrix::multiply( comMatrix b)
{
    comMatrix R;
    R.A11 = A11*b.A11 + A12*b.A21 + A13*b.A31 + A14*b.A41;
    R.A12 = A11*b.A12 + A12*b.A22 + A13*b.A32 + A14*b.A42;
    R.A13 = A11*b.A13 + A12*b.A23 + A13*b.A33 + A14*b.A43;
    R.A14 = A11*b.A14 + A12*b.A24 + A13*b.A34 + A14*b.A44;

    R.A21 = A21*b.A11 + A22*b.A21 + A23*b.A31 + A24*b.A41;
    R.A22 = A21*b.A12 + A22*b.A22 + A23*b.A32 + A24*b.A42;
    R.A23 = A21*b.A13 + A22*b.A23 + A23*b.A33 + A24*b.A43;
    R.A24 = A21*b.A14 + A22*b.A24 + A23*b.A34 + A24*b.A44;

    R.A31 = A31*b.A11 + A32*b.A21 + A33*b.A31 + A34*b.A41;
    R.A32 = A31*b.A12 + A32*b.A22 + A33*b.A32 + A34*b.A42;
    R.A33 = A31*b.A13 + A32*b.A23 + A33*b.A33 + A34*b.A43;
    R.A34 = A31*b.A14 + A32*b.A24 + A33*b.A34 + A34*b.A44;

    R.A41 = A41*b.A11 + A42*b.A21 + A43*b.A31 + A44*b.A41;
    R.A42 = A41*b.A12 + A42*b.A22 + A43*b.A32 + A44*b.A42;
    R.A43 = A41*b.A13 + A42*b.A23 + A43*b.A33 + A44*b.A43;
    R.A44 = A41*b.A14 + A42*b.A24 + A43*b.A34 + A44*b.A44;

    return R;
}

comMatrix comMatrix::substract(comMatrix b)
{
    comMatrix R;
    R.A11 = A11 - b.A11;
    R.A12 = A12 - b.A12;
    R.A13 = A13 - b.A13;
    R.A14 = A14 - b.A14;

    R.A21 = A21 - b.A21;
    R.A22 = A22 - b.A22;
    R.A23 = A23 - b.A23;
    R.A24 = A24 - b.A24;

    R.A31 = A31 - b.A31;
    R.A32 = A32 - b.A32;
    R.A33 = A33 - b.A33;
    R.A34 = A34 - b.A34;

    R.A41 = A41 - b.A41;
    R.A42 = A42 - b.A42;
    R.A43 = A43 - b.A43;
    R.A44 = A44 - b.A44;


    return R;
}

void comMatrix::setM(complex<float> *K)
{
    A11 = K[0];  A12 = K[1];  A13 = K[2];  A14 = K[3];
    A21 = K[4];  A22 = K[5];  A23 = K[6];  A24 = K[7];
    A31 = K[8];  A32 = K[9];  A33 = K[10]; A34 = K[11];
    A41 = K[12]; A42 = K[13]; A43 = K[14]; A44 = K[15];
 }
//sita funkcija neveikia reikia psirziureti kazkas negerai, grazintas pointer turi tik nuliukus

void comMatrix::getM(complex<float> *K)
{
        *(K+0) = A11;  *(K+1) = A12;  *(K+2) = A13;  *(K+3) = A14;
        *(K+4) = A21;  *(K+5) = A22; *(K+6) = A23;  *(K+7) = A24;
        *(K+8) = A31;  *(K+9) = A32;  *(K+10) = A33; *(K+11) = A34;
        *(K+12) = A41; *(K+13) = A42; *(K+14) = A43; *(K+15) = A44;
}

float comMatrix::intensity()
{
    float I =abs((A11*A11 + A21*A21 + A31*A31 + A41*A41)) ;
    return (I/2);
}

void comMatrix::recalc(float angle)
{
}
