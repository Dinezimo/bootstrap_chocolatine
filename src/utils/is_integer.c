/*
** EPITECH PROJECT, 2024
** ROBOT FACTORY
** File description:
** Function to check if a string is an integer
*/

#include "../../include/utils.h"

int is_integer(char const *str)
{
    int i = 0;

    if (str[i] == '-')
        i++;
    for (; str[i]; i++) {
        if (!is_digit(str[i]))
            return 0;
    }
    if (i == 0)
        return 0;
    return 1;
}
