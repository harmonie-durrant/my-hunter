/*
** EPITECH PROJECT, 2022
** Main (Workspace)
** File description:
** destroy
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

void destroy_music(struct game_vars *game_vars, struct duck_vars *duck)
{
    sfMusic_destroy(duck->sfx);
    sfMusic_destroy(game_vars->music);
    sfMusic_destroy(game_vars->go_music);
}

void destroy_sprites(struct game_vars *game_vars, struct duck_vars *duck,
struct menu_vars *menu_vars)
{
    sfSprite_destroy(duck->sprite);
    sfSprite_destroy(game_vars->bg_sprite);
    sfSprite_destroy(game_vars->ms_sprite);
    sfSprite_destroy(game_vars->heart_sprite);
    sfSprite_destroy(game_vars->heart1_sprite);
    sfSprite_destroy(game_vars->heart2_sprite);
    sfSprite_destroy(game_vars->mapp_sprite);
    sfSprite_destroy(game_vars->mapp1_sprite);
    sfSprite_destroy(game_vars->mapp2_sprite);
    sfSprite_destroy(game_vars->score_bg_sprite);
}

void destroy(struct game_vars *game_vars, struct duck_vars *duck,
struct menu_vars *menu_vars)
{
    destroy_music(game_vars, duck);
    destroy_sprites(game_vars, duck, menu_vars);
    sfText_destroy(game_vars->score_txt);
    sfText_destroy(game_vars->score_text);
    sfTexture_destroy(duck->texture);
    sfTexture_destroy(game_vars->bg_texture);
    sfTexture_destroy(game_vars->ms_texture);
    sfTexture_destroy(game_vars->heart_texture);
    sfTexture_destroy(game_vars->heart1_texture);
    sfTexture_destroy(game_vars->heart2_texture);
    sfTexture_destroy(game_vars->mapp_texture);
    sfTexture_destroy(game_vars->mapp1_texture);
    sfTexture_destroy(game_vars->mapp2_texture);
    sfTexture_destroy(game_vars->score_bg_texture);
    sfClock_destroy(game_vars->anim_clock);
    sfClock_destroy(game_vars->move_clock);
    sfRenderWindow_destroy(game_vars->window);
}
