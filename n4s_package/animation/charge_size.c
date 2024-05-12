/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to charge size
*/
#include "../main/paint.h"

void red_size(int i, samourai_t *s)
{
    if (i == 0) {
        s->sam_size = (sfVector2f){31, 54};
        s->sheet_size = (sfVector2f){248, 54};
    }
    if (i == 1 || i == 2) {
        s->sam_size = (sfVector2f){78, 54};
        s->sheet_size = (sfVector2f){624, 55};
    }
    if (i == 4 || i == 5) {
        s->sam_size = (sfVector2f){58, 55};
        s->sheet_size = (sfVector2f){348, 60};
    }
    if (i == 6) {
        s->sam_size = (sfVector2f){44, 55};
        s->sheet_size = (sfVector2f){220, 55};
    }
    if (i == 3) {
         s->sam_size = (sfVector2f){55, 55};
        s->sheet_size = (sfVector2f){230, 55};
    }
    if (i == 7) {
        s->sam_size = (sfVector2f){60, 60};
        s->sheet_size = (sfVector2f){630, 55};
    }
}

void green_size(int i, samourai_t *s)
{
    s->sam_size = (sfVector2f){128, 128};
    if (i == 0)
        s->sheet_size = (sfVector2f){768, 128};
    if (i == 1)
        s->sheet_size = (sfVector2f){512, 128};
    if (i == 2)
        s->sheet_size = (sfVector2f){640, 128};
    if (i == 3)
        s->sheet_size = (sfVector2f){256, 128};
    if (i == 4)
        s->sheet_size = (sfVector2f){1024, 128};
    if (i == 5)
        s->sheet_size = (sfVector2f){1152, 128};
    if (i == 6)
        s->sheet_size = (sfVector2f){384, 128};
    if (i == 7)
        s->sheet_size = (sfVector2f){768, 128};
}

void maela_size(int i, samourai_t *s)
{
    s->sam_size = (sfVector2f){128, 128};
    if (i == 1 || i == 3)
        s->sheet_size = (sfVector2f){765, 128};
    if (i == 2 || i == 4 || i == 5)
        s->sheet_size = (sfVector2f){1000, 128};
    if (i == 0)
        s->sheet_size = (sfVector2f){1100, 128};
    if (i == 7)
        s->sheet_size = (sfVector2f){250, 128};
}

void samy_size(int i, samourai_t *s)
{
     s->sam_size = (sfVector2f){98, 98};
    if (i == 0 || i == 5)
        s->sheet_size = (sfVector2f){672, 96};
    if (i == 1 || i == 2 || i == 3 || i == 7)
        s->sheet_size = (sfVector2f){480, 96};
    if (i == 6)
        s->sheet_size = (sfVector2f){380, 96};
    if (i == 4)
        s->sheet_size = (sfVector2f){300, 128};
}
