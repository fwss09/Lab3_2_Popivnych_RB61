#include <math.h>

double func(double x) {
    return pow(x/100 - 5, 5)
            - pow(x/50 + 10, 4)
            - pow(x/25 - 15, 3)
            - (x * x) - 10;
}