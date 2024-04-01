/*
** EPITECH PROJECT, 2024
** error_case. c
** File description:
** error_case
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
int error_case1(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return 84;
}

int error_case2(char *str, char *f)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (check(str[i], f) != 0 && str[i] != '\n')
            exit(84);
}

int error_case(int argc, char **argv)
{
    if (error_case1(argv[3]) == 84)
        return 84;
    if (error_case1(argv[2]) == 84)
        return 84;
}
