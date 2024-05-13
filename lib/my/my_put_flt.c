/*
** EPITECH PROJECT, 2022
** Main (Workspace)
** File description:
** my_put_flt
*/

#include <stdio.h>
#include "../../include/my_printf.h"

void print_flt(long decimal, int j, long temp, int *counter)
{
    int k = 1;

    while (j - count_char_nbr(decimal) + k != 0) {
        if (j - count_char_nbr(decimal) < 0) {
            decimal /= 10;
        } else {
            my_putchar('0');
            *counter++;
            k--;
        }
    }
    *counter += count_char_nbr(decimal);
    my_put_nbr(decimal);
}

void treat_zero(int decimal, int j, long temp, int *counter)
{
    if (decimal % 10 >= 5) {
        decimal += 10;
    }
    decimal /= 10;
    if (decimal == 0) {
        my_putstr("000000");
    } else {
        print_flt(decimal, j, temp, counter);
    }
}

int my_put_flt(double nbr, int j, int *counter)
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
    my_putchar('.');
    *counter += count_char_nbr(whole) + 1;
    treat_zero(decimal, j, temp, counter);
    return 0;
}
