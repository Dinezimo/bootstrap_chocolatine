/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** desc
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include <stdlib.h>
#include <ncurses.h>

int move_upp(char **words, int *x, int *y)
{
    if (words[*x - 2][*y] == 'X' &&
        words[*x - 1][*y] == 'X') {
        words[*x - 2][*y] = 'X';
        words[*x - 1][*y] = 'X';
        return 0;
    }
    if (words[*x - 2][*y] != '#' &&
        words[*x - 1][*y] == 'X') {
        words[*x][*y] = ' ';
        words[*x - 1][*y] = 'P';
        words[*x - 2][*y] = 'X';
        return 0;
    }
    if (words[*x - 1][*y] != '#') {
        words[*x][*y] = ' ';
        words[*x - 1][*y] = 'P';
        return 0;
    }
    return 0;
}

int move_up(char **words, int *x, int *y)
{
    if (words[*x - 1][*y] == '#') {
        words[*x][*y] = 'P';
        return 0;
    }
    if (words[*x - 2][*y] == '#' &&
        words[*x - 1][*y] == 'X') {
        words[*x - 1][*y] = 'X';
        words[*x][*y] = 'P';
        return 0;
    }
    move_upp(words, x, y);
}

int move_downn(char **words, int *x, int *y)
{
    if (words[*x + 2][*y] == 'X' &&
        words[*x + 1][*y] == 'X') {
        words[*x + 2][*y] = 'X';
        words[*x + 1][*y] = 'X';
        return 0;
    }
    if (words[*x + 2][*y] != '#' &&
        words[*x + 1][*y] == 'X') {
        words[*x][*y] = ' ';
        words[*x + 1][*y] = 'P';
        words[*x + 2][*y] = 'X';
    }
    if (words[*x + 1][*y] != '#') {
        words[*x][*y] = ' ';
        words[*x + 1][*y] = 'P';
    }
    return 0;
}

int move_down(char **words, int *x, int *y)
{
    if (words[*x + 1][*y] == '#') {
        words[*x][*y] = 'P';
        return 0;
    }
    if (words[*x + 2][*y] == '#' &&
        words[*x + 1][*y] == 'X') {
        words[*x + 1][*y] = 'X';
        words[*x][*y] = 'P';
        return 0;
    }
    move_downn(words, x, y);
}
