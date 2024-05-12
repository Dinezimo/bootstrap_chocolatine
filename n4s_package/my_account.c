/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** desc
*/
#include <stdio.h>

int point(char const *str)
{
    int i = 0;
    int o = 0;

    if (*str == '\0')
        return 84;
    while (str[i] != '\0') {
        if (str[i] == 'O') {
            o++;
        }
        i++;
    }
    return (o);
}

int player(char const *str)
{
    int i = 0;
    int p = 0;

    if (*str == '\0')
        return 84;
    while (str[i] != '\0') {
        if (str[i] == 'P') {
            p++;
        }
        i++;
    }
    return (p);
}

int objet(char const *str)
{
    int i = 0;
    int x = 0;

    if (*str == '\0')
    return 84;
    while (str[i] != '\0') {
        if (str[i] == 'X') {
            x++;
        }
        i++;
    }
    return (x);
}
