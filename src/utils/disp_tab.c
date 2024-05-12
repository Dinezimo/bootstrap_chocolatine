/*
** EPITECH PROJECT, 2024
** A MAZE D
** File description:
** function to display a 2d_array
*/

#include "../../include/utils.h"

void disp_mat_room(char **tab)
{
    int i = 0;

    for (; tab[i + 1]; i++) {
        my_putstr(tab[i]);
        my_putchar(' ');
    }
    my_putstr(tab[i]);
    my_putchar('\n');
    return;
}

void disp_mat_pipe(char **tab)
{
    int i = 0;

    for (; tab[i + 1]; i++) {
        my_putstr(tab[i]);
        my_putchar('-');
    }
    my_putstr(tab[i]);
    my_putchar('\n');
    return;
}
