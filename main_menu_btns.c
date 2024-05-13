/*
** EPITECH PROJECT, 2022
** Main (Workspace)
** File description:
** main_menu_btns
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

void get_highscore(struct game_vars *game_vars);

int create_main_menu_start(struct game_vars *game_vars,
struct menu_vars *menu_vars)
{
    int vw;
    int vh;
    menu_vars->btn_w = 554;
    menu_vars->btn_h = 174;
    menu_vars->start_scale.x = 0.8;
    menu_vars->start_scale.y = 0.8;
    vw = menu_vars->btn_w * menu_vars->start_scale.x;
    vh = menu_vars->btn_h * menu_vars->start_scale.y;
    menu_vars->start_pos.x = game_vars->w / 2 - (vw / 2);
    menu_vars->start_pos.y = game_vars->h / 2 - (vh / 2);
    menu_vars->start_texture = CreText("./assets/start.png", NULL);
    if (!menu_vars->start_texture) return 84;
    menu_vars->start_sprite = sfSprite_create();
    sfSprite_setTexture(menu_vars->start_sprite,
    menu_vars->start_texture, sfTrue);
    sfSprite_setScale(menu_vars->start_sprite, menu_vars->start_scale);
    setp_sprite(menu_vars->start_sprite, menu_vars->start_pos);
}

int create_main_menu_mapc(struct game_vars *game_vars,
struct menu_vars *menu_vars)
{
    int vw;
    int vh;
    menu_vars->mapbtn_w = 554;
    menu_vars->mapbtn_h = 174;
    menu_vars->mapbtn_scale.x = 0.8;
    menu_vars->mapbtn_scale.y = 0.8;
    vw = menu_vars->mapbtn_w * menu_vars->mapbtn_scale.x;
    vh = menu_vars->mapbtn_h * menu_vars->mapbtn_scale.y;
    menu_vars->mapbtn_pos.x = game_vars->w / 2 - (vw / 2);
    menu_vars->mapbtn_pos.y = ((game_vars->h / 4) * 3) - (vh / 2);
    menu_vars->mapbtn_texture = CreText("./assets/mapc.png", NULL);
    if (!menu_vars->mapbtn_texture) return 84;
    menu_vars->mapbtn_sprite = sfSprite_create();
    sfSprite_setTexture(menu_vars->mapbtn_sprite,
    menu_vars->mapbtn_texture, sfTrue);
    sfSprite_setScale(menu_vars->mapbtn_sprite, menu_vars->mapbtn_scale);
    setp_sprite(menu_vars->mapbtn_sprite, menu_vars->mapbtn_pos);
}

int create_main_menu_score(struct game_vars *game_vars,
struct menu_vars *menu_vars)
{
    sfVector2f txt_pos;
    txt_pos.x = (game_vars->w / 2) - 300;
    txt_pos.y = 25;
    char *hs_tmp = "High Score: ";
    char *hs_str = my_strcat(hs_tmp, game_vars->high_score);
    menu_vars->hs_text = sfText_create();
    sfText_setString(menu_vars->hs_text, hs_str);
    sfText_setFont(menu_vars->hs_text, game_vars->font);
    sfText_setCharacterSize(menu_vars->hs_text, 50);
    sfText_setColor(menu_vars->hs_text, sfRed);
    sfText_setPosition(menu_vars->hs_text, txt_pos);
}
