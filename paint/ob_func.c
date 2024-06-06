/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to use all_function()
*/
#include "paint.h"

void destroy_res(win_t *w)
{
    sfTexture *t = sfTexture_createFromFile("new.jpg", NULL);

    sfSprite_destroy(w->back);
    sfRectangleShape_destroy(w->file[0].r);
    sfRectangleShape_destroy(w->file[1].r);
    sfRectangleShape_destroy(w->file[2].r);
    sfTexture_destroy(t);
    sfRenderWindow_destroy(w->win);
}
