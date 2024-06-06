/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to manage sprite comportement
*/
#include "paint.h"

sfSprite* sprite_settings(char *test, sfVector2f scale, sfVector2f position)
{
    sfSprite* sprite = sfSprite_create();
    sfTexture *t = sfTexture_createFromFile(test, NULL);

    sfSprite_setTexture(sprite, t, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, position);
    return sprite;
}

void draw_spr(tool_t *s, int len, win_t *w)
{
    for (int i = 0; i < len; i++)
        sfRenderWindow_drawSprite(w->win, s[i].sprite, NULL);
}
