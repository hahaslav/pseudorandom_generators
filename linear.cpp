#include "linear.h"

namespace lnr {
    int full_x;
}

const int A = 3;
const int X0 = 10;
const int C = 45'127;
const int M = 12'143;

float linear() {
    static int x = X0;

    x = (A * x + C) % M;

    lnr::full_x = x;
    return (float)x / M;
}

int lnr::get_x() {
    /*
     * Returns value of X, not divided by M
     */
    return lnr::full_x;
}