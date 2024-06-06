/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to manage color
*/

#include "paint.h"

co_t *col_init(void)
{
    co_t *c = malloc(sizeof(co_t));

    c->red = 0;
    c->green = 0;
    c->blue = 0;
    c->black = 0;
    c->yellow = 0;
    c->white = 0;
    c->magenta = 0;
    c->cyan = 0;
    return c;
}

co_t *col_val(co_t *c, win_t *w)
{
    if (w->event.type == sfEvtMouseButtonPressed) {
        c->red = (is_over(w->col[0].r, w->win)) ? 1 : 0;
        c->blue = (is_over(w->col[1].r, w->win)) ? 1 : 0;
        c->black = (is_over(w->col[2].r, w->win)) ? 1 : 0;
        c->yellow = (is_over(w->col[3].r, w->win)) ? 1 : 0;
        c->white = (is_over(w->col[4].r, w->win)) ? 1 : 0;
        c->cyan = (is_over(w->col[5].r, w->win)) ? 1 : 0;
        c->magenta = (is_over(w->col[6].r, w->win)) ? 1 : 0;
        c->green = (is_over(w->col[7].r, w->win)) ? 1 : 0;
    }
    return c;
}

sfColor pixel_color(co_t *c)
{
    if (c->red == 1)
        return sfRed;
    if (c->blue == 1)
        return sfBlue;
    if (c->black == 1)
        return sfBlack;
    if (c->green == 1)
        return sfGreen;
    if (c->magenta == 1)
        return sfMagenta;
    if (c->cyan == 1)
        return sfCyan;
    if (c->yellow == 1)
        return sfYellow;
    if (c->white == 1)
        return sfWhite;
    return sfBlack;
}
