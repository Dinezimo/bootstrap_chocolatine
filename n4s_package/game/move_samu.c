/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to move samurai
*/

#include "../main/paint.h"

samourai_t *init_samourai(char *str)
{
    samourai_t *tmp = malloc(sizeof(samourai_t));

    tmp->s = spriteFromFile(str);
    sfSprite_setPosition(tmp->s, (sfVector2f){700, 800});
    tmp->s_c = sfClock_create();
    tmp->i = 0;
    tmp->j = 0;
    tmp->s_dir = 'n';
    tmp->atk = 0;
    tmp->dead = 0;
    tmp->def = 0;
    tmp->hit = 0;
    tmp->dle = 0;
    return tmp;
}

int direction_evt(samourai_t *s)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        s->i = 48;
        return 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        s->i = 96;
        return 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        s->i = 144;
        return 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        s->i = 0;
        return 0;
    }
    return -1;
}

void sa_moving(samourai_t *s)
{
    sfTime t = sfClock_getElapsedTime(s->s_c);

    if (sfTime_asSeconds(t) > 0.1f) {
        s->j += 48;
        if (s->j >= 144)
            s->j = 0;
        s->s_r = (sfIntRect){s->j, s->i, 48, 48};
        sfSprite_setTextureRect(s->s, s->s_r);
        sfClock_restart(s->s_c);
    }
}
