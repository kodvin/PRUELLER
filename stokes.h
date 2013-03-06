#ifndef STOKES_H
#define STOKES_H
#include <commatrix.h>

class Stokes : public comMatrix
{
public:
        Stokes();
 void   populate(complex<float> a11,
                 complex<float> a21,
                 complex<float> a31,
                 complex<float> a41);
};

#endif // STOKES_H
