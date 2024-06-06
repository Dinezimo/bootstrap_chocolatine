/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** draw manual
*/

#include "paint.h"

sfText *get_man(char *str)
{
    char buffer[100000];
    int fd = open(str, O_RDONLY);
    sfFont* font = sfFont_createFromFile("name_pol.ttf");
    sfText *man;

    read(fd, buffer, 10000);
    man = tool_name(buffer, font);
    sfText_setPosition(man, (sfVector2f){500, 250});
    close(fd);
    return man;
}

sfRectangleShape *man_back(void)
{
    sfRectangleShape* cadre = sfRectangleShape_create();

    sfRectangleShape_setSize(cadre, (sfVector2f){1000, 500});
    sfRectangleShape_setFillColor(cadre, sfColor_fromRGB(240, 182, 216));
    sfRectangleShape_setPosition(cadre, (sfVector2f){500, 250});
    return cadre;
}
