/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to compute
*/
#include "my.h"

char **my_strtok_version1(char *str, char *sep)
{
    int c = 0;
    char **macho = malloc(sizeof(char *) * (strlen(str) + 5));
    char *momo = strdup(str);
    char *london = strtok(momo, sep);

    while (london != NULL) {
        macho[c] = strdup(london);
	london = strtok(NULL, sep);
        c++;
    }
    return macho;
}

void free_array(char **map)
{
    if (map == NULL)
        return;
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}

double *lidar_treating(char *str)
{
    int i = 3;
    char **map = my_strtok_version1(str, ":");
    double *l = malloc(sizeof(double) * 34);

    for (i = 3; map[i + 1]!= NULL; i++)
        l[i - 3] = atof(map[i]);
    l[i - 3] = -1;
    free_array(map);
    return l;
}

double standart_treating(char *str)
{
    char **map = my_strtok_version1(str, "\n:");
    double res = atof(map[3]);

    return res;
}

double standart_treating1(char *str)
{
    char **map = my_strtok_version1(str, "\n:");
    double res = atof(map[4]);

    return res;
}
