/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to charge all sprite
*/
#include "../main/paint.h"

samourai_t *charge_red(void)
{
    samourai_t *h = malloc(sizeof(samourai_t) * 9);

    h[2] = *(init_samourai("animation/assets/red/atk2.png"));
    h[7] = *(init_samourai("animation/assets/red/death .png"));
    h[6] = *(init_samourai("animation/assets/red/hit taken.png"));
    h[0] = *(init_samourai("animation/assets/red/Idle.png"));
    h[5] = *(init_samourai("animation/assets/red/run left .png"));
    h[4] = *(init_samourai("animation/assets/red/run right.png"));
    h[3] = *(init_samourai("animation/assets/red/landing.png"));
    h[1] = *(init_samourai("animation/assets/red/atk1 .png"));

    for (int i = 0; i < 8; i++)
        sfSprite_setScale(h[i].s, (sfVector2f){2, 2});
    return h;
}

samourai_t *charge_green(void)
{
    samourai_t *h = malloc(sizeof(samourai_t) * 9);

    h[1] = *(init_samourai("animation/assets/green/Attack_1.png"));
    h[2] = *(init_samourai("animation/assets/green/Attack_2.png"));
    h[7] = *(init_samourai("animation/assets/green/Dead.png"));
    h[6] = *(init_samourai("animation/assets/green/Hurt.png"));
    h[0] = *(init_samourai("animation/assets/green/Idle.png"));
    h[4] = *(init_samourai("animation/assets/green/Run.png"));
    h[3] = *(init_samourai("animation/assets/green/Protection.png"));
    h[5] = *(init_samourai("animation/assets/green/Walk.png"));
    return h;
}

samourai_t *charge_princess(void)
{
    samourai_t *h = malloc(sizeof(samourai_t) * 9);

    h[1] = *(init_samourai("animation/assets/princess/atk.png"));
    h[2] = *(init_samourai("animation/assets/princess/atk2.png"));
    h[7] = *(init_samourai("animation/assets/princess/death.png"));
    h[6] = *(init_samourai("animation/assets/princess/hurt.png"));
    h[0] = *(init_samourai("animation/assets/princess/dlle.png"));
    h[4] = *(init_samourai("animation/assets/princess/Run.png"));
    h[3] = *(init_samourai("animation/assets/princess/def.png"));
    h[5] = *(init_samourai("animation/assets/princess/Walk.png"));
    for (int i = 0; i < 8; i++) {
        sfSprite_setScale(h[i].s, (sfVector2f){2, 2});
        sfSprite_setPosition(h[i].s, (sfVector2f){1500, 650});
    }
    return h;
}

samourai_t *charge_soldier(void)
{
    samourai_t *h = malloc(sizeof(samourai_t) * 9);

    h[2] = *(init_samourai("animation/assets/soldier/Attack_2.png"));
    h[7] = *(init_samourai("animation/assets/soldier/Dead.png"));
    h[6] = *(init_samourai("animation/assets/soldier/Hurt.png"));
    h[0] = *(init_samourai("animation/assets/soldier/Idle.png"));
    h[1] = *(init_samourai("animation/assets/soldier/Attack_1.png"));
    h[4] = *(init_samourai("animation/assets/soldier/Run.png"));
    h[3] = *(init_samourai("animation/assets/soldier/Blade.png"));
    h[5] = *(init_samourai("animation/assets/soldier/Walk.png"));
    for (int i = 0; i < 8; i++) {
        sfSprite_setScale(h[i].s, (sfVector2f){1.1, 1.1});
        sfSprite_setPosition(h[i].s, (sfVector2f){1500, 800});
    }
    return h;
}
