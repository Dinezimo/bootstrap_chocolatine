/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to compute
*/
#include "my.h"

char *double_to_string(double value) {
    char* str = (char*) malloc(sizeof(char) * 20);

    sprintf(str, "%.3f", value);
    return str;
}

current_t *data_updating2(current_t *flash)
{
    size_t size = 200;
    char *buf = malloc(sizeof(char) * 200);

    write(1, "GET_INFO_LIDAR\n", 15);
    getline(&buf, &size, stdin);
    flash->lidar = lidar_treating(strdup(buf));
    bzero(buf, strlen(buf));
    write(1, "GET_CURRENT_SPEED\n", 18);
    getline(&buf, &size, stdin);
    flash->speed = standart_treating(buf);
    bzero(buf, strlen(buf));
    free(buf);
    return flash;
}

current_t *data_updating(current_t *flash)
{
    size_t size = 200;
    char *buf = malloc(sizeof(char) * 200);

    flash = data_updating2(flash);
    write(1, "GET_CAR_SPEED_MAX\n", 18);
    getline(&buf, &size, stdin);
    flash->max_speed = standart_treating(buf);
    bzero(buf, strlen(buf));
    write(1, "GET_CAR_SPEED_MIN\n", 18);
    getline(&buf, &size, stdin);
    flash->min_speed = standart_treating(buf);
    bzero(buf, strlen(buf));
    write(1, "GET_CURRENT_WHEELS\n", 19);
    getline(&buf, &size, stdin);
    flash->wheel = standart_treating(buf);
    free(buf);
    return flash;
}
int biggest_vector(double *l, int len, int a)
{
    int assini = 0;

    for (int i = a; i < a + len; i++)
        if (l[i] > l[assini])
            assini = i;
    return assini;
}
