/*
** EPITECH PROJECT, 2023
** my
** File description:
**  contains the prototypes of all the functions exposed by your libmy.a
*/

#ifndef TRIGO_H
    #define TRIGO_H
    #include <math.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <fcntl.h>
    #include <criterion/criterion.h>
    #include <criterion/redirect.h>

char **get_map(char *str, char *f);
int lines_nbr(char *buffer);
int world_nbr(char *str);
char *last_str(char *str);
int error_buffer(char *str);
int error_map(char **map, int n);
int error_case(int argc, char **argv);
int error_case2(char *str, char *f);
int check(char c, char *str);
int my_strlen(char *str);
#endif
