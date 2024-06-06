/*
** EPITECH PROJECT, 2023
** projet c
** File description:
** réplique de len
*/
#include "paint.h"
int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
