/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** pour gérer le volume
*/

#include "paint.h"

sfRectangleShape **creation_vol_sequence()
{
    sfRectangleShape **tmp = malloc(sizeof(sfRectangleShape *) * 2);

    for (int i = 0; i < 2; i++) {
        tmp[i] = sfRectangleShape_create();
        sfRectangleShape_setPosition(tmp[i], (sfVector2f){600, 300});
    }
    sfRectangleShape_setFillColor(tmp[0], sfBlack);
    sfRectangleShape_setSize(tmp[0], (sfVector2f){200, 40});
    sfRectangleShape_setOutlineThickness(tmp[0], 2);
    sfRectangleShape_setOutlineColor(tmp[0], sfColor_fromRGBA(255, 255, 255, 150));
    sfRectangleShape_setFillColor(tmp[1], sfTransparent);
    sfRectangleShape_setSize(tmp[0], (sfVector2f){0, 30});
    return tmp;
}

void volume_design(sfRectangleShape **r, int vol, sfRenderWindow *win, state_t *s)
{
    sfRectangleShape_setSize(r[1], (sfVector2f){vol * 20, 30});
    if (vol > 0 && vol < 5)
        sfRectangleShape_setFillColor(r[1], sfColor_fromRGBA(250, 0, 0, 150));
    if (vol >= 5 && vol < 8)
        sfRectangleShape_setFillColor(r[1], sfColor_fromRGBA(0, 250, 250, 150));
    if (vol >= 8 && vol <= 10)
        sfRectangleShape_setFillColor(r[1], sfColor_fromRGBA(0, 250, 0, 150));
    if (s->setting)
        for (int i = 0; i < 2; i++)
            sfRenderWindow_drawRectangleShape(win, r[i], NULL);
}
