/*
** EPITECH PROJECT, 2024
** A MAZE D
** File description:
** Function to check if a line is empty or not
*/

#include "../../include/utils.h"

int is_empty_line(char *str)
{
    for (int i = 0; str[i] != '\n'; i++)
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            return 0;
    return 1;
}
