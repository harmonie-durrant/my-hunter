/*
** EPITECH PROJECT, 2022
** Main (Workspace)
** File description:
** flag_a
*/

#include "../../include/my_printf.h"
#include <stdarg.h>
#include <stdio.h>

void my_put_sci_g(double num, int cap, int prec, int *count)
{
    int i = 0;

    if (num < 1 && num > -1) {
        my_put_sci_neg(num, cap, prec, count);
        return;
    }
    num = reducenum(num, &i);
    my_put_flt_g(num, 6, count);
    if (cap == 1)
        my_putchar('E');
    else
        my_putchar('e');
    my_putchar('+');
    if (i < 10)
        my_putchar('0');
    my_put_nbr(i);
}

int process_sci(double num, int cap, int *count)
{
    while (!(num < 10 && num > -10)) {
        num = num / 10;
    }
    if (num == 0.0 || (num - (int)num) == 0) {
        my_put_nbr((int)num);
        *count += count_char_nbr((int)num);
        if (cap == 1)
            my_putstr("E+00");
        else
            my_putstr("e+00");
        return 0;
    }
    if (cap == 1) {
        my_put_sci_g(num, 1, 6, count);
        return 0;
    }
    my_put_sci_g(num, 0, 6, count);
    *count += 4;
    return 0;
}

int flag_g(const char *format, int i, va_list args, int *count)
{
    int cap = 0;
    double num = va_arg(args, double);
    double temp = num;

    if (num < 0) {
        num *= -1;
        my_putchar('-');
        *count += 1;
    }
    if (format[i] == 'G')
        cap = 1;
    while (temp < 1000000 && (temp - (int)temp) != 0) {
        temp *= 10;
    }
    if (num >= 1000000) {
        process_sci(num, cap, count);
    } else {
        my_put_flt_g(num, 6, count);
    }
    return 0;
}
