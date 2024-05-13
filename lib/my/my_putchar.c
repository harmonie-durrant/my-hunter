/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** print character to console
*/

#include "../../include/my_printf.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
