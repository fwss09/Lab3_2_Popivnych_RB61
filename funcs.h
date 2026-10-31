#ifndef LAB3_2_POPIVNYCH_RB61_FUNCS_H
#define LAB3_2_POPIVNYCH_RB61_FUNCS_H

/**
 * @brief обчислює значення нелінійної функції f(x)
 * @param x аргумент функції
 * @return значення функції в точці x
 */
double func(double x);

/**
 * @brief обчислює значення першої похідної функції f'(x)
 * @param x аргумент похідної
 * @return значення похідної в точці x
 */
double dfunc(double x);




/**
 * @brief знаходить корінь рівняння методом половинного ділення
 * @param a ліва межа проміжку ізоляції
 * @param b права межа проміжку ізоляції
 * @param eps точність обчислення
 * @param debug прапорець режиму налагодження
 * @param step_limit ліміт ітерацій до паузи
 */
void bisectionMethod(double a, double b, double eps, int debug, int step_limit);

/**
 * @brief знаходить корінь рівняння методом хорд
 * @param a ліва межа проміжку ізоляції
 * @param b права межа проміжку ізоляції
 * @param eps точність обчислення
 * @param debug прапорець режиму налагодження
 * @param step_limit ліміт ітерацій до паузи
 */
void chordMethod(double a, double b, double eps, int debug, int step_limit);

#endif //LAB3_2_POPIVNYCH_RB61_FUNCS_H