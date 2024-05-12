/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** desc
*/
#include <fcntl.h>
#include "my.h"
#include <ncurses.h>
#include <stdlib.h>

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    return fd;
}

void ncurses(void)
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
}

void move_player(char **words, int a, int b, int c)
{
    int *x = &a;
    int *y = &b;

    if (c == 'q') {
        endwin();
        exit(0);
    }
    if (c == KEY_UP || c == 'w')
        move_up(words, x, y);
    if (c == KEY_DOWN || c == 's')
        move_down(words, x, y);
    if (c == KEY_RIGHT || c == 'd')
        move_right(words, x, y);
    if (c == KEY_LEFT || c == 'a')
        move_left(words, x, y);
}

void cond_usage(char **av)
{
    my_putstr("USAGE\n");
    my_putstr("    ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    map file representing the warehouse ");
    my_putstr("map, containing '#' for walls,\n");
    my_putstr("        'P' for the player, 'X' for boxes ");
    my_putstr("and 'O' for storage locations.\n");
}
