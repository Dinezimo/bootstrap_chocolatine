/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to compute
*/

#include "my.h"

int smallest_vector(double *l, int len, int a)
{
    int assini = a;

    for (int i = a; i < a + len; i++)
        if (l[i] < l[assini])
            assini = i;
    return assini;
}

double conversio(double x, double *A, double *B)
{
    return  (x - A[0]) / (A[1] - A[0]) * (B[1] - B[0]) + B[0];
}

char *my_concat_params(char* str1, char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t t = len1 + len2 + 1;

    char* result = (char*)malloc(sizeof(char) * t);
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

void avancer(double vit)
{
    char *buf =  malloc(sizeof(char) * 200);
    size_t size = 200;
    char *str = double_to_string(vit);

    str = my_concat_params("car_forward:", str);
    str = my_concat_params(str, "\n");
    write(1, str, strlen(str));
    getline(&buf, &size, stdin);
    free(buf);
}

void reculer(double vit)
{
    char *buf =  malloc(sizeof(char) * 200);
    size_t size = 200;
    char *str = double_to_string(vit);

    str = my_concat_params("car_backwards:", str);
    str = my_concat_params(str, "\n");
    write(1, str, strlen(str));
    getline(&buf, &size, stdin);
    free(buf);
}
