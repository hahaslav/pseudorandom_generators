#include "arens.h"
#include "linear.h"
#include <cmath>

const float PI = 3.141592653589793;
const float A = 0.7;

bool check(float x, float y) {
    float v = linear();
    float e = (1 + y * y) * std::exp((A - 1) * std::log(x / (A - 1)) - std::sqrt(2 * A - 1) * y);
    return v > e;
}

float arens() {
    float x, y;

    do {
        y = std::tan(PI * linear());
        x = std::sqrt(2 * A - 1) * y + A - 1;
    } while (x <= 0 || check(x, y));

    return x;
}