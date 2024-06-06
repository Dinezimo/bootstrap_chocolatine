/*
** EPITECH PROJECT, 2024
** projet C
** File description:
** to manage rectangle shape
*/

#include "paint.h"

sfRectangleShape *cadre_func(void)
{
    sfRectangleShape* cadre = sfRectangleShape_create();

    sfRectangleShape_setSize(cadre, (sfVector2f){1500, 800});
    sfRectangleShape_setOutlineThickness(cadre, 2);
    sfRectangleShape_setOutlineColor(cadre, sfBlue);
    sfRectangleShape_setPosition(cadre, (sfVector2f){200, 80});
    return cadre;
}

tool_t *tool_tmp(char **list, int len, rep_t *gr)
{
    int i = 0;
    tool_t *p = malloc(sizeof(tool_t) * (len + 3));

    for (i = 0; list[i] != NULL; i++) {
        p[i].name = my_strdup(list[i]);
        p[i].ind = i;
        p[i].r = sfRectangleShape_create();
        p[i].gr = copy_rep(gr);
    }
    return p;
}

tool_t *tool_parts(char **list, int len, rep_t *gr)
{
    int i = 0;
    int k = 0;
    int g = 0;
    tool_t *p = tool_tmp(list, len, gr);
    double L = gr->size.x / gr->nb.x;
    double l = gr->size.y / gr->nb.y;

    for (int j = gr->pos.y; j < gr->pos.y + gr->size.y && k < len; j += l) {
        for (int i = gr->pos.x; i < gr->pos.x + gr->size.x
            && k < len; i += L) {
            sfRectangleShape_setPosition(p[k].r, (sfVector2f){i, j + g});
            sfRectangleShape_setSize(p[k].r, (sfVector2f){L, l});
            k++;
        }
        g += 5;
    }
    return p;
}

rep_t *copy_rep(rep_t *gr)
{
    rep_t *cpy = malloc(sizeof(rep_t));

    cpy->pos.x = gr->pos.x;
    cpy->pos.y = gr->pos.y;
    cpy->nb.x = gr->nb.x;
    cpy->nb.y = gr->nb.y;
    cpy->size.x = gr->size.x;
    cpy->size.y = gr->size.y;
    return cpy;
}
