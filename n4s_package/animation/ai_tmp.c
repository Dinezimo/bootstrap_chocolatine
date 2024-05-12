/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** checking
*/
#include "../main/paint.h"

void h_atk_manager(int i, samourai_t *h, samourai_t *ads)
{
    if (i == 1 || i == 2)
        h->i = 6;
    if (i == 0)
        ads->i = 6;
    if (i == 3)
        ads->i = 3;
}
