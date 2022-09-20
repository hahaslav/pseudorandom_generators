#include <iostream>
#include "linear.h"
#include "quadratic.h"
#include "fibonacci.h"
#include "reversed.h"
#include "uniting.h"
#include "sigma.h"
#include "polar.h"
#include "ratio.h"
#include "logar.h"
#include "arens.h"

const int NUMBERS_TO_GEN = 1002;
const int COUNTERS = 10;
const int HISTOGRAM_HAS_NEGATIVE = 1;
const int HISTOGRAM_HAS_NOT_NEGATIVE = 0;
const int HISTOGRAM_RANGE[] = {1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1};

void method_prompt() {
    /*
     * Shows the list of the methods
     */
    std::cout << "Select a method for generating quasirandom numbers:\n";
    std::cout << " 1. Linear congruential method.\n";
    std::cout << " 2. Quadratic congruential method.\n";
    std::cout << " 3. Fibonacci numbers.\n";
    std::cout << " 4. Reversed congruential method.\n";
    std::cout << " 5. Uniting method.\n";
    std::cout << " 6. 3-sigma.\n";
    std::cout << " 7. Polar coordinates method.\n";
    std::cout << " 8. Ratio method.\n";
    std::cout << " 9. Logarithmic method.\n";
    std::cout << "10. Gamma distribution method.\n";
    std::cout << "\nInput the number of the method:\n";
}

int input() {
    /*
     * Returns the number of the method from cin
     */
    int method_number;
    std::cin >> method_number;
    return method_number;
}

void unimplemented(int method_number) {
    /*
     * Says that user asked for an unimplemented method
     */
    std::cout << "Method " << method_number << " is unimplemented!";
}

void print_with_precision(float n, float precision) {
    /*
     * Prints float with given precision
     *
     * CAUTION!
     * Sets this precision for the next couts!
     */
    std::cout.setf(std::ios::fixed);
    std::cout.precision(precision);
    std::cout << n;
}

int main() {
    int method_number, i, histogram_period_precision, histogram_negative, histogram_numbers = NUMBERS_TO_GEN;
    float histogram_period, generated_number;
    int histogram_counters[COUNTERS];
    for (i = 0; i < COUNTERS; i++) {
        histogram_counters[i] = 0;
    }

    // select method
    method_prompt();
    method_number = input();

    // setup histogram params
    switch (HISTOGRAM_RANGE[method_number]) {
        case 1: {
            histogram_negative = HISTOGRAM_HAS_NOT_NEGATIVE;
            histogram_period_precision = 1;
            break;
        }
        case 3: {
            histogram_negative = HISTOGRAM_HAS_NEGATIVE;
            histogram_period_precision = 1;
            break;
        }
    }
    histogram_period = (float)HISTOGRAM_RANGE[method_number] / COUNTERS;
    if (histogram_negative != 0) histogram_period *= 2 * histogram_negative;

    for (i = 0; i < NUMBERS_TO_GEN; i++) {
        // generate number
        switch (method_number) {
            case 1: {
                generated_number = linear();
                break;
            }
            case 2: {
                generated_number = quadratic();
                break;
            }
            case 3: {
                generated_number = fibonacci();
                break;
            }
            case 4: {
                generated_number = reversed();
                break;
            }
            case 5: {
                generated_number = uniting();
                break;
            }
            case 6: {
                generated_number = sigma();
                break;
            }
            case 7: {
                generated_number = polar();
                break;
            }
            case 8: {
                generated_number = ratio();
                break;
            }
            case 9: {
                generated_number = logar();
                break;
            }
            case 10: {
                generated_number = arens();
                break;
            }
            default: {
                unimplemented(method_number);
                exit(0);
            }
        }

        // count number in the histogram
        if (histogram_negative == HISTOGRAM_HAS_NEGATIVE) {
            generated_number += HISTOGRAM_RANGE[method_number];
        }
        if (0 <= generated_number && generated_number <= histogram_period * COUNTERS) {
            histogram_counters[(int) (generated_number / histogram_period)]++;
        } else {
            histogram_numbers--;
        }
    }
    
    // show histogram
    std::cout << "\n";
    for (i = 0; i < COUNTERS; i++) {
        std::cout << '[';
        print_with_precision(histogram_period * i - (histogram_negative * HISTOGRAM_RANGE[method_number]), histogram_period_precision);
        std::cout << ";\t";
        print_with_precision(histogram_period * (i + 1) - (histogram_negative * HISTOGRAM_RANGE[method_number]), histogram_period_precision);
        std::cout << "]\t";
        print_with_precision((float)histogram_counters[i] / histogram_numbers, 2);
        std::cout << "\n";
    }

    return 0;
}
