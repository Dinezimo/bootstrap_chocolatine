/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to edit tools
*/
#include "paint.h"
tool_t *just_edit(tool_t *el, int len)
{
    char *l[] = {"pencil.png", "t.jpg", "eraser.jpg", "shape.jpg", NULL};
    sfFont* font = sfFont_createFromFile("name_pol.ttf");
    tool_t *spr = sprites_list(l, len);
    sfVector2f tmp;

    for (int i = 0; i < len; i++) {
        sfRectangleShape_setTexture(el[i].r, spr[i].texture, sfTrue);
        sfRectangleShape_setOutlineThickness(el[i].r, 2);
        sfRectangleShape_setOutlineColor(el[i].r, sfBlack);
        el[i].txt = tool_name(el[i].name, font);
        tmp = sfRectangleShape_getPosition(el[i].r);
        sfText_setPosition(el[i].txt, tmp);
    }
    return el;
}

tool_t *edit(void)
{
    char *l[] = {"pencil", "text", "eraser", "shape", NULL};
    rep_t *gr = malloc(sizeof(rep_t));

    gr->pos = (sfVector2f){180, 80};
    gr->nb = (sfVector2f){1, 4};
    gr->size = (sfVector2f){150, 280};
    return just_edit(tool_parts(l, 4, gr), 4);
}
