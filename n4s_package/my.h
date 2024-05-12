/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to contain proto
*/

#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    double *lidar;
    double wheel;
    double speed;
    double max_speed;
    double min_speed;
}current_t;

char **my_strtok_version1(char *str, char *sep);
void free_array(char **map);
double *lidar_treating(char *str);
double standart_treating(char *str);
double standart_treating1(char *str);
current_t *data_updating2(current_t *flash);
current_t *data_updating(current_t *flash);
int biggest_vector(double *l, int len, int a);
int smallest_vector(double *l, int len, int a);
double conversio(double x, double *A, double *B);
void avancer(double vit);
void reculer(double vit);
void tourner(double res);
double pourcentage_in_intervall(double c, double a, double b);
void collision(current_t *flash);
void objectif1(void);
int n4s_win(int argc, char *argv[]);
int learn_win(int argc, char *argv[]);
int rpg_ai(int argc, char *argv[]);
char *double_to_string(double value);
void sokoban_ai(int argc, char *argv[]);
int quizz(int argc, char *argv[]);
char *my_concat_params(char* str1, char* str2);