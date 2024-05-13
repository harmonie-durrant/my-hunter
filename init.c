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
#include "my_hunter_struct.h"
#include "my_hunter_macros.h"

int game_loop(struct game_vars *, struct duck_vars *, struct menu_vars *);

int create_bg(struct game_vars *game_vars);

int create_mouse(struct game_vars *game_vars);

int create_score_bg(struct game_vars *game_vars);

int create_score_texts(struct game_vars *game_vars);

void create_clocks(struct game_vars *game_vars);

int create_main_menu(struct game_vars *game_vars,
struct menu_vars *menu_vars);

int create_hearts(struct game_vars *game_vars);

int create_mapp(struct game_vars *game_vars);

int change_sfx(struct duck_vars *duck, struct game_vars *game_vars, int index);

void destroy(struct game_vars *game_vars, struct duck_vars *duck,
struct menu_vars *menu_vars);

int change_music(struct game_vars *game_vars, struct menu_vars *menu_vars,
int index)
{
    if (game_vars->music != NULL)
        sfMusic_destroy(game_vars->music);
    if (index == 0) {
        game_vars->music = MscCFF("assets/msc_dh.ogg");
        sfMusic_setVolume(game_vars->music, 20);
    }
    if (index == 1) {
        game_vars->music = MscCFF("assets/msc_mc.ogg");
        sfMusic_setVolume(game_vars->music, 100);
    }
    if (index == 2) {
        game_vars->music = MscCFF("assets/msc_cb.ogg");
        sfMusic_setVolume(game_vars->music, 20);
    }
    if (!game_vars->music) return 84;
    sfMusic_play(game_vars->music);
    sfMusic_setLoop(game_vars->music, sfTrue);
    return 0;
}

int init_music(struct game_vars *game_vars, struct menu_vars *menu_vars)
{
    game_vars->music = MscCFF("assets/msc_dh.ogg");
    game_vars->go_music = MscCFF("assets/go_mc.ogg");
    sfMusic_setVolume(game_vars->music, 20);
    sfMusic_setVolume(game_vars->go_music, 50);
    sfMusic_play(game_vars->music);
    sfMusic_setLoop(game_vars->music, sfTrue);
    return 0;
}

int set_vars(struct game_vars *game_vars, struct menu_vars *menu_vars)
{
    if (init_music(game_vars, menu_vars) == 84) return 84;
    sfEvent event;
    int h = 1000;
    int w = 1900;
    int bpp = 32;
    sfVideoMode mode = {w, h, bpp};
    game_vars->h = h;
    game_vars->w = w;
    game_vars->bpp = bpp;
    game_vars->window = create_window(mode, "my_hunter", sfClose, NULL);
    sfFPSLimit(game_vars->window, 60);
    show_mouse(game_vars->window, sfFalse);
    create_clocks(game_vars);
    game_vars->event = event;
    game_vars->lives = 3;
    if (create_bg(game_vars) == 84) return 84;
    if (create_mouse(game_vars) == 84) return 84;
    if (create_score_bg(game_vars) == 84) return 84;
    if (create_score_texts(game_vars) == 84) return 84;
    if (create_main_menu(game_vars, menu_vars) == 84) return 84;
}

int init_duck(struct game_vars *game_vars, struct duck_vars *duck)
{
    sfVector2f duck_scale = {1.0, 1.0};
    duck->scale = 1.0;
    duck->speed = 4;
    duck->texture = CreText("assets/duck-sheet.png", NULL);
    if (!duck->texture) return 84;
    duck->sprite = sfSprite_create();
    sfSprite_setTexture(duck->sprite, duck->texture, sfTrue);
    duck->rect;
    duck->pos.x = (int)(((float)rand() / (float)(RAND_MAX)) * -440) - 110;
    duck->pos.y = (float)rand() / (float)RAND_MAX + 256;
    duck->pos.y *= duck->pos.y * ((game_vars->h * 0.8) - 110);
    duck->rect.top = 0;
    duck->rect.left = 0;
    duck->rect.width = 110;
    duck->rect.height = 110;
    duck->maxw = 220;
    duck->anim_speed = 0.12;
    sfSprite_setScale(duck->sprite, duck_scale);
    change_sfx(duck, game_vars, 0);
    return 0;
}

int start_game(void)
{
    struct game_vars game_vars;
    struct menu_vars menu_vars;
    struct duck_vars duck;
    game_vars.current_menu = 0;
    game_vars.high_score = 0;
    game_vars.score = "000000";
    if (set_vars(&game_vars, &menu_vars) == 84) return 84;
    if (init_duck(&game_vars, &duck) == 84 || !game_vars.window) return 84;
    if (create_hearts(&game_vars) == 84) return 84;
    if (create_mapp(&game_vars) == 84) return 84;
    duck.pos.y = 256 + 64;
    game_loop(&game_vars, &duck, &menu_vars);
    destroy(&game_vars, &duck, &menu_vars);
    return 0;
}
