/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to define ai inputs
*/
#include "../main/paint.h"

double distanc_sprite(sfSprite *sprite1, sfSprite *sprite2) {
    sfFloatRect r1 = sfSprite_getGlobalBounds(sprite1);
    sfFloatRect r2 = sfSprite_getGlobalBounds(sprite2);

    double cY1 = r1.top + r1.height / 2;
    double cX1 = r1.left +r1.width / 2;
    double cX2 = r2.left +r2.width / 2;
    double cY2 = r2.top + r2.height / 2;
    double dx = cX1 - cX2;
    double dy = cY1 - cY2;
    return sqrt(dx * dx + dy * dy);
}

void interractions(samourai_t *h, samourai_t *ads)
{
    double p2 = sfSprite_getPosition(ads->s).x;
    double p1 = sfSprite_getPosition(h->s).x;
    double d = distanc_sprite(h->s, ads->s);

    if (d > 50) {
        ads->i = my_rand_int(0, 1);
            if (ads->i != 0)
                ads->i = (p1 < p2) ? 5 : 4;
    } else {
        if (h->atk) {
            ads->i = my_rand_int(0, 3);
            h_atk_manager(ads->i, h, ads);
        }
        if (h->dle) {
            ads->i = my_rand_int(0, 2);
            h_atk_manager(ads->i, h, ads);
        }
        if (h->def)
            ads->i = 4;
        if (h->hit) {
            h->i = my_rand_int(0, 3);
            h->hit = 0;
        }
        if (ads->hit) {
            ads->i = my_rand_int(0, 3);
            ads->hit = 0;
        }
    }
}

void ads_behavior(samourai_t *ads)
{
    sfVector2f pos = sfSprite_getPosition(ads[0].s);

    if (ads->i == 4 && pos.x < 1800) {
        pos = sfSprite_getPosition(ads[4].s);
        sfSprite_move(ads[4].s, (sfVector2f){0.3, 0.0});
        for (int i = 0; i < 8; i++)
            if (i != 4)
            sfSprite_setPosition(ads[i].s, pos);
    } else if (ads->i == 5 && pos.x > 5) {
        pos = sfSprite_getPosition(ads[5].s);
        sfSprite_move(ads[5].s, (sfVector2f){-0.3, 0.0});
        for (int i = 0; i < 8; i++)
            if (i != 5)
            sfSprite_setPosition(ads[i].s, pos);
    }
}
