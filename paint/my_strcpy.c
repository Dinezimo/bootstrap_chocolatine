/*
** EPITECH PROJECT, 2023
** projet c
** File description:
** copy from a string to another string
*/
#include "paint.h"

char *my_strdup(char *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 2));

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
