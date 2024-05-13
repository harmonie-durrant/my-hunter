/*
** EPITECH PROJECT, 2022
** Main (Workspace)
** File description:
** flags_6-10
*/

#include <stdio.h>
#include "../../include/my_printf.h"
#include <stdarg.h>

int flag_di(const char *format, int i, va_list args, int *count)
{
    int nb = 0;
    nb = va_arg(args, int);

    my_put_nbr(nb);
    *count += count_char_nbr(nb);
    return 0;
}

int flag_o(const char *format, int i, va_list args, int *count)
{
    char *str;
    str = convert(va_arg(args, int), 8, 0);

    my_putstr(str);
    *count += my_strlen(str);
    return 0;
}

int flag_x(const char *format, int i, va_list args, int *count)
{
    char *str;

    if (format[i - 1] == 'X') {
        str = convert(va_arg(args, int), 16, 1);
        my_putstr(str);
        return 0;
    }
        str = convert(va_arg(args, int), 16, 0);
    *count += my_strlen(str);
    my_putstr(str);
    return 0;
}

int flag_e(const char *format, int i, va_list args, int *count)
{
    double arg = va_arg(args, double);
    if (arg == 0) {
        my_put_flt(0.0, 6, count);
        if (format[i - 1] == 'E')
            my_putstr("E+00");
        else
            my_putstr("e+00");
        return 0;
    }
    if (format[i - 1] == 'E') {
        my_put_sci(arg, 1, 6, count);
        return 0;
    }
    my_put_sci(arg, 0, 6, count);
    *count += 4;
    return 0;
}
