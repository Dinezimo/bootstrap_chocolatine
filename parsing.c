/*
** EPITECH PROJECT, 2024
** projet C
** File description:
** to get information in a file
*/

#include "my.h"

char **mem_alloc2(int nb_rows, int nb_cols)
{
    char **j;
    int k = 0;

    j = malloc(sizeof(char *) * (nb_rows + 5));
    for (k = 0; k < nb_rows; k++)
        j[k] = malloc(sizeof(char) * (nb_cols + 5));
    return j;
}

char **str_to_arrays(char *str)
{
    int l = 0;
    int k = 0;
    int i = 0;
    int j = 0;
    char **tab = mem_alloc2(lines_nbr(str), strlen(str));

    for (l = 0; str[l] != '\0'; l++) {
        if (str[l] == '\n') {
            tab[i][k] = '\0';
            k = 0;
            i++;
        } else {
            tab[i][k] = str[l];
            k++;
        }
    }
    tab[i] = NULL;
    return tab;
}

char **get_map(char *str, char *f)
{
    char **map;
    char *buffer;
    int fd = open(str, O_RDONLY);

    if (fd == -1)
        exit(84);
    buffer = malloc(sizeof(char) * 300);
    read(fd, buffer, 300);
    if (strlen(buffer) == 0 || error_buffer(buffer) == -1)
        exit(84);
    error_case2(buffer, f);
    map = str_to_arrays(buffer);
    if (error_map(map, lines_nbr(buffer)) != 0)
        exit(84);
    free(buffer);
    return map;
}
