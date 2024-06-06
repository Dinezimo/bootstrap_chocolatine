/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to draw
*/
#include "paint.h"

void draw_or_erase(win_t *w, st_t *p, co_t *c)
{
    if (w->event.type == sfEvtMouseButtonPressed
        && is_over(w->edit[0].r, w->win)) {
        w->is_draw = 1;
        w->is_erase = 0;
    }
    if (w->event.type == sfEvtMouseButtonPressed
        && is_over(w->edit[2].r, w->win)) {
        w->is_draw = 0;
        w->is_erase = 1;
    }
}

void edit_help_exec(win_t *w, st_t *p, co_t *c)
{
    if (p->edit == 1) {
        over_tool(w->edit, 4, w->win);
        draw_or_erase(w, p, c);
        display_tools(w->edit, 4, w->win);
    }
    if (p->help == 1) {
        over_tool(w->help, 2, w->win);
        display_tools(w->help, 2, w->win);
        if (w->event.type == sfEvtMouseButtonPressed)
            p = h_bool(w->help, p, w);
        h_tic(p, w);
    }
}

void draw_exec(win_t *w, st_t *p, co_t *c)
{
    if (w->is_draw == 1) {
        over_tool(w->col, 8, w->win);
        over_tool(w->pencil, 2, w->win);
        display_tools2(w->col, 8, w->win);
        display_tools(w->pencil, 2, w->win);
        if (w->event.type == sfEvtMouseButtonPressed) {
            w->colo = pixel_color(col_val(c, w));
            p = pen_bool(w->pencil, p, w);
        }
        if (w->event.type == sfEvtMouseMoved)
            draw_in_paper(w->paper->sprite, w->colo, w, pen_tic(p));
    }
    if (w->is_erase == 1)
        draw_in_paper(w->paper->sprite, sfWhite, w, 30);
    cool_cursor(w->is_draw, w->is_erase, w);
}
