/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to main
*/
#include "../my.h"

int main(int ac, char **av)
{
    char **map;

    if (ac != 4)
        return 84;
    if (error_case(ac, av) == 84)
        return 84;
    map = get_map(av[1], av[2]);
    free(map);
    return 0;
}
