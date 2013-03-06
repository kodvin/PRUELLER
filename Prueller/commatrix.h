#ifndef COMMATRIX_H
#define COMMATRIX_H
#include <complex>

using namespace std;
class comMatrix
{
  protected:
    complex<float> A11,A12,A13,A14,
                 A21,A22,A23,A24,
                 A31,A32,A33,A34,
                 A41,A42,A43,A44;
 void initialize();
 virtual void recalc(float angle);
public:
    comMatrix();
    comMatrix multiply(comMatrix b);
    comMatrix
    operator*(const comMatrix& cM){return this->multiply(cM);}

    comMatrix substract(comMatrix b);
    comMatrix
    operator-(const comMatrix& cM){return this->substract(cM);}
    void setM(complex<float>* K);
    void getM(complex<float>*);

    complex<float> getA11(){return A11;}
    complex<float> getA12(){return A12;}
    complex<float> getA13(){return A13;}
    complex<float> getA14(){return A14;}
    complex<float> getA21(){return A21;}
    complex<float> getA22(){return A22;}
    complex<float> getA23(){return A23;}
    complex<float> getA24(){return A24;}
    complex<float> getA31(){return A31;}
    complex<float> getA32(){return A32;}
    complex<float> getA33(){return A33;}
    complex<float> getA34(){return A34;}
    complex<float> getA41(){return A41;}
    complex<float> getA42(){return A42;}
    complex<float> getA43(){return A43;}
    complex<float> getA44(){return A44;}
    float intensity();
};

#endif // COMMATRIX_H
