/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to draw all
*/

#include "paint.h"

tool_t *just_pen(tool_t *el, int len)
{
    sfFont* font = sfFont_createFromFile("name_pol.ttf");

    for (int i = 0; i < len; i++) {
        sfRectangleShape_setOutlineThickness(el[i].r, 2);
        sfRectangleShape_setOutlineColor(el[i].r, sfBlack);
        el[i].txt = tool_name(el[i].name, font);
        sfText_setPosition(el[i].txt, sfRectangleShape_getPosition(el[i].r));
    }
    return el;
}

tool_t *pen_tick(void)
{
    char *l[] = {"micro", "macro", NULL};
    rep_t *gr = malloc(sizeof(rep_t));

    gr->pos = (sfVector2f){10, 550};
    gr->size = (sfVector2f){150, 50};
    gr->nb = (sfVector2f){2, 1};
    return just_pen(tool_parts(l, 2, gr), 2);
}

tool_t *just_col(tool_t *el, int len)
{
    sfFont* font = sfFont_createFromFile("name_pol.ttf");

    for (int i = 0; i < len; i++) {
        sfRectangleShape_setOutlineThickness(el[i].r, 2);
        el[i].txt = tool_name(el[i].name, font);
        sfText_setPosition(el[i].txt, sfRectangleShape_getPosition(el[i].r));
    }
    return el;
}

tool_t *cols(void)
{
    char **l = str_list();
    rep_t *gr = malloc(sizeof(rep_t));
    tool_t *p;
    sfColor *col = col_list();

    gr->pos = (sfVector2f){10, 610};
    gr->size = (sfVector2f){150, 150};
    gr->nb = (sfVector2f){3, 3};
    p = just_col(tool_parts(l, 8, gr), 8);
    for (int i = 0; i < 8; i++)
        sfRectangleShape_setFillColor(p[i].r, col[i]);
    free(l);
    free(gr);
    return p;
}
