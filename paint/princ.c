/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** just prainc
*/

#include "paint.h"
char *name(char *str)
{
    int i = 0;
    char *cpy = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (i = 0; str[i] != '.'; i++)
        cpy[i] = str[i];
    cpy[i] = '\0';
}

tool_t *just_princ(tool_t *el, int len)
{
    char *l[] = {"file.jpg", "edit.jpg", "help.jpg", NULL};
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
