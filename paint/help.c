/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to make help tools
*/

#include "paint.h"

tool_t *just_help(tool_t *el, int len)
{
    char *l[] = {"login.jpg", "man.jpg", NULL};
    sfFont* font = sfFont_createFromFile("name_pol.ttf");
    tool_t *spr = sprites_list(l, len);

    for (int i = 0; i < len; i++) {
        sfRectangleShape_setTexture(el[i].r, spr[i].texture, sfTrue);
        sfRectangleShape_setOutlineThickness(el[i].r, 2);
        sfRectangleShape_setOutlineColor(el[i].r, sfBlack);
        el[i].txt = tool_name(el[i].name, font);
        sfText_setPosition(el[i].txt, sfRectangleShape_getPosition(el[i].r));
    }
    return el;
}

tool_t *help()
{
    char *l[] = {"login", "manual", NULL};
    rep_t *gr = malloc(sizeof(rep_t));

    gr->pos = (sfVector2f){450, 80};
    gr->nb = (sfVector2f){1, 2};
    gr->size = (sfVector2f){150, 200};
    return just_help(tool_parts(l, 2, gr), 2);
}

st_t *h_bool(tool_t *t, st_t *p, win_t *w)
{
    if (is_over(t[0].r, w->win))
        p->log = 1;
    else
        p->log = 0;
    if (is_over(t[1].r, w->win))
        p->man = 1;
    else
        p->man = 0;
    return p;
}

int h_tic(st_t *p, win_t *w)
{
    if (p->man == 1) {
        sfRenderWindow_drawRectangleShape(w->win, w->man_r, NULL);
        sfRenderWindow_drawText(w->win, w->man_t, NULL);
        draw_spr(w->smile, 3, w);
    } else if (p->log == 1)
        sfRenderWindow_drawSprite(w->win, w->curs[2].sprite, NULL);
}
