/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** task03
*/

#include "../../include/my_printf.h"

int	my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
