/*
** EPITECH PROJECT, 2024
** project C
** File description:
** to manage bools actions
*/
#include "paint.h"

st_t *state(st_t *p)
{
    p->draw_ok = sfFalse;
    p->color = sfFalse;
    p->file = sfFalse;
    p->edit = sfFalse;
    p->help = sfFalse;
    p->save = sfFalse;
    p->erase = sfFalse;
    p->new = sfFalse;
    p->import = sfFalse;
    p->login = sfFalse;
    p->tick = sfFalse;
    p->man = sfFalse;
    p->log = sfFalse;
    return p;
}

sfBool is_over(sfRectangleShape *r, sfRenderWindow* win)
{
    sfFloatRect rp = sfRectangleShape_getGlobalBounds(r);
    sfVector2i mpos = sfMouse_getPositionRenderWindow(win);

    if (!sfFloatRect_contains(&rp, mpos.x, mpos.y))
        return sfFalse;
    return sfTrue;
}

void over_tool(tool_t *t, int len, sfRenderWindow *win)
{
    for (int i = 0; i < len; i++) {
        if (is_over(t[i].r, win) == 0)
            sfRectangleShape_setOutlineColor(t[i].r, sfWhite);
        if (is_over(t[i].r, win) != 0)
            sfRectangleShape_setOutlineColor(t[i].r, sfBlack);
    }
}

sfBool is_list_over(tool_t *t, sfRenderWindow* win, int len)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(win);

    if (mpos.x > t->gr->pos.x && mpos.x < t->gr->pos.x + t->gr->size.x &&
        mpos.y > t->gr->pos.y && mpos.y < t->gr->pos.y + t->gr->size.y)
        return 1;
    
return 0;
}
