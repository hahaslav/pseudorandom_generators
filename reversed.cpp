#include "reversed.h"

const int A = 9;
const int X0 = 14;
const int C = 22;
const int P = 18329;
const int M = P + 1;

int inverse(int x) {
    int i = 6;

    while ((x * i) % P != 1 && i < P) i++;

    if (i == P) {
        return 0;
    }
    return i;
}

float reversed() {
    static int x = X0;

    x = (A * inverse(x) + C) % P;

    return (float)x / M;
}