/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to check envents
*/

#include "paint.h"
#include <SFML/Graphics.h>

sfBool set_over(sfSprite *s, sfRenderWindow* win)
{
    sfFloatRect rp = sfSprite_getGlobalBounds(s);
    sfVector2i mpos = sfMouse_getPositionRenderWindow(win);

    rp.top += 30;
    rp.left += 30;
    rp.height = 80;
    rp.width = 70;
    if (!sfFloatRect_contains(&rp, mpos.x, mpos.y))
        return sfFalse;
    return sfTrue;
}

void over_set(button_t *t, int len, sfRenderWindow *win)
{
    sfVector2f sc = (sfVector2f){0.3, 0.3};

    for (int i = 0; i < len; i++) {
        if (set_over(t[i].s, win))
            sfText_setFillColor(t[i].txt, sfRed);
        if (!set_over(t[i].s, win))
            sfText_setFillColor(t[i].txt, sfWhite);
    }
}
