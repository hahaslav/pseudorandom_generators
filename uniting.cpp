#include "uniting.h"
#include "linear.h"
#include "fibonacci.h"

const int M = 45'817;

float uniting() {
    linear();
    fibonacci();

    return (float)((lnr::get_x() - fbn::get_x() + M) % M) / M;
}