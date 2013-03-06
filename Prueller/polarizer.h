#ifndef POLARIZER_H
#define POLARIZER_H
#include <commatrix.h>
class polarizer : public comMatrix
{
    float a;//angle of the poliarization axis
public:
    polarizer(float angle){a =angle;}
    void recalc();
    void setAngle(float angle) {a = angle;}
};

#endif // POLARIZER_H
