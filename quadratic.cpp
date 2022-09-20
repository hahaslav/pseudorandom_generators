#include "quadratic.h"

const int D = 4;
const int X0 = 6;
const int A = 0;
const int C = 0;
const int M = 22'109;

float quadratic() {
    static int x = X0;

    x = (D * x * x + A * x + C) % M;

    return (float)x / M ;
}