#include <stdio.h>
#include <time.h>
#include "funcs.h"

int main() {
    double a, b, eps;
    int method, debug, max_iter;

    printf("choose mode:\n");
    printf("1 - bisection\n");
    printf("2 - chord\n");
    printf("your choice: ");
    scanf("%d", &method);

    if (method != 1 && method != 2) {
        printf("invalid mode\n");
        return 0;
    }

    printf("enter left boundary a: ");
    scanf("%lf", &a);

    printf("enter right boundary b: ");
    scanf("%lf", &b);

    if (a >= b) {
        printf("a must be < b\n");
        return 0;
    }

    printf("\ncheck interval [%lf, %lf]:\n", a, b);
    printf("f(a) = %lf, f(b) = %lf\n", func(a), func(b));
    printf("f'(a) = %lf, f'(b) = %lf\n", dfunc(a), dfunc(b));

    if (func(a) * func(b) >= 0) {
        printf("f(a) and f(b) must have opposite signs!\n");
        return 0;
    }

    printf("enter eps: ");
    scanf("%lf", &eps);

    if (eps <= 0) {
        printf("eps must be > 0\n");
        return 0;
    }

    printf("enable debug mode [1 - yes, 0 - no]: ");
    scanf("%d", &debug);

    printf("enter iteration limit: ");
    scanf("%d", &max_iter);

    if (max_iter <= 0) {
        printf("max iter must be > 0\n");
        return 0;
    }

    if (method == 1) {
        bisectionMethod(a, b, eps, debug, max_iter);
    } else {
        chordMethod(a, b, eps, debug, max_iter);
    }

    return 0;
}