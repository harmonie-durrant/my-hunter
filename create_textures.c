/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** create_textures.c
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

int create_main_menu_start(struct game_vars *game_vars,
struct menu_vars *menu_vars);

int create_main_menu_mapc(struct game_vars *game_vars,
struct menu_vars *menu_vars);

int create_main_menu_score(struct game_vars *game_vars,
struct menu_vars *menu_vars);

void get_highscore(struct game_vars *game_vars);

int create_mouse(struct game_vars *game_vars)
{
    sfVector2f ms_scale = {0.1, 0.1};
    game_vars->ms_texture = CreText("./assets/mouse_img.png", NULL);
    if (!game_vars->ms_texture) return 84;
    game_vars->ms_sprite = sfSprite_create();
    sfSprite_setTexture(game_vars->ms_sprite, game_vars->ms_texture, sfTrue);
    sfSprite_setScale(game_vars->ms_sprite, ms_scale);
    game_vars->ms_pos.x = -500;
    game_vars->ms_pos.y = -500;
}

int create_score_bg(struct game_vars *game_vars)
{
    sfVector2f score_bg_scale = {2, 2};
    game_vars->score_bg_texture = CreText("./assets/score_bg.png", NULL);
    if (!game_vars->score_bg_texture) return 84;
    game_vars->score_bg_sprite = sfSprite_create();
    sfSprite_setTexture(game_vars->score_bg_sprite,
    game_vars->score_bg_texture, sfTrue);
    sfSprite_setScale(game_vars->score_bg_sprite, score_bg_scale);
    game_vars->score_bg_pos.x = 0;
    game_vars->score_bg_pos.y = 0;
    setp_sprite(game_vars->score_bg_sprite, game_vars->score_bg_pos);
}

int create_score_texts(struct game_vars *game_vars)
{
    sfVector2f offset_text = {70, 103};
    sfVector2f offset_score = {60, 147};
    get_highscore(game_vars);
    game_vars->font = sfFont_createFromFile("Monocraft.otf");
    if (!game_vars->font) return 84;
    game_vars->score_txt = sfText_create();
    game_vars->score_text = sfText_create();
    sfText_setString(game_vars->score_txt, "SCORE");
    sfText_setString(game_vars->score_text, game_vars->score);
    sfText_setFont(game_vars->score_txt, game_vars->font);
    sfText_setFont(game_vars->score_text, game_vars->font);
    sfText_setCharacterSize(game_vars->score_txt, 35);
    sfText_setCharacterSize(game_vars->score_text, 35);
    sfText_move(game_vars->score_txt, offset_text);
    sfText_move(game_vars->score_text, offset_score);
}

int create_bg(struct game_vars *game_vars)
{
    game_vars->bg_texture = CreText("./assets/bg_dh.png", NULL);
    if (!game_vars->bg_texture) return 84;
    game_vars->bg_sprite = sfSprite_create();
    sfSprite_setTexture(game_vars->bg_sprite, game_vars->bg_texture, sfTrue);
}

int create_main_menu(struct game_vars *game_vars, struct menu_vars *menu_vars)
{
    create_main_menu_start(game_vars, menu_vars);
    create_main_menu_mapc(game_vars, menu_vars);
    create_main_menu_score(game_vars, menu_vars);
}
