/*
** EPITECH PROJECT, 2022
** Main (Workspace)
** File description:
** flag_g_functions
*/

#include "../../include/my_printf.h"
#include <stdarg.h>
#include <stdio.h>

void print_flt_g(long decimal, int j, long temp, int *counter)
{
    while (decimal % 10 == 0) {
        decimal = decimal / 10;
    }
    my_put_nbr(decimal);
}

void treat_zero_g(int decimal, int j, long temp, int *counter)
{
    if (decimal % 10 >= 5) {
        decimal += 10;
    }
    decimal /= 10;
    if (decimal == 0) {
        return;
    } else {
        my_putchar('.');
        print_flt_g(decimal, j, temp, counter);
    }
}

int my_put_flt_g(double nbr, int j, int *counter)
{
    int whole = (int)nbr;
    long decimal = (long)((nbr - whole) * my_compute_power_rec(10, j + 1));
    long temp = decimal;

    if (decimal < 0) {
        decimal = decimal * (-1);
        temp = temp * (-1);
    }
    if (nbr < 0 && nbr > -1) {
        my_putchar('-');
        *counter += 1;
    }
    j--;
    my_put_nbr(whole);
    *counter += count_char_nbr(whole);
    treat_zero_g(decimal, j, temp, counter);
    return 0;
}
