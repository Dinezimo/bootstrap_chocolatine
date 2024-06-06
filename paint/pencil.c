/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to set pen 's bools
*/

#include "paint.h"

st_t *pen_bool(tool_t *t, st_t *p, win_t *w)
{
    if (is_over(t[1].r, w->win))
        p->tick = 1;
    if (is_over(t[0].r, w->win))
        p->tick = 0;
    return p;
}

int pen_tic(st_t *w)
{
    if (w->tick == 1)
        return 20;
    return 5;
}
