/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to set a good cursor
*/

#include "paint.h"

tool_t *smile_sprite(void)
{
    char *l[] = {"sourire.png", "content.png", "mine-rejouie.png", NULL};
    tool_t *sm = sprites_list(l, 3);
    double pos = 550;

    for (int i = 0; i < 3; i++) {
        sfSprite_setScale(sm[i].sprite, (sfVector2f){0.2, 0.2});
        sfSprite_setPosition(sm[i].sprite, (sfVector2f){pos, 620});
        pos += 225;
    }
    return sm;
}

tool_t *curs_sprite(win_t *w)
{
    char *l[] = {"crayon.png", "la-gomme.png", "log.png", NULL};
    tool_t *sm = sprites_list(l, 3);

    for (int i = 0; i < 2; i++)
        sfSprite_setScale(sm[i].sprite, (sfVector2f){0.1, 0.1});
    sfSprite_setPosition(sm[2].sprite, (sfVector2f){500, 200});
    return sm;
}

void cool_cursor(sfBool d, sfBool e, win_t *w)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(w->win);
    sfVector2f pos = (sfVector2f){mpos.x, mpos.y - 40};
    sfVector2f pos2 = (sfVector2f){mpos.x, mpos.y};

    if (d == 1 || e == 1)
        sfRenderWindow_setMouseCursorVisible(w->win, 0);
    if (d == 1) {
        sfSprite_setPosition(w->curs[0].sprite, pos);
        sfRenderWindow_drawSprite(w->win, w->curs[0].sprite, NULL);
    }
    if (e == 1) {
        sfSprite_setPosition(w->curs[1].sprite, pos2);
        sfRenderWindow_drawSprite(w->win, w->curs[1].sprite, NULL);
    }
}
