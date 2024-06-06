/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to list color
*/

#include "paint.h"

char **str_list(void)
{
    char **m = malloc(sizeof(char *) * 12);

    m[0] = my_strdup("red");
    m[1] = my_strdup("blue");
    m[2] = my_strdup("black");
    m[3] = my_strdup("yellow");
    m[4] = my_strdup("kn");
    m[5] = my_strdup("lfjd");
    m[6] = my_strdup("ljn");
    m[7] = my_strdup("momo");
    m[8] = NULL;
    return m;
}

sfColor *col_list(void)
{
    sfColor *c = malloc(sizeof(sfColor) * 12);

    c[0] = sfRed;
    c[1] = sfBlue;
    c[2] = sfBlack;
    c[3] = sfYellow;
    c[4] = sfWhite;
    c[5] = sfCyan;
    c[6] = sfMagenta;
    c[7] = sfGreen;
    return c;
}
