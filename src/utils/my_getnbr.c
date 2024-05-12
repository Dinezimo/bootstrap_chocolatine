/*
** EPITECH PROJECT, 2023
** getnbr
** File description:
** prendre le nombre uniquement
*/

#include "../../include/utils.h"

// int my_getnbr(char const *str)
// {
//     int s = 1;
//     int n = 0;
//     int t;
//     int i = 0;

//     for (; is_sign(str[i]); i++)
//         s *= str[i] == '-' ? -1 : 1;
//     while (str[i] >= '0' && str[i] <= '9') {
//         t = str[i] - 48;
//         n = (n * 10) + t;
//         i++;
//     }
//     return n * s;
// }

int my_getnbr(char const *str)
{
    int s = 1;
    int n = 0;
    int i = 0;

    for (; is_sign(str[i]); i++)
        s *= str[i] == '-' ? -1 : 1;
    for (; str[i]; i++)
        n = (n * 10) + (str[i] - 48);
    return n * s;
}
