/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to anime a sprite
*/
#include "../main/paint.h"

void anim_charact_j(samourai_t *s, int leng, sfVector2f size)
{
    sfTime t = sfClock_getElapsedTime(s->s_c);

    if (sfTime_asSeconds(t) > 0.06f) {
        s->j += size.x;
        if (s->j >= leng)
            s->j = 0;
        s->s_r = (sfIntRect){s->j, s->i, size.x, size.y};
        sfSprite_setTextureRect(s->s, s->s_r);
        sfClock_restart(s->s_c);
    }
}

int direction_char(samourai_t *s, samourai_t *r)
{
    sfVector2f pos;

    s->i = 0;
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        pos = sfSprite_getPosition(s[5].s);
        s->i = 5;
        sfSprite_move(s[5].s, (sfVector2f){-0.3, 0.0});
        for (int i = 0; i < 8; i++)
            if (i != 5)
            sfSprite_setPosition(r[i].s, pos);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        pos = sfSprite_getPosition(s[4].s);
        s->i = 4;
        sfSprite_move(s[4].s, (sfVector2f){0.3, 0.0});
        for (int i = 0; i < 8; i++)
            if (i != 4)
            sfSprite_setPosition(r[i].s, pos);
    }
    if (sfKeyboard_isKeyPressed(sfKeyA))
        s->i = my_rand_int(1, 2);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        s->i = 3;
    return 0;
}
