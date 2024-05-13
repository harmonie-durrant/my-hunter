/*
** EPITECH PROJECT, 2022
** Main (Workspace)
** File description:
** flags_11-15
*/

#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include "../../include/my_printf.h"

int flag_n(const char *format, int i, va_list args, int *count)
{
    int *ptr = va_arg(args, int *);
    *ptr = *count;
    return 0;
}

int flag_b(const char *format, int i, va_list args, int *count)
{
    int str = va_arg(args, int);

    my_putstr(convert(str, 2, 0));
    *count += my_strlen(convert(str, 2, 0));
    return 0;
}

int flag_u(const char *format, int i, va_list args, int *count)
{
    unsigned int nb = va_arg(args, unsigned int);
    if (nb < 0)
        nb = 4294967295 + nb;
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    *count += count_char_uns(nb);
    return 0;
}
