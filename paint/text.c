/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to write a text
*/

#include "paint.h"
sfText *tool_name(char *str, sfFont *font)
{
    sfText *txt = sfText_create();

    sfText_setString(txt, str);
    sfText_setFont(txt, font);
    sfText_setCharacterSize(txt, 20);
    sfText_setColor(txt, sfBlack);
    return txt;
}
