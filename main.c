#include <stdio.h>
#include <time.h>
#include "funcs.h"

/**
 * @file main.c
 * @brief головний файл програми для вибору методу та введення початкових даних
 */

/**
 * @brief головна функція програми
 * @return 0 при успішному завершенні програми
 */
int main() {
    // оголошення змінних для меж проміжку a, b та точності обчислення eps
    double a, b, eps;

    // змінні для вибору методу, режиму налагодження та ліміту ітерацій
    int method, debug, max_iter;

    // виведення текстового меню для вибору методу розв'язання
    printf("choose mode:\n");
    printf("1 - bisection\n");
    printf("2 - chord\n");
    printf("your choice: ");
    scanf("%d", &method);

    // перевірка коректності обраного методу
    if (method != 1 && method != 2) {
        printf("invalid mode\n");
        return 0;
    }

    // введення лівої та правої меж проміжку ізоляції
    printf("enter left boundary a: ");
    scanf("%lf", &a);

    printf("enter right boundary b: ");
    scanf("%lf", &b);


    // перевірка щоб ліва межа була меншою за праву
    if (a >= b) {
        printf("a must be < b\n");
        return 0;
    }

    // виведення значень функції та її похідної
    printf("\ncheck interval [%lf, %lf]:\n", a, b);
    printf("f(a) = %lf, f(b) = %lf\n", func(a), func(b));
    printf("f'(a) = %lf, f'(b) = %lf\n", dfunc(a), dfunc(b));

    // перевірка умови
    if (func(a) * func(b) >= 0) {
        printf("f(a) and f(b) must have opposite signs!\n");
        return 0;
    }

    // введення точності обчислень eps
    printf("enter eps: ");
    scanf("%lf", &eps);

    // перевірка точності обчислень eps
    if (eps <= 0) {
        printf("eps must be > 0\n");
        return 0;
    }

    // запит на увімкнення режиму налагодження
    printf("enable debug mode [1 - yes, 0 - no]: ");
    scanf("%d", &debug);

    // введення ліміту ітерацій
    printf("enter iteration limit: ");
    scanf("%d", &max_iter);

    // перевірка ліміту ітерацій
    if (max_iter <= 0) {
        printf("max iter must be > 0\n");
        return 0;
    }

    // виклик відповідної функції залежно від вибору користувача
    if (method == 1) {
        bisectionMethod(a, b, eps, debug, max_iter);
    } else {
        chordMethod(a, b, eps, debug, max_iter);
    }

    return 0;
}