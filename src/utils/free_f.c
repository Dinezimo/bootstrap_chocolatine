/*
** EPITECH PROJECT, 2024
** A MAZE D
** File description:
** Function  to free memory
*/

#include "../../include/utils.h"

void *free_f(void *ptr)
{
    if (ptr != 0)
        free(ptr);
    return 0;
}
