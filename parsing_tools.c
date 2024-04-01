/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** tools that I use to parse
*/
#include "my.h"

int lines_nbr(char *buffer)
{
    int i = 0;
    int nline = 0;

    for (i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            nline++;
    }
    return nline;
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

int world_nbr(char *str)
{
    int i = 0;
    int c = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            c++;
        i++;
    }
    return c + 1;
}
