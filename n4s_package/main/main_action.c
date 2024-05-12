/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to manage actions
*/
#include "paint.h"

void actions(menu_t *m, state_t *s, var_t *p, sfRenderWindow *win, sfEvent evt)
{
    draw_tool(m->tools, win, evt, p, s);
    if (s->play)
        sfRenderWindow_close(win);
    if (s->setting)
        draw_set(m->d, m->button, win);
    if (s->Quit)
        exit(1);
    if (s->add_vol && p->vol < 10) {
        printf("vol = %d\n", p->vol);
        p->vol += 1;
        sfMusic_setVolume(p->mus, 10 * p->vol);
        s->add_vol = sfFalse;
    }
    if (s->no_vol && p->vol >= 1) {
        p->vol -= 1;
        sfMusic_setVolume(p->mus, 10 * p->vol);
        s->no_vol = sfFalse;
        printf("vol = %d\n", p->vol);
    }
    if (s->mute) {
        p->vol = 0;
        sfMusic_setVolume(p->mus, 10 * p->vol);
        s->mute = 0;
    }
    if (s->exit)
        s->setting = sfFalse;
}
