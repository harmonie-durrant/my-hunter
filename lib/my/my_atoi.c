/*
** EPITECH PROJECT, 2022
** Main (Workspace)
** File description:
** my_atoi.c
*/

#include "../../include/my_printf.h"

int my_atoi(char *str)
{
    int out = 0;
    int ct = 0;
    for (int i = my_strlen(str) - 1; i >= 0; i--) {
        out += my_compute_power_rec(10, ct) * (str[i] - 48);
        ct++;
    }
    return out;
}
