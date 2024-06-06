/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to manage tools
*/
#include "paint.h"

void drawing(win_t *w, st_t *p, co_t *c)
{
    while (sfRenderWindow_pollEvent(w->win, &(w->event))) {
        if (w->event.type == sfEvtClosed)
            sfRenderWindow_close(w->win);
        file_evt(w, p, c);
        edit_evt(w, p, c);
        help_evt(w, p, c);
    }
    sfRenderWindow_drawSprite(w->win, w->paper->sprite, NULL);
    display_tools(w->princ, 3, w->win);
    paper_file_draw(w, p, c);
    edit_help_exec(w, p, c);
    draw_exec(w, p, c);
    sfRenderWindow_display(w->win);
}

void is_open(win_t *w, st_t *p, co_t *c)
{
    while (sfRenderWindow_isOpen(w->win)) {
        sfRenderWindow_clear(w->win, w->color);
        drawing(w, p, c);
    }
}
