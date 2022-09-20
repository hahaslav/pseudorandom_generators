#include "fibonacci.h"

namespace fbn {
    int full_x;
}

const int X0 = 21'573;
const int X1 = 36'444;
const int M = 37'951;

float fibonacci() {
    static int x_minus_1 = X0;
    static int x = X1;

    int x_new = (x_minus_1 + x) % M;
    x_minus_1 = x;
    x = x_new;

    fbn::full_x = x;
    return (float)x / M;
}

int fbn::get_x() {
    /*
     * Returns value of X, not divided by M
     */
    return fbn::full_x;
}
