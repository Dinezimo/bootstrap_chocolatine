/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to code
*/

#include "../main/paint.h"

int scene1_window(cin_t *p, var_t *t)
{
    int i = 0;
    int j = 0;
    int k = 0;
    sfEvent evt;
    sfVideoMode mode = (sfVideoMode){1920, 1080, 64};
    sfRenderWindow *game = sfRenderWindow_create(mode, "game",
    sfResize | sfClose, NULL);

    looping_display1(p);
    while (sfRenderWindow_isOpen(game)) {
        sfRenderWindow_clear(game, sfBlack);
        while (sfRenderWindow_pollEvent(game, &evt)) {
            if (evt.type == sfEvtClosed)
                exit(0);
        }
        j = t->b_charac[0]->i;
        k = t->b_charac[3]->i;
        direction_char(t->b_charac[0], t->b_charac[3]);
        ads_behavior(t->b_charac[3]);
        red_size(j, &t->b_charac[0][j]);
        samy_size(k, &t->b_charac[3][k]);
        charge_state(t->b_charac[0]);
        anim_charact_j(&t->b_charac[0][j], t->b_charac[0][j].sheet_size.x, t->b_charac[0][j].sam_size);
        anim_charact_j(&t->b_charac[3][k], t->b_charac[3][k].sheet_size.x, t->b_charac[3][k].sam_size);
        interractions(t->b_charac[0], t->b_charac[3]);
        sfRenderWindow_drawSprite(game, p->background[i], NULL);
        sfRenderWindow_drawSprite(game, t->b_charac[0][j].s, NULL);
        sfRenderWindow_drawSprite(game, t->b_charac[3][k].s, NULL);
        sfRenderWindow_display(game);
        i++;
        if (i >= 7)
            i = 0;
    }
    free(p);
    sfRenderWindow_destroy(game);
}
