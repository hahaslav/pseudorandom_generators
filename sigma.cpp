#include "sigma.h"
#include "linear.h"

const int M = 0;
const int TO_SUM = 12;
const int SIX = 6;
const int DISPERCION = 1;

float sigma() {
    int i;
    float sum = 0;

    for (i = 0; i < TO_SUM; i++) {
        sum += linear();
    }

    return M + (sum - SIX) * DISPERCION;
}