/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** sfx_change.c
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

int change_sfx(struct duck_vars *duck, struct game_vars *game_vars, int index)
{
    if (index == 0)  {
        duck->sfx = MscCFF("assets/kill_dh.ogg");
        game_vars->go_music = MscCFF("assets/go_mc.ogg");
    }
    if (index == 1) {
        duck->sfx = MscCFF("assets/kill_mc.ogg");
        game_vars->go_music = MscCFF("assets/go_mc.ogg");
    }
    if (index == 2) {
        duck->sfx = MscCFF("assets/kill_cp.ogg");
        game_vars->go_music = MscCFF("assets/go_mc.ogg");
    }
    if (!duck->sfx || !game_vars->go_music) return 84;
    sfMusic_setVolume(duck->sfx, 35);
    return 0;
}
