/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to draw
*/
#include "paint.h"
void display_tools(tool_t *l, int len, sfRenderWindow* win)
{
    for (int i = 0; i < len; i++) {
        sfRenderWindow_drawRectangleShape(win, l[i].r, NULL);
        sfRenderWindow_drawText(win, l[i].txt, NULL);
    }
}

void display_tools2(tool_t *l, int len, sfRenderWindow* win)
{
    for (int i = 0; i < len; i++)
        sfRenderWindow_drawRectangleShape(win, l[i].r, NULL);
}
