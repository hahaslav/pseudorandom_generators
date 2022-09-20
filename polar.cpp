#include "polar.h"
#include "linear.h"
#include "fibonacci.h"
#include <cmath>

float transformation(float u) {
    /*
     * Returns V = 2U - 1
     */
    return 2 * u - 1;
}

float polar() {
    static float x1 = 0;
    static float x2 = 0;
    static bool second_number = false;

    if (second_number) {
        second_number = false;
        return x2;
    }

    float s, v1, v2;

    do {
        float u1 = linear();
        float u2 = fibonacci();
        v1 = transformation(u1);
        v2 = transformation(u2);

        s = v1 * v1 + v2 * v2;
    } while (s >= 1);

    float root = std::sqrt((-2 * std::log(s)) / s);
    x1 = v1 * root;
    x2 = v2 * root;

    second_number = true;
    return x1;
}