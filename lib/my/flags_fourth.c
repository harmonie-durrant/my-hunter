/*
** EPITECH PROJECT, 2022
** My_printf
** File description:
** flags_16-20
*/

#include <stdio.h>
#include <stdarg.h>
#include "../../include/my_printf.h"

int flag_f(const char *format, int i, va_list args, int *count)
{
    my_put_flt(va_arg(args, double), 6, count);
    return 0;
}

int flag_a(const char *format, int i, va_list args, int *count)
{
    int str = va_arg(args, int);

    *count += my_strlen(convert(str, 16, 0));
    *count += 2;
    if (format[i - 1] == 'A') {
        my_putchar('0');
        my_putchar('x');
        my_putstr(convert(str, 16, 1));
        return 0;
    }
    my_putchar('0');
    my_putchar('x');
    my_putstr(convert(str, 16, 0));
    return 0;
}

int flag_c(const char *format, int i, va_list args, int *count)
{
    my_putchar(va_arg(args, int));
    count += 1;
    return 0;
}
