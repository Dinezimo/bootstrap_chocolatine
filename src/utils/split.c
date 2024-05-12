/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to convert a string into string array
*/

#include "../../include/utils.h"

// char **split(char const *str, int (*func)(char))
// {
//     int c = 0;
//     int nb_w = count_word(str, func);
//     int a = 0;
//     int b = 0;
//     int i = 0;
//     char **w_array = malloc(sizeof(char *) * (nb_w + 1));

//     for (c = 0; c < nb_w; c++) {
//         for (; !func(str[i]); i++);
//         a = 0;
//         b = i;
//         for (; str[i] && func(str[i]); i++)
//             a++;
//         w_array[c] = malloc(sizeof(char) * (a + 1));
//         jm_copy(w_array[c], &str[b], func);
//     }
//     w_array[c] = NULL;
//     return w_array;
// }

// char *my_strncpy(char *dest, char const *src, int n)
// {
//     int i;

//     for (i = 0; i < n && src[i] != '\0'; i++)
//         dest[i] = src[i];
//     for (; i < n; i++)
//         dest[i] = '\0';
//     return (dest);
// }

// int skip_delimiters1(char **str, const char *delimiters, int is_delimiter)
// {
//     is_delimiter = 0;
//     for (size_t i = 0; delimiters[i]; i++) {
//         if (**str == delimiters[i]) {
//             is_delimiter = 1;
//             break;
//         }
//     }
// }

// void skip_delimiters(char **str, const char *delimiters)
// {
//     int is_delimiter = 0;

//     while (**str) {
//         is_delimiter = skip_delimiters1(str, delimiters, is_delimiter);
//         if (!is_delimiter)
//             break;
//         (*str)++;
//     }
// }

// char *find_token(char **str, const char *delimiters)
// {
//     char *token_start = *str;
//     int token_length = 0;
//     int is_delimiter = 0;

//     while (**str) {
//             is_delimiter = skip_delimiters1(str, delimiters, is_delimiter);
//         if (is_delimiter)
//             break;
//         (*str)++;
//         token_length++;
//     }
//     return token_start;
// }

// char **formating(char *str, char *delimiters)
// {
//     int k = 0;
//     char **ds = malloc(sizeof(char *) * 1000);
//     int token_length;
//     char *token_start;
//     char *token;

//     while (*str) {
//         skip_delimiters(&str, delimiters);
//         token_start = find_token(&str, delimiters);
//         token_length = str - token_start;
//         token = (char *)malloc(token_length + 1);
//         if (token) {
//             my_strncpy(token, token_start, token_length);
//             token[token_length] = '\0';
//             ds[k] = token;
//             k++;
//         }
//     }
//     ds[k - 1] = NULL;
//     return ds;
// }

int charer(char *str, char c)
{
    int i = 0;

    for (; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

int line_count(char *str, char *seg)
{
    int i = 0;
    int j = 0;

    while (str[i]) {
        for (; charer(seg, str[i]) && str[i]; i++);
        if (!charer(seg, str[i]) && str[i])
            j++;
        for (; !charer(seg, str[i]) && str[i]; i++);
    }
    return j;
}

char **split(char *str, char *seg)
{
    int ln = line_count(str, seg);
    char **tab = malloc(sizeof(char *) * (ln + 1));
    split_t cut = (split_t){0, 0, 0, 0, 0};

    for (; cut.i < ln; cut.i++) {
        for (; charer(seg, str[cut.k]) && str[cut.k]; cut.k++);
        cut.a = 0;
        cut.b = cut.k;
        for (; !charer(seg, str[cut.k]) && str[cut.k]; cut.k++)
            cut.a++;
        tab[cut.i] = malloc(sizeof(char) * (cut.a + 1));
        for (cut.j = 0; cut.j < cut.a; cut.j++) {
            tab[cut.i][cut.j] = str[cut.b];
            cut.b++;
        }
        tab[cut.i][cut.j] = 0;
    }
    tab[cut.i] = 0;
    return tab;
}
