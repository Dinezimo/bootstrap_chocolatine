/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to open my_window
*/

#include "paint.h"
void init_window2(win_t *w)
{
    w->col = cols();
    w->smile = smile_sprite();
    w->curs = curs_sprite(w);
    w->paper->sprite = paper_definition(w->paper->sprite, w);
    w->man_t = get_man("text.txt");
    w->man_r = man_back();
    w->is_draw = 0;
    w->is_erase = 0;
    w->colo = sfBlack;
    w->color = sfColor_fromRGB(123, 208, 209);
}

win_t *init_window(void)
{
    char *list[] = {"File", "Edit", "Help", NULL};
    win_t *w = malloc(sizeof(win_t));
    rep_t *gr = malloc(sizeof(rep_t));

    w->paper = malloc(sizeof(tool_t));
    gr->pos = (sfVector2f){0, 0};
    gr->nb = (sfVector2f){3, 1};
    gr->size = (sfVector2f){500, 70};
    w->mode = (sfVideoMode){1900, 1000, 32};
    w->win = sfRenderWindow_create(w->mode, "paint", sfResize | sfClose, NULL);
    w->princ = just_princ(tool_parts(list, 3, gr), 3);
    w->file = file();
    w->edit = edit();
    w->help = help();
    w->pencil = pen_tick();
    init_window2(w);
    return w;
}

tool_t *sprites_list(char **list, int len)
{
    int i = 0;
    tool_t *tab = malloc(sizeof(tool_t) * (len + 2));

    for (i = 0; list[i] != NULL; i++) {
        tab[i].name = name(list[i]);
        tab[i].sprite = sfSprite_create();
        tab[i].texture = sfTexture_createFromFile(list[i], NULL);
        sfSprite_setTexture(tab[i].sprite, tab[i].texture, sfTrue);
        tab[i].ind = i;
        tab[i].r = sfRectangleShape_create();
    }
    tab[i].name = my_strdup("finito");
    return tab;
}
