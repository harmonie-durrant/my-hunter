/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** menu_loops.c
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

void analyse_events(sfEvent event, struct game_vars *game_vars,
struct duck_vars *duck, struct menu_vars *menu_vars);

int handle_mouse_move(sfVector2i evt, struct game_vars *game_vars);

int handle_mapp_mouse_click(sfVector2i evt, struct game_vars *g_v,
struct menu_vars *m_v, struct duck_vars *duck);

int change_music(struct game_vars *game_vars, struct menu_vars *menu_vars,
int index);

int change_sfx(struct duck_vars *duck, struct game_vars *game_vars, int index);

int main_menu_loop(sfEvent event, struct game_vars *game_vars,
struct menu_vars *menu_vars, struct duck_vars *duck)
{
    char *hs_tmp = "High Score: ";
    char *hs_str = my_strcat(hs_tmp, game_vars->high_score);
    sfText_setString(menu_vars->hs_text, hs_str);
    drw_txt(game_vars->window, menu_vars->hs_text, NULL);
    drw_sprite(game_vars->window, menu_vars->start_sprite, NULL);
    drw_sprite(game_vars->window, menu_vars->mapbtn_sprite, NULL);
}

int update_map(struct game_vars *game_vars, int index,
struct duck_vars *duck)
{
    if (index == 0) {
        duck->anim_speed = 0.12;
        duck->maxw = 220;
        duck->scale = 1.0;
    } else if (index == 1) {
        duck->anim_speed = 0.05;
        duck->maxw = 3983;
        duck->scale = 0.4;
    } else {
        duck->anim_speed = 0.12;
        duck->maxw = 220;
        duck->scale = 0.6;
    }
    if (!duck->texture || !game_vars->bg_texture) return 84;
    game_vars->bg_sprite = sfSprite_create();
    sfSprite_setTexture(game_vars->bg_sprite, game_vars->bg_texture, sfTrue);
    duck->sprite = sfSprite_create();
    sfSprite_setTexture(duck->sprite, duck->texture, sfTrue);
    game_vars->current_menu = 0;
    sfSprite_setScale(duck->sprite, (sfVector2f){duck->scale, duck->scale});
}

int changemap(struct game_vars *game_vars, struct menu_vars *menu_vars,
struct duck_vars *duck, int index)
{
    if (index == 0) {
        game_vars->bg_texture = CreText("./assets/bg_dh.png", NULL);
        duck->texture = CreText("assets/duck-sheet.png", NULL);
        duck->rect.width = 110;
        duck->rect.height = 110;
    } else if (index == 1) {
        game_vars->bg_texture = CreText("./assets/bg_mc.png", NULL);
        duck->texture = CreText("assets/chicken-sheet.png", NULL);
        duck->rect.width = 249;
        duck->rect.height = 315;
    } else {
        game_vars->bg_texture = CreText("./assets/bg_cp.png", NULL);
        duck->texture = CreText("assets/drone-sheet.png", NULL);
        duck->rect.width = 330;
        duck->rect.height = 252;
    }
    change_music(game_vars, menu_vars, index);
    change_sfx(duck, game_vars, index);
    return update_map(game_vars, index, duck);
}

int cmap_menu_loop(sfEvent event, struct game_vars *game_vars,
struct menu_vars *menu_vars, struct duck_vars *duck)
{
    setp_sprite(game_vars->mapp_sprite, game_vars->mapp_pos);
    drw_sprite(game_vars->window, game_vars->mapp_sprite, NULL);
    setp_sprite(game_vars->mapp1_sprite, game_vars->mapp1_pos);
    drw_sprite(game_vars->window, game_vars->mapp1_sprite, NULL);
    setp_sprite(game_vars->mapp2_sprite, game_vars->mapp2_pos);
    drw_sprite(game_vars->window, game_vars->mapp2_sprite, NULL);
}

int handle_menu_mouse_click(sfVector2i evt, struct game_vars *g_v,
struct duck_vars *duck, struct menu_vars *m_v)
{
    if (g_v->current_menu == 1)
        return handle_mapp_mouse_click(evt, g_v, m_v, duck);
    if (evt.x < m_v->start_pos.x + (m_v->btn_w * m_v->start_scale.x)
    && evt.x > m_v->start_pos.x && g_v->current_menu == 0)
        if (evt.y < m_v->start_pos.y + (m_v->btn_h * m_v->start_scale.y)
        && evt.y > m_v->start_pos.y)
            g_v->current_menu = 2;
    if (evt.x < m_v->mapbtn_pos.x + (m_v->mapbtn_w * m_v->mapbtn_scale.x)
    && evt.x > m_v->mapbtn_pos.x && g_v->current_menu == 0)
        if (evt.y < m_v->mapbtn_pos.y + (m_v->mapbtn_h * m_v->mapbtn_scale.y)
        && evt.y > m_v->mapbtn_pos.y)
            g_v->current_menu = 1;
    return 0;
}
