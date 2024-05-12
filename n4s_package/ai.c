/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to make bootstrap
*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "my.h"

void tourner(double res)
{
    char *buf =  malloc(sizeof(char) * 200);
    size_t size = 200;
    char *str = double_to_string(res);

    str = my_concat_params("WHEELS_DIR:", str);
    str = my_concat_params(str, "\n");
    write(1, str, strlen(str));
    getline(&buf, &size, stdin);
    free(buf);
}

double pourcentage_in_intervall(double c, double a, double b)
{
    return (c - a) / (b - a);
}

void vitesse(double lead)
{
    double A[2] = {10, 50};
    double B[2] = {0, 0.1};
    double C[2] = {51, 500};
    double D[2] = {0.1, 0.2};
    double min = conversio(lead, A, B);
    double moy = conversio(lead, C, D);

    if (lead <= 500)
        avancer(min);
    if (lead > 500 && lead < 1000)
        avancer(moy);
    if (lead > 1000)
        avancer(0.3);
    if (lead < 50) {
        reculer(0.6);
    }
    //avancer(0.01);
}

void collision(current_t *flash)
{
    static double d;
    double A[2] = {0, 60};
    double B[2] = {-1, 1};
    double C[3] = {flash->lidar[0], flash->lidar[15], flash->lidar[30]};
    int way = biggest_vector(C, 3, 0);
    int sm = smallest_vector(C, 3, 0);
    double angle = way * 60.0 / 32;

    angle = conversio(angle, A, B);
    vitesse(flash->lidar[15]);
    if (way == 1)
        tourner(0.0);
    else if (way == 0) {
        tourner(-1 * angle);
        avancer(0.01);
    } else {
        tourner(angle);
        avancer(0.01);
    }
    /*if (sm == 0)
        tourner();
    else if() {

    }*/
}

void objectif1(void)
{
    char *buf = malloc(sizeof(char) * 200);
    size_t size = 200;
    current_t *flash = malloc(sizeof(current_t));

    write(1, "START_SIMULATION\n", 17);
    getline(&buf, &size, stdin);
    write(2, buf, sizeof(buf));
    while (1) {
        flash = data_updating(flash);
        collision(flash);
    }
    free(buf);
}

int main(int ac, char **av)
{
    objectif1();
}
