#include <stdio.h>
#include <math.h>
#include <time.h>
#include "funcs.h"

double func(double x) {
    return pow(x/100 - 5, 5)
            - pow(x/50 + 10, 4)
            - pow(x/25 - 15, 3)
            - (x * x) - 10;
}

double dfunc(double x) {
    return 0.05 * pow(x/100 - 5, 4)
         - 0.08 * pow(x/50 + 10, 3)
         - 0.12 * pow(x/25 - 15, 2)
         - 2 * x;
}

void bisectionMethod(double a, double b, double eps, int debug, int step_limit) {
    double x = a, x_prev = b;
    int iter = 0;
    int current_limit = step_limit;
    int no_limit = 0;
    int action;

    clock_t start_time = clock();

    while (1) {
        iter++;
        x_prev = x;
        x = (a + b) / 2.0;

        if (debug == 1) {
            printf("iter %d: x = %lf, f(x) = %lf\n", iter, x, func(x));
        }

        if (fabs(x - x_prev) <= eps || fabs(b - a) <= eps || fabs(func(x)) <= eps) {
            clock_t end_time = clock();
            double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

            printf("\n--- root found (bisection) ---\n");
            printf("root x = %lf\n", x);
            printf("f(x) = %lf\n", func(x));
            printf("iterations = %d\n", iter);
            printf("time = %lf sec\n", time_spent);
            break;
        }

        if (func(a) * func(x) < 0) {
            b = x;
        } else {
            a = x;
        }

        if (!no_limit && iter >= current_limit) {
            printf("\nlimit of %d iterations reached\n", current_limit);
            printf("current res: x = %lf, f(x) = %lf\n", x, func(x));
            printf("1 - continue (+%d iterations)\n", step_limit);
            printf("2 - run until the end (no limit)\n");
            printf("3 - exit program\n");
            printf("your choice: ");
            scanf("%d", &action);

            if (action == 1) {
                current_limit += step_limit;
            } else if (action == 2) {
                no_limit = 1;
            } else {
                printf("\nexiting. intermediate x = %lf, f(x) = %lf\n", x, func(x));
                break;
            }
        }
    }
}

void chordMethod(double a, double b, double eps, int debug, int step_limit) {
    double x = a, x_prev = b;
    int iter = 0;
    int current_limit = step_limit;
    int no_limit = 0;
    int action;

    clock_t start_time = clock();

    while (1) {
        iter++;
        x_prev = x;
        x = a - func(a) * (b - a) / (func(b) - func(a));

        if (debug == 1) {
            printf("iter %d: x = %lf, f(x) = %lf\n", iter, x, func(x));
        }

        if (fabs(x - x_prev) <= eps || fabs(func(x)) <= eps) {
            clock_t end_time = clock();
            double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

            printf("\n--- root found (chord) ---\n");
            printf("root x = %lf\n", x);
            printf("f(x) = %lf\n", func(x));
            printf("iterations = %d\n", iter);
            printf("time = %lf sec\n", time_spent);
            break;
        }

        if (func(a) * func(x) < 0) {
            b = x;
        } else {
            a = x;
        }

        if (!no_limit && iter >= current_limit) {
            printf("\nlimit of %d iterations reached\n", current_limit);
            printf("current res: x = %lf, f(x) = %lf\n", x, func(x));
            printf("1 - continue (+%d iterations)\n", step_limit);
            printf("2 - run until the end (no limit)\n");
            printf("3 - exit program\n");
            printf("your choice: ");
            scanf("%d", &action);

            if (action == 1) {
                current_limit += step_limit;
            } else if (action == 2) {
                no_limit = 1;
            } else {
                printf("\nexiting. intermediate x = %lf, f(x) = %lf\n", x, func(x));
                break;
            }
        }
    }
}