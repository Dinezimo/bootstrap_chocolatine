/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to manage events
*/
#include "paint.h"

void file_evt(win_t *w, st_t *p, co_t *c)
{
    if (w->event.type == sfEvtClosed)
        sfRenderWindow_close(w->win);
    if (is_over(w->princ[0].r, w->win)) {
        p->file = sfTrue;
        w->princ[0].state = 1;
    } else if (w->princ[0].state == 1 && is_list_over(w->file, w->win, 3)) {
        p->file = sfTrue;
    } else {
        p->file = sfFalse;
        w->princ[0].state = 0;
    }
}

void edit_evt(win_t *w, st_t *p, co_t *c)
{
    if (is_over(w->princ[1].r, w->win)) {
        p->edit = sfTrue;
        w->princ[1].state = 1;
    } else if (w->princ[1].state == 1 && is_list_over(w->edit, w->win, 4))
        p->edit = sfTrue;
    else {
        p->edit = 0;
        w->princ[1].state = 0;
    }
}

void help_evt(win_t *w, st_t *p, co_t *c)
{
    if (is_over(w->princ[2].r, w->win)) {
        p->help = sfTrue;
        w->princ[2].state = 1;
    } else if (w->princ[2].state == 1 && is_list_over(w->help, w->win, 4))
        p->help = 1;
    else {
        p->help = 0;
        w->princ[2].state = 0;
    }
}

void paper_file_draw(win_t *w, st_t *p, co_t *c)
{
    if (p->file == 1) {
        over_tool(w->file, 3, w->win);
        display_tools(w->file, 3, w->win);
        if (is_over(w->file[1].r, w->win)
            && w->event.type == sfEvtMouseButtonPressed)
            sfImage_saveToFile(w->img, "Akatsuka.png");
    }
}
