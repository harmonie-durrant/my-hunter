/*
** EPITECH PROJECT, 2022
** Main (Workspace)
** File description:
** init.c
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_hunter_struct.h"
#include "my_hunter_macros.h"
#include "my_printf.h"

int save_highscore(struct game_vars *game_vars)
{
    game_vars->high_score = game_vars->score;
    int fd = open("highscore.txt", O_CREAT | O_RDWR, 0777);
    if (fd < 0) return 84;
    write(fd, game_vars->score, my_strlen(game_vars->score));
    close(fd);
    return 0;
}

int get_highscore(struct game_vars *game_vars)
{
    ssize_t red = 0;
    game_vars->high_score = "000000";
    int ct = 0;
    int add = 0;
    char *buf = malloc(sizeof(char) * 7);
    int fd = open("highscore.txt", O_CREAT | O_RDWR, 0777);
    if (fd < 0) return 84;
    red = read(fd, buf, 6);
    if (red >= 6)
        game_vars->high_score = buf;
    close(fd);
    return 0;
}

int reset_score(struct game_vars *game_vars)
{
    if (my_atoi(game_vars->score) > my_atoi(game_vars->high_score))
        if (save_highscore(game_vars) == 84) return 84;
    game_vars->score = "000000";
    game_vars->lives = 3;
    game_vars->current_menu = 0;
    return 0;
}
