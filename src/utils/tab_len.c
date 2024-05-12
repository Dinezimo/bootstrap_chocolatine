/*
** EPITECH PROJECT, 2024
** MINISHELL 1
** File description:
** Function to count number of line of an array
*/

#include "../../include/utils.h"

int tab_len(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return i;
}
