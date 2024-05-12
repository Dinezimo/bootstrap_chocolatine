/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to update charact state
*/
#include "../main/paint.h"

void charge_state(samourai_t *s)
{
    s->atk = (s->i == 1 || s->i == 2) ? 1 : 0;
    s->dead = (s->i == 7) ? 1 : 0;
    s->def = (s->i == 3) ? 1 : 0;
    s->dle = (s->i == 0) ? 1 : 0;
    s->hit = (s->i == 6) ? 1 : 0;
}

sfSprite *looping_display1(cin_t *p)
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