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

int handle_menu_mouse_click(sfVector2i evt, struct game_vars *g_v,
struct duck_vars *duck, struct menu_vars *m_v);

void add_one(struct game_vars *game_vars)
{
    int done = 0;
    char *newstr = malloc(sizeof(char) * my_strlen(game_vars->score) + 1);
    for (int i = my_strlen(game_vars->score) - 1; i >= 0; i--) {
        if (done == 1) {
            newstr[i] = game_vars->score[i];
            continue;
        }
        if (game_vars->score[i] == '9') {
            newstr[i] = '0';
            continue;
        }
        if (game_vars->score[i] < '9' && game_vars->score[i] >= '0') {
            newstr[i] = (game_vars->score[i] + 1);
            done = 1;
        }
    }
    newstr[my_strlen(game_vars->score)] = '\0';
    game_vars->score = newstr;
}

int handle_mouse_click(sfVector2i evt, struct game_vars *g_v,
struct duck_vars *duck, struct menu_vars *m_v)
{
    if (evt.x < duck->pos.x + (duck->rect.width * duck->scale)
    && evt.x > duck->pos.x)
        if (evt.y < duck->pos.y + (duck->rect.height * duck->scale)
        && evt.y > duck->pos.y) {
            sfMusic_stop(duck->sfx);
            sfMusic_play(duck->sfx);
            add_one(g_v);
            sfText_setString(g_v->score_text, g_v->score);
            duck->pos.x = (int)((float)rand() / (float)(RAND_MAX));
            duck->pos.x *= (duck->rect.width * -1);
            duck->pos.x -= duck->rect.width;
            duck->pos.y = (float)rand() / (float)RAND_MAX;
            duck->pos.y *= g_v->h - (duck->rect.height +256);
            duck->pos.y += 256;
        }
    return 0;
}

int handle_mouse_move(sfVector2i evt, struct game_vars *game_vars)
{
    sfVector2f pos = {evt.x, evt.y};
    game_vars->ms_pos.x = pos.x - 24;
    game_vars->ms_pos.y = pos.y - 24;
    return 0;
}

void analyse_events(sfEvent event, struct game_vars *game_vars,
struct duck_vars *duck, struct menu_vars *menu_vars)
{
    sfRenderWindow_clear(game_vars->window, sfBlack);
    while (sfRenderWindow_pollEvent(game_vars->window, &event)) {
        if (event.type == EvtMs && game_vars->current_menu < 2)
            handle_menu_mouse_click(MsPos(game_vars->window),
            game_vars, duck, menu_vars);
        if (event.type == EvtMs && game_vars->current_menu == 2)
            handle_mouse_click(MsPos(game_vars->window),
            game_vars, duck, menu_vars);
        if (event.type == EvtMsMv)
            handle_mouse_move(MsPos(game_vars->window), game_vars);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game_vars->window);
    }
}
