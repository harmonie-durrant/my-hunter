/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** main file for my_printf project
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../include/my_printf.h"
#include "../../include/my_printf_struct.h"

static int process_cases(const char *format, int i, va_list args, int *ptr)
{
    int test = 0;
    const struct pro_cases pro_tab[] = {
        {'c', flag_c}, {'p', flag_p}, {'s', flag_s}, {'n', flag_n},
        {'b', flag_b}, {'o', flag_o}, {'d', flag_di}, {'i', flag_di},
        {'u', flag_u}, {'A', flag_a}, {'a', flag_a}, {'f', flag_f},
        {'F', flag_f}, {'x', flag_x}, {'X', flag_x}, {'P', flag_p},
        {'e', flag_e}, {'E', flag_e}, {'S', flag_s}, {'g', flag_g},
        {'G', flag_g},
    };

    if (format[i] == '%') {
        my_putchar('%');
        *ptr++;
        return 0;
    }
    for (int j = 0; j < 21; j++) {
        if (format[i] == pro_tab[j].flag)
            test = pro_tab[j].ptr(format, i + 1, args, ptr);
    }
    return test;
}

int my_printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int *ptr = &count;

    va_start(args, format);
    for (int i = 0; i < my_strlen(format); i++) {
        if (format[i] == '%') {
            i += process_cases(format, i + 1, args, &count);
            i++;
            continue;
        }
        my_putchar(format[i]);
        count++;
    }
    va_end(args);
    return count;
}
