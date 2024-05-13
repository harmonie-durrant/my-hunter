/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** hearts.c
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
#include "my_printf.h"

int create_hearts_thid(struct game_vars *game_vars)
{
    sfVector2f heart2_scale = {0.1, 0.1};
    game_vars->heart2_texture = CreText("./assets/heart.png", NULL);
    if (!game_vars->heart2_texture) return 84;
    game_vars->heart2_sprite = sfSprite_create();
    set_txt(game_vars->heart2_sprite, game_vars->heart2_texture, sfTrue);
    sfSprite_setScale(game_vars->heart2_sprite, heart2_scale);
    game_vars->heart2_pos.x = -500;
    game_vars->heart2_pos.y = 200;
}

int create_hearts(struct game_vars *game_vars)
{
    sfVector2f heart_scale = {0.1, 0.1};
    game_vars->heart_texture = CreText("./assets/heart.png", NULL);
    if (!game_vars->heart_texture) return 84;
    game_vars->heart_sprite = sfSprite_create();
    set_txt(game_vars->heart_sprite, game_vars->heart_texture, sfTrue);
    sfSprite_setScale(game_vars->heart_sprite, heart_scale);
    game_vars->heart_pos.x = -500;
    game_vars->heart_pos.y = 200;
    sfVector2f heart1_scale = {0.1, 0.1};
    game_vars->heart1_texture = CreText("./assets/heart.png", NULL);
    if (!game_vars->heart1_texture) return 84;
    game_vars->heart1_sprite = sfSprite_create();
    set_txt(game_vars->heart1_sprite, game_vars->heart1_texture, sfTrue);
    sfSprite_setScale(game_vars->heart1_sprite, heart1_scale);
    game_vars->heart1_pos.x = -500;
    game_vars->heart1_pos.y = 200;
    if (create_hearts_thid(game_vars) == 84) return 84;
}

void draw_hearts(struct game_vars *game_vars)
{
    if (game_vars->lives >= 1)
        game_vars->heart_pos.x = 53;
    else
        game_vars->heart_pos.x = -500;
    sfSprite_setPosition(game_vars->heart_sprite, game_vars->heart_pos);
    if (game_vars->lives >= 2)
        game_vars->heart1_pos.x = 106;
    else
        game_vars->heart1_pos.x = -500;
    sfSprite_setPosition(game_vars->heart1_sprite, game_vars->heart1_pos);
    if (game_vars->lives >= 3)
        game_vars->heart2_pos.x = 159;
    else
        game_vars->heart2_pos.x = -500;
    sfSprite_setPosition(game_vars->heart2_sprite, game_vars->heart2_pos);
    drw_sprite(game_vars->window, game_vars->heart_sprite, NULL);
    drw_sprite(game_vars->window, game_vars->heart1_sprite, NULL);
    drw_sprite(game_vars->window, game_vars->heart2_sprite, NULL);
}
