/*
** EPITECH PROJECT, 2022
** Main (Workspace)
** File description:
** convert
*/

#include "../../include/my_printf.h"

char *convert(unsigned int num, int base, int cap)
{
    if (num == 0)
        return "0";
    char Representation[17];
    if (cap == 0) {
        my_strcpy(Representation, "0123456789abcdef");
    } else {
        my_strcpy(Representation, "0123456789ABCDEF");
    }
    static char buffer[50];
    char *ptr;
    ptr = &buffer[49];
    *ptr = '\0';
    while (num != 0) {
        *--ptr = Representation[num % base];
        num = num / base;
    }
    return (ptr);
}

int reducenum(int num, int *i)
{
    while (!(num < 10 && num > -10)) {
        num = num / 10;
        *i += 1;
    }
    return num;
}

void my_put_sci(double num, int cap, int prec, int *count)
{
    int i = 0;

    if (num < 1 && num > -1) {
        my_put_sci_neg(num, cap, prec, count);
        return;
    }
    num = reducenum(num, &i);
    my_put_flt(num, 6, count);
    if (cap == 1)
        my_putchar('E');
    else
        my_putchar('e');
    my_putchar('+');
    if (i < 10)
        my_putchar('0');
    my_put_nbr(i);
}

void my_put_sci_neg(double num, int cap, int prec, int *count)
{
    int i = 0;

    while (num < 1 && num > -1) {
        num = num * 10;
        i++;
    }
    my_put_flt(num, 6, count);
    if (cap == 1)
        my_putchar('E');
    else
        my_putchar('e');
    my_putchar('-');
    if (i < 10)
        my_putchar('0');
    my_put_nbr(i);
}
