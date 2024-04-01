/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to manage all erreor cases
*/
#include "my.h"

int error_buffer(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' && str[i] != '\n' || str[i] > '9')
            return -1;
    }
    return 0;
}

int check(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return 0;
    return -1;
}

int error_map(char **map, int n)
{
    for (int i = 0; map[i] != NULL; i++)
        if (strlen(map[i]) != n)
            return -1;
    return 0;
}
