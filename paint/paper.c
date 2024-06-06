/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to define the draw surface
*/
#include "paint.h"
#include <string.h>
sfSprite *paper_definition(sfSprite *paper, win_t *w)
{
    sfTexture *paper_t;

    w->img = sfImage_createFromColor(1500, 800, sfWhite);
    paper_t = sfTexture_createFromImage(w->img, NULL);
    paper = sfSprite_create();
    sfSprite_setTexture(paper, paper_t, sfTrue);
    sfSprite_setPosition(paper, (sfVector2f){200, 100});
    return paper;
}

void temp(sfImage *img, sfColor col, sfVector2i m, int e)
{
    for (int o = 0; o < e; o++)
        for (int l = 0; l < e; l++)
            sfImage_setPixel(img, m.x + o, m.y + l, col);
}

void draw_in_paper(sfSprite *p, sfColor col, win_t *w, int e)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow(w->win);
    sfVector2f sprite_position = sfSprite_getPosition(p);
    sfVector2i m;
    sfTexture *to;
    sfFloatRect rp = sfSprite_getGlobalBounds(p);

    m.x = mouse_position.x - sprite_position.x;
    m.y = mouse_position.y - sprite_position.y;
    if (sfFloatRect_contains(&rp, m.x, m.y)) {
        temp(w->img, col, m, e);
        to = (sfTexture *)sfSprite_getTexture(p);
        sfTexture_updateFromImage(to, w->img, 0, 0);
    }
}
