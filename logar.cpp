#include "logar.h"
#include "linear.h"
#include <cmath>

const float mu = 0.3;

float logar() {
    float x;

    x = -mu * std::log(linear());

    return x;
}