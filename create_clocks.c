/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** create_clocks.c
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
#include "my_hunter_struct.h"
#include "my_hunter_macros.h"

void create_clocks(struct game_vars *game_vars)
{
    sfClock *anim_clock = sfClock_create();
    sfTime anim_time;
    float anim_seconds;
    sfClock *move_clock = sfClock_create();
    sfTime move_time;
    float move_seconds;

    game_vars->anim_clock = anim_clock;
    game_vars->anim_seconds = anim_seconds;
    game_vars->anim_time = anim_time;
    game_vars->move_clock = move_clock;
    game_vars->move_seconds = move_seconds;
    game_vars->move_time = move_time;
}
