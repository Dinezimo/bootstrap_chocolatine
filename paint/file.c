/*
** EPITECH PROJECT, 2024
** project c
** File description:
** to create tools arrays
*/
#include "paint.h"

tool_t *just_file(tool_t *el, int len)
{
    char *l[] = {"new.jpg", "save.jpg", "import.jpg", NULL};
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

tool_t *file(void)
{
    char *l[] = {"new", "save", "import", NULL};
    rep_t *gr = malloc(sizeof(rep_t));

    gr->pos = (sfVector2f){30, 80};
    gr->nb = (sfVector2f){1, 3};
    gr->size = (sfVector2f){150, 250};
    return just_file(tool_parts(l, 3, gr), 3);
}
