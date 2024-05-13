/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** flags_21-25.c
*/

#include "../../include/my_printf.h"
#include <stdarg.h>

void flag_bigs(char *str, int *count)
{
    int nb = 0;
    char *temp = convert(str[nb], 8, 0);
    for (nb = 0; str[nb] != '\0'; nb++) {
        if (str[nb] < 32 || str[nb] >= 127)
            my_putchar('\\');
        if (str[nb] < 32)
            my_putchar('0');
        if (str[nb] < 8)
            my_putchar('0');
        if (str[nb] < 32 || str[nb] >= 127) {
            my_putstr(convert(str[nb], 8, 0));
            *count += 4;
        } else {
            my_putchar(str[nb]);
            *count += 1;
        }
    }
}

int flag_s(const char *format, int i, va_list args, int *count)
{
    char *str;
    str = va_arg(args, char *);
    if (format[i - 1] == 'S') {
        flag_bigs(str, count);
        return 0;
    }
    my_putstr(str);
    *count += my_strlen(str);
    return 0;
}

int flag_p(const char *format, int i, va_list args, int *count)
{
    int nb = va_arg(args, int);
    my_putchar('0');
    my_putchar('x');
    if (nb < 0) {
        nb = -nb;
    }
    *count += my_strlen(convert(nb, 16, 0));
    my_putstr(convert(nb, 16, 0));
    return 0;
}
