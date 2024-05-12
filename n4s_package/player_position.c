/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** desc
*/

#include "my.h"
#include <stdlib.h>
#include <ncurses.h>

int *player_position(char **str)
{
    int a;
    int b;
    int *tab = malloc(sizeof(int) * 2);

    for (a = 0; str[a] != NULL; a++)
        for (b = 0; str[a][b] != '\0'; b++) {
            tab[0] = str[a][b] == 'P' ? a : tab[0];
            tab[1] = str[a][b] == 'P' ? b : tab[1];
        }
    return tab;
}

int o_pos(char **str2)
{
    int c = 0;

    for (int a = 0; str2[a] != NULL; a++) {
        for (int b = 0; str2[a][b] != '\0'; b++)
            c = str2[a][b] == 'O' ? c + 1 : c;
    }
    return c;
}

void secur(void)
{
    endwin();
    exit(0);
}

int end_game(char **str, char **str2)
{
    int c = 0;

    for (int a = 0; str[a] != NULL; a++)
        for (int b = 0; str[a][b] != '\0'; b++) {
            str[a][b] == 'O' && str2[a][b] == 'X' &&
            str2[a][b] == 'X' && o_pos(str2) == 0 ? secur() : str[a][b] == 'O'
            && str2[a][b] == 'X' && str2[a][b] == 'X' && o_pos(str2) == 0;
        }
    return c;
}

char **o_position(char **str1, char **str2)
{
    int c = 0;

    for (int a = 0; str2[a] != NULL; a++)
        for (int b = 0; str2[a][b] != '\0'; b++)
            str1[a][b] = str2[a][b] == 'O' &&
            str1[a][b] == ' ' ? 'O' : str1[a][b];
    return str1;
}
