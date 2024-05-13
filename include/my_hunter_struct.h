/*
** EPITECH PROJECT, 2022
** CSFML_bs
** File description:
** my_csfml.h
*/

#include <SFML/System/Types.h>
#include <SFML/Audio.h>
#include "my_hunter_macros.h"

#ifndef MY_HR_S_H_
    #define MY_HR_S_H_

    typedef struct duck_vars {
        sfTexture *texture;
        sfSprite *sprite;
        sfIntRect rect;
        int maxw;
        sfVector2f pos;
        float scale;
        int speed;
        float anim_speed;
        sfMusic *sfx;
    } duck_vars;

    typedef struct game_vars {
        sfVideoMode mode;
        int w;
        int h;
        int bpp;
        sfRenderWindow *window;
        sfEvent event;
        sfClock *anim_clock;
        sfTime anim_time;
        float anim_seconds;
        sfClock *move_clock;
        sfTime move_time;
        float move_seconds;
        sfTexture *bg_texture;
        sfSprite *bg_sprite;
        sfTexture *ms_texture;
        sfSprite *ms_sprite;
        sfVector2f ms_pos;
        sfTexture *heart_texture;
        sfSprite *heart_sprite;
        sfVector2f heart_pos;
        sfTexture *heart1_texture;
        sfSprite *heart1_sprite;
        sfVector2f heart1_pos;
        sfTexture *heart2_texture;
        sfSprite *heart2_sprite;
        sfVector2f heart2_pos;
        sfTexture *mapp_texture;
        sfSprite *mapp_sprite;
        sfVector2f mapp_pos;
        sfTexture *mapp1_texture;
        sfSprite *mapp1_sprite;
        sfVector2f mapp1_pos;
        sfTexture *mapp2_texture;
        sfSprite *mapp2_sprite;
        sfVector2f mapp2_pos;
        int mapp_btn_w;
        int mapp_btn_h;
        sfTexture *score_bg_texture;
        sfSprite *score_bg_sprite;
        sfVector2f score_bg_pos;
        sfFont *font;
        sfText *score_txt;
        sfText *score_text;
        char *score;
        char *high_score;
        int lives;
        sfMusic *music;
        sfMusic *go_music;
        int current_menu;
        struct duck_vars duck;
    } game_vars;

    typedef struct menu_vars {
        sfVector2f start_scale;
        sfVector2f start_pos;
        int btn_w;
        int btn_h;
        sfTexture *start_texture;
        sfSprite *start_sprite;
        sfVector2f mapbtn_scale;
        sfVector2f mapbtn_pos;
        int mapbtn_w;
        int mapbtn_h;
        sfTexture *mapbtn_texture;
        sfSprite *mapbtn_sprite;
        sfText *hs_text;
    } menu_vars;

#endif /* MY_HR_S_H_ */
