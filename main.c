/*
** EPITECH PROJECT, 2022
** CSFML_bs
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my_hunter_struct.h"
#include "my_hunter_macros.h"
#include "my_printf.h"

int game_loop(struct game_vars *, struct duck_vars *);

int start_game(void);

int print_help(void)
{
    my_printf("Usage:./my_hunter\n");
    my_printf("Inputs:\n");
    my_printf("    mouse: left click to kill a duck\n");
    return 0;
}

int main(int ac, char *av[])
{
    if (ac == 1)
        return start_game();
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return print_help();
    else {
        write(2, "Bad option\n", 12);
        return 84;
    }
}
