/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to concept gaming.c
*/

#include "../main/paint.h"

sfSprite *looping_display(cin_t *p)
{
    p->background = malloc(sizeof(sfSprite*) * 10);
    p->background[0] = spriteFromFile("animation/assets/frames/f0.gif");
    p->background[1] = spriteFromFile("animation/assets/frames/f1.gif");
    p->background[2] = spriteFromFile("animation/assets/frames/f2.gif");
    p->background[3] = spriteFromFile("animation/assets/frames/f3.gif");
    p->background[4] = spriteFromFile("animation/assets/frames/f4.gif");
    p->background[5] = spriteFromFile("animation/assets/frames/f5.gif");
    p->background[6] = spriteFromFile("animation/assets/frames/f6.gif");
    for (int i = 0; i < 7; i++)
        sfSprite_setScale(p->background[i], (sfVector2f){2, 2.8});
}

void perso_loading(cin_t *p)
{
    p->persos = malloc(sizeof(sfSprite*) * 10);
    p->persos[0] = spriteFromFile("main/assets/antoine.png");
    p->persos[1] = spriteFromFile("main/assets/green.png");
    p->persos[2] = spriteFromFile("main/assets/lady.png");
}