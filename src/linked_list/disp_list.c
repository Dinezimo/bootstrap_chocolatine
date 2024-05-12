/*
** EPITECH PROJECT, 2024
** disp_list.c
** File description:
** function to display my linked_list
*/

#include "../../include/linked_list.h"
#include "../../include/utils.h"

void disp_list(linked_list_t *list, void (*func)(void *data))
{
    node_t *actuel = list->begin;

    if (is_empty_list(list))
        return;
    while (actuel != NULL) {
        func(actuel->data);
        actuel = actuel->next;
    }
}
