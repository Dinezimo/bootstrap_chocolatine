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

int move_rightt(char **words, int *x, int *y)
{
    if (words[*x][*y + 2] == 'X' &&
        words[*x][*y + 1] == 'X') {
        words[*x][*y + 2] = 'X';
        words[*x][*y + 1] = 'X';
        return 0;
    }
    if (words[*x][*y + 2] != '#' &&
        words[*x][*y + 1] == 'X') {
        words[*x][*y] = ' ';
        words[*x][*y + 1] = 'P';
        words[*x][*y + 2] = 'X';
    }
    if (words[*x][*y + 1] != '#') {
        words[*x][*y] = ' ';
        words[*x][*y + 1] = 'P';
    }
    return 0;
}

int move_right(char **words, int *x, int *y)
{
    if (words[*x][*y + 1] == '#') {
        words[*x][*y] = 'P';
        return 0;
    }
    if (words[*x][*y + 2] == '#' &&
        words[*x][*y + 1] == 'X') {
        words[*x][*y + 1] = 'X';
        words[*x][*y] = 'P';
        return 0;
    }
    move_rightt(words, x, y);
}

int move_leftt(char **words, int *x, int *y)
{
    if (words[*x][*y - 2] == 'X' &&
        words[*x][*y - 1] == 'X') {
        words[*x][*y - 2] = 'X';
        words[*x][*y - 1] = 'X';
        return 0;
    }
    if (words[*x][*y - 2] != '#' &&
        words[*x][*y - 1] == 'X') {
        words[*x][*y] = ' ';
        words[*x][*y - 1] = 'P';
        words[*x][*y - 2] = 'X';
    }
    if (words[*x][*y - 1] != '#') {
        words[*x][*y] = ' ';
        words[*x][*y - 1] = 'P';
    }
    return 0;
}

int move_left(char **words, int *x, int *y)
{
    if (words[*x][*y - 1] == '#') {
        words[*x][*y] = 'P';
        return 0;
    }
    if (words[*x][*y - 2] == '#' &&
        words[*x][*y - 1] == 'X') {
        words[*x][*y - 1] = 'X';
        words[*x][*y] = 'P';
        return 0;
    }
    move_leftt(words, x, y);
}
