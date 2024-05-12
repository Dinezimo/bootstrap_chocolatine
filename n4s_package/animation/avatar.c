/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to build avatar
*/

#include "../main/paint.h"

samourai_t **avatar_creation(void)
{
    samourai_t **av = malloc(sizeof(samourai_t *) * 7);

    av[0] = charge_red();
    av[1] = charge_green();
    av[2] = charge_princess();
    av[3] = charge_soldier();
    return av;
}
