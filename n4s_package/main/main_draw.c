/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to draw tools
*/
#include "paint.h"

void draw_tool(button_t *t, sfRenderWindow *win, sfEvent evt,  var_t *v, state_t *s)
{
    sfRenderWindow_drawRectangleShape(win, t[0].d, NULL);
    overtool_act(t, win, &evt, v, s);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(win, t[i].s, NULL);
}

void draw_set(sfRectangleShape *d, button_t *b, sfRenderWindow *win)
{
    sfRenderWindow_drawRectangleShape(win, d, NULL);
    for (int i = 0; i < 5; i++) {
        sfRenderWindow_drawSprite(win, b[i].s, NULL);
        sfRenderWindow_drawText(win ,b[i].txt, NULL);
    }
}
