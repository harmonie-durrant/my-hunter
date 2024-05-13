/*
** EPITECH PROJECT, 2022
** CSFML_bs
** File description:
** my_csfml.h
*/

#ifndef MY_HR_M_H_
    #define MY_HR_M_H_

    #define create_window sfRenderWindow_create

    #define draw_sprite sfRenderWindow_drawSprite

    #define close_window sfRenderWindow_close

    #define RWIsOp sfRenderWindow_isOpen

    #define sfFPSLimit sfRenderWindow_setFramerateLimit

    #define drw_sprite sfRenderWindow_drawSprite

    #define setp_sprite sfSprite_setPosition

    #define drw_txt sfRenderWindow_drawText

    #define set_txt sfSprite_setTexture

    #define MsPos sfMouse_getPositionRenderWindow

    #define show_mouse sfRenderWindow_setMouseCursorVisible

    #define CreText sfTexture_createFromFile

    #define EvtMs sfEvtMouseButtonPressed

    #define EvtMsMv sfEvtMouseMoved

    #define MscCFF sfMusic_createFromFile

#endif /* MY_HR_M_H_ */
