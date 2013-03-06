#include "abstractretarder.h"

void abstractRetarder::recalc()
{

    complex<float> zero(0.0,0.0);
    complex<float> one(1.0,0.0);
    complex<float> half(0.5,0.0);
    complex<float> CR4 = cos(4*ro);
    complex<float> CR2 = cos(2*ro);
    complex<float> SR4 = cos(4*ro);
    complex<float> SR2 = cos(2*ro);
    complex<float> SD_2 = sin(delta/2);
    complex<float> CD_2 = cos(delta/2);
    complex<float> SD = sin(delta);
    complex<float> CD = cos(delta);

    complex<float> G = half*(one + CD);
    complex<float> H = half*(one - CD);
    A11 = one;  A12 = zero;    A13 = zero;     A14 = zero;
    A21 = zero; A22 = G+H*CR4; A23 = H*SR4;    A24 = -SR2*SD;
    A31 = zero; A32 = H*SR4;   A33 = G - H*CR4;A34 = CR2*SD;
    A41 = zero; A42 = SD*SR2;  A43 = -SD*CR2;  A44 = CD;
}
//void abstractRetarder::recalc()
//{

//    complex<float> zero(0.0,0.0);
//    complex<float> one(1.0,0.0);
//    complex<float> CR4 = cos(4*ro);
//    complex<float> CR2 = cos(2*ro);
//    complex<float> SR4 = cos(4*ro);
//    complex<float> SR2 = cos(2*ro);
//    complex<float> SD_2 = sin(delta/2);
//    complex<float> CD_2 = cos(delta/2);
//    complex<float> SD = sin(delta);
//    complex<float> CD = cos(delta);
//    A11 = one;  A12 = zero;                    A13 = zero;                      A14 = zero;
//    A21 = zero; A22 = CR4*SD_2*SD_2+CD_2*CD_2; A23 = SR4*SD_2*SD_2;             A24 = -SR2*SD;
//    A31 = zero; A32 = SR4*SD_2*SD_2;           A33 = -CR4*SD_2*SD_2+CD_2*CD_2;  A34 = CR2*SD;
//    A41 = zero; A42 = SR2*SD*SD;               A43 = CR2*SD;                    A44 = CD;
//}
