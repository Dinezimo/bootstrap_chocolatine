/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to check envents
*/

#include "paint.h"
#include <SFML/Graphics.h>

sfBool is_in_setting(menu_t *m, sfRenderWindow *win)
{
    sfFloatRect rp = sfRectangleShape_getGlobalBounds(m->d);
    sfVector2i mpos = sfMouse_getPositionRenderWindow(win);

    if (!sfFloatRect_contains(&rp, mpos.x, mpos.y))
        return sfFalse;
    return sfTrue;
}

void set_click(sfEvent *evt, menu_t *m, sfRenderWindow* win, state_t *s)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(win);

    if (evt->type == sfEvtMouseButtonPressed) {
        s->play = (tool_over(m->tools[0].s, win)) ? 1 : 0;
        s->resume = (tool_over(m->tools[1].s, win)) ? 1 : 0;
        s->setting = (tool_over(m->tools[2].s, win) ||
        s->setting && is_in_setting(m, win)) ? 1 : 0;
        s->Quit = (tool_over(m->tools[3].s, win)) ? 1 : 0;
        s->add_vol = (set_over(m->button[0].s, win) && s->setting) ? 1 : 0;
        s->no_vol = (set_over(m->button[1].s, win) && s->setting) ? 1 : 0;
        s->mute = (set_over(m->button[3].s, win) && s->setting) ? 1 : 0;
        if (set_over(m->button[2].s, win) && s->setting)
            s->no_sound = (s->no_sound) ? 0 : 1;
        s->exit = (set_over(m->button[4].s, win) && s->setting) ? 1 : 0;
    }
}

void overtool_act_tmp(button_t *b, sfRenderWindow *win, sfEvent *evt, var_t *v, state_t *s)
{
    sfVector2f st = (sfVector2f){0.12, 0.1};
    sfVector2f norm = sfSprite_getScale(b->s);
    sfVector2f big = (sfVector2f){0.13, 0.12};
    sfVector2f sma = (sfVector2f){0.08, 0.08};

    if (tool_over(b->s, win) && norm.x < 0.15) {
        sfSprite_setScale(b->s, big);
        if (!s->no_sound)
            sfMusic_play(v->cli);
    }
    if (evt->type == sfEvtMouseButtonPressed
    && tool_over(b->s, win) && norm.x < 0.08)
        sfSprite_setScale(b->s, sma);
    if (!tool_over(b->s, win) && st.x != 0.12 && st.y != 0.1)
        sfSprite_setScale(b->s, st);
}

void overtool_act(button_t *b, sfRenderWindow *win, sfEvent *evt, var_t *v, state_t *s)
{
    for (int i = 0; i < 4; i++)
        overtool_act_tmp(&b[i], win, evt, v, s);
}

sfBool tool_over(sfSprite *s, sfRenderWindow* win)
{
    sfFloatRect rp = sfSprite_getGlobalBounds(s);
    sfVector2i mpos = sfMouse_getPositionRenderWindow(win);

    rp.top += 65;
    rp.left += 40;
    rp.height = 70;
    rp.width = 300;
    if (!sfFloatRect_contains(&rp, mpos.x, mpos.y))
        return sfFalse;
    return sfTrue;
}
