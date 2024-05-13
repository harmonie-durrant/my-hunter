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
#include "my_hunter_struct.h"
#include "my_hunter_macros.h"
#include "my_printf.h"

void analyse_events(sfEvent,
struct game_vars *, struct duck_vars *, struct menu_vars *);

int main_menu_loop(sfEvent, struct game_vars *, struct menu_vars *);

int cmap_menu_loop(sfEvent, struct game_vars *,
struct menu_vars *, struct duck_vars *);

void reset_score(struct game_vars *game_vars);

void draw_hearts(struct game_vars *game_vars);

static void move_rect(struct duck_vars *duck)
{
    duck->rect.left += duck->rect.width;
    if (duck->rect.left > duck->maxw)
        duck->rect.left = 0;
}

static int move_duck(struct game_vars *game_vars,
struct duck_vars *duck, int jump)
{
    duck->pos.x += jump;
    if (duck->pos.x > game_vars->w + duck->rect.width) {
        game_vars->lives -= 1;
        sfMusic_stop(game_vars->go_music);
        sfMusic_play(game_vars->go_music);
        duck->pos.x = (int)((float)rand() / (float)(RAND_MAX));
        duck->pos.x *= (duck->rect.width * -1);
        duck->pos.x -= duck->rect.width;
        duck->pos.y = (float)rand() / (float)RAND_MAX;
            duck->pos.y *= game_vars->h - (duck->rect.height +252);
        duck->pos.y += 252;
    }
    sfSprite_setPosition(duck->sprite, duck->pos);
}

void draw_ents(struct game_vars *game_vars, struct duck_vars *duck)
{
    drw_sprite(game_vars->window, game_vars->bg_sprite, NULL);
    if (game_vars->current_menu == 2) {
        drw_sprite(game_vars->window, game_vars->score_bg_sprite, NULL);
        drw_txt(game_vars->window, game_vars->score_txt, NULL);
        drw_txt(game_vars->window, game_vars->score_text, NULL);
        drw_sprite(game_vars->window, duck->sprite, NULL);
        draw_hearts(game_vars);
    }
}

void clock_event(struct game_vars *g_v, struct menu_vars *m_v,
struct duck_vars *duck)
{
    analyse_events(g_v->event, g_v, duck, m_v);
    if (g_v->current_menu == 2) {
        g_v->anim_time = sfClock_getElapsedTime(g_v->anim_clock);
        g_v->anim_seconds = g_v->anim_time.microseconds / 1000000.0;
        g_v->move_time = sfClock_getElapsedTime(g_v->move_clock);
        g_v->move_seconds = g_v->move_time.microseconds / 1000000.0;
        if (g_v->anim_seconds > duck->anim_speed) {
            move_rect(duck);
            sfClock_restart(g_v->anim_clock);
        }
        if (g_v->move_seconds > 0.01) {
            move_duck(g_v, duck, duck->speed + (my_atoi(g_v->score) / 3));
            sfClock_restart(g_v->move_clock);
        }
    }
}

int game_loop(struct game_vars *game_vars, struct duck_vars *duck,
struct menu_vars *menu_vars)
{
    int err = 0;
    while (sfRenderWindow_isOpen(game_vars->window)) {
        clock_event(game_vars, menu_vars ,duck);
        if (game_vars->lives <= 0) {
            reset_score(game_vars);
        }
        if (game_vars->current_menu == 2)
            sfSprite_setTextureRect(duck->sprite, duck->rect);
        draw_ents(game_vars, duck);
        if (game_vars->current_menu == 0)
            err = main_menu_loop(game_vars->event, game_vars, menu_vars);
        if (game_vars->current_menu == 1)
            err = cmap_menu_loop(game_vars->event, game_vars, menu_vars, duck);
        setp_sprite(game_vars->ms_sprite, game_vars->ms_pos);
        drw_sprite(game_vars->window, game_vars->ms_sprite, NULL);
        sfRenderWindow_display(game_vars->window);
    }
    return err;
}
