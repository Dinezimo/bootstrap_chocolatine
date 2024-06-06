/*
** EPITECH PROJECT, 2024
** project C
** File description:
** paint main
*/

#include "paint.h"
#include <string.h>

int main(void)
{
    win_t *w = init_window();
    st_t *p = malloc(sizeof(st_t));
    co_t *c = col_init();

    p = state(p);
    is_open(w, p, c);
    destroy_res(w);
    return 0;
}
