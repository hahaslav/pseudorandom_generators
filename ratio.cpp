#include "ratio.h"
#include "linear.h"
#include "fibonacci.h"
#include <cmath>

const float root = std::sqrt(8 / std::exp(1));

bool upper_check(float x, float u) {
    return x * x <= 5 - 4 * std::exp(0.25) * u;
}

bool lower_check(float x, float u) {
    return x * x >= 4 * std::exp(-1.35) / u + 1.4;
}

bool final_check(float x, float u) {
    return x * x > -4 * std::log(u);
}

float ratio() {
    float x, u;

    do {
        float v;

        do {
            u = linear();
        } while (u == 0);
        v = fibonacci();

        x = root * (v - 0.5) / u;

        if (upper_check(x, u)) return x;

    } while (lower_check(x, u) || final_check(x, u));

    return x;
}