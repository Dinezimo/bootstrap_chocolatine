/*
** EPITECH PROJECT, 2024
** projet c
** File description:
** to display dialogue
*/

#include <SFML/Graphics.h>
#include "paint.h"
#include <time.h>

sfSprite *my_set_size(sfSprite *s, sfVector2f size, sfVector2f sc)
{
    sfFloatRect actual = sfSprite_getGlobalBounds(s);
    sfVector2f pos = (sfVector2f){size.x / actual.width,
    size.y / actual.height};

    pos.x *=  sc.x;
    pos.y *= sc.y;
    sfSprite_setScale(s, pos);
    return s;
}

sfSprite *spriteFromFile(char *file)
{
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}


dialogue_t *dialogue_test(void)
{
    dialogue_t *d = malloc(sizeof(dialogue_t));

    d->file = "file";
    d->p_image = "niska.jpg";
    d->back = sfMagenta;
    d->dim = (sfVector2f){1000, 100};
    d->pos = (sfVector2f){200, 200};
    d->txt_len = 300;
    return d;
}

dialogue_t *dialogue_from_file(dialogue_t *p)
{
    sfFont *f = sfFont_createFromFile("main/assets/name_pol.ttf");

    char *str = get_string(p->file, p->txt_len);
    p->cadre = sfRectangleShape_create();
    sfRectangleShape_setPosition(p->cadre, p->pos);
    p->txt = sfText_create();
    sfText_setCharacterSize(p->txt, 30);
    sfText_setColor(p->txt, sfBlack);
    sfText_setFont(p->txt, f);
    sfText_setPosition(p->txt, p->pos);
    sfText_setString(p->txt, str);
    sfRectangleShape_setFillColor(p->cadre, p->back);
    sfRectangleShape_setPosition(p->cadre, p->pos);
    sfRectangleShape_setSize(p->cadre, p->dim);
    p->p_sprite = sfSprite_create();
    p->perso = sfTexture_createSrgbFromFile(p->p_image, NULL);
    sfSprite_setPosition(p->p_sprite, (sfVector2f){p->pos.x, p->pos.y - 500});
    p->p_sprite = spriteFromFile(p->p_image);
    return p;
}

state_t *state_init()
{
    state_t *s = malloc(sizeof(state_t));

    s->play = 0;
    s->resume = 0;
    s->setting = 0;
    s->Quit = 0;
    s->add_vol = 0;
    s->no_vol = 0;
    s->mute = 0;
    s->no_sound = 0;
    s->exit = 0;
    return s;
}

int my_rand_int(int a, int b)
{
    srand(time(NULL));
    return a + (rand() % (b - a + 1));
}

sfRectangleShape **creer_les_gouttes(sfRenderWindow *window)
{
    sfRectangleShape **gouttes = malloc(sizeof(sfRectangleShape *) * 300);
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 300; i++)
    {
        gouttes[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(gouttes[i], (sfVector2f){2, 10});
        sfRectangleShape_setFillColor(gouttes[i], sfColor_fromRGBA(135, 206, 250, 200));
        sfRectangleShape_setPosition(gouttes[i], (sfVector2f){(float)(rand() % 1900), (float)(rand() % 1000)});
    }

    return gouttes;
}

void effet_pluie(sfRenderWindow *win, sfRectangleShape **gouttes)
{
    for (int i = 0; i < 300; i++)
    {
        sfVector2f position = sfRectangleShape_getPosition(gouttes[i]);
        if (position.y > 1000) {
            position.y = 0;
            position.x = (float)(rand() % 1900);
        }
        else
            position.y += 3;
        sfRectangleShape_setPosition(gouttes[i], position);
        sfRenderWindow_drawRectangleShape(win, gouttes[i], NULL);
    }
}

int main()
{
    sfVideoMode mode = (sfVideoMode){1900, 1000, 64};
    sfRenderWindow *win = sfRenderWindow_create(mode, "tools",  sfResize | sfClose, NULL);
    sfEvent evt;
    //dialogue_t *d = dialogue_test();
    menu_t *m = create_menue(1000, 1900);
    state_t *s = state_init();
    var_t *p = malloc(sizeof(var_t));
    cin_t *t = malloc(sizeof(cin_t));

    //d = dialogue_from_file(d);
    p->main_back = spriteFromFile("main/assets/samurai-battle-field-desktop-wallpaper-preview.jpg");
    p->rain = creer_les_gouttes(win);
    p->mus = sfMusic_createFromFile("main/assets/naruto.ogg");
    p->vol = 9;
    p->vol_graph = creation_vol_sequence();
    p->cli = sfMusic_createFromFile("main/assets/clik1.ogg");
    p->b_charac = avatar_creation();
    sfSprite_setScale(p->main_back, (sfVector2f){1.25, 1.15});
    //sfSprite_setPosition(d->p_sprite, (sfVector2f){d->pos.x, d->pos.y - 190});
    sfMusic_play(p->mus);
    /*while (sfRenderWindow_isOpen(win)) {
        sfVector2i mpos = sfMouse_getPositionRenderWindow(win);
        sfRenderWindow_clear(win, sfCyan);
        while (sfRenderWindow_pollEvent(win, &evt)) {
             if (evt.type == sfEvtClosed)
                 exit(0);
            set_click(&evt, m, win, s);
        }
        sfRenderWindow_drawSprite(win, p->main_back, NULL);
        over_set(m->button, 5, win);
        actions(m, s, p, win, evt);
        volume_design(p->vol_graph, p->vol, win, s);
        sfRenderWindow_display(win);
    }*/
    sfMusic_stop(p->mus);
    scene1_window(t, p);
    //game_window(t, p);
    free(p);
    free(m);
    free(s);
    sfRenderWindow_destroy(win);
}
