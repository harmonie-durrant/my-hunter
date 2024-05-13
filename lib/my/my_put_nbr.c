/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** print int to screen
*/

#include "../../include/my_printf.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb == -2147483648) {
        my_putstr("2147483648");
    } else if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return (0);
}
