/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** string concatonation
*/

#include "../../include/my_printf.h"
#include <stdlib.h>

char *my_strcat(char *a, char *b)
{
    char *p;
    char *q;
    char *out;

    out = q = malloc(my_strlen(a) + my_strlen(b) + 1);
    for (p = a; (*q = *p) != '\0'; ++p)
        ++q;
    for (p = b; (*q = *p) != '\0'; ++p)
        ++q;
    return out;
}
