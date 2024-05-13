/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** create_m_textures.c
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

int changemap(struct game_vars *game_vars, struct menu_vars *menu_vars,
struct duck_vars *duck, int index);

int create_mapp_thid(struct game_vars *game_vars)
{
    sfVector2f mapp2_scale = {0.8, 0.8};
    game_vars->mapp2_texture = CreText("./assets/mapp_3.png", NULL);
    if (!game_vars->mapp2_texture) return 84;
    game_vars->mapp2_sprite = sfSprite_create();
    set_txt(game_vars->mapp2_sprite, game_vars->mapp2_texture, sfTrue);
    sfSprite_setScale(game_vars->mapp2_sprite, mapp2_scale);
    game_vars->mapp2_pos.x = 1110 + 138;
    game_vars->mapp2_pos.y = 200;
    game_vars->mapp_btn_w = 544 * mapp2_scale.x;
    game_vars->mapp_btn_h = 730 * mapp2_scale.y;
}

int create_mapp(struct game_vars *game_vars)
{
    sfVector2f mapp_scale = {0.8, 0.8};
    game_vars->mapp_texture = CreText("./assets/mapp_1.png", NULL);
    if (!game_vars->mapp_texture) return 84;
    game_vars->mapp_sprite = sfSprite_create();
    set_txt(game_vars->mapp_sprite, game_vars->mapp_texture, sfTrue);
    sfSprite_setScale(game_vars->mapp_sprite, mapp_scale);
    game_vars->mapp_pos.x = 138;
    game_vars->mapp_pos.y = 200;
    sfVector2f mapp1_scale = {0.8, 0.8};
    game_vars->mapp1_texture = CreText("./assets/mapp_2.png", NULL);
    if (!game_vars->mapp1_texture) return 84;
    game_vars->mapp1_sprite = sfSprite_create();
    set_txt(game_vars->mapp1_sprite, game_vars->mapp1_texture, sfTrue);
    sfSprite_setScale(game_vars->mapp1_sprite, mapp1_scale);
    game_vars->mapp1_pos.x = 544 + 138;
    game_vars->mapp1_pos.y = 200;
    if (create_mapp_thid(game_vars) == 84) return 84;
}

int handle_mapp_mouse_click(sfVector2i evt, struct game_vars *g_v,
struct menu_vars *m_v, struct duck_vars *duck)
{
    if (evt.x < g_v->mapp_pos.x + g_v->mapp_btn_w
    && evt.x > g_v->mapp_pos.x && g_v->current_menu == 1)
        if (evt.y < g_v->mapp_pos.y + g_v->mapp_btn_h
        && evt.y > g_v->mapp_pos.y)
            changemap(g_v, m_v, duck, 0);
    if (evt.x < g_v->mapp1_pos.x + g_v->mapp_btn_w
    && evt.x > g_v->mapp1_pos.x && g_v->current_menu == 1)
        if (evt.y < g_v->mapp1_pos.y + g_v->mapp_btn_h
        && evt.y > g_v->mapp1_pos.y)
            changemap(g_v, m_v, duck, 1);
    if (evt.x < g_v->mapp2_pos.x + g_v->mapp_btn_w
    && evt.x > g_v->mapp2_pos.x && g_v->current_menu == 1)
        if (evt.y < g_v->mapp2_pos.y + g_v->mapp_btn_h
        && evt.y > g_v->mapp2_pos.y)
            changemap(g_v, m_v, duck, 2);
}
