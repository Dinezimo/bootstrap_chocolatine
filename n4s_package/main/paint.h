/*
** EPITECH PROJECT, 2024
** all prototypes
** File description:
** project c
*/

#ifndef PAINT_H
    #define PAINT_H
    #include <string.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <math.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>


typedef struct welcome_state {
    sfBool play;
    sfBool resume;
    sfBool setting;
    sfBool Quit;
    sfBool add_vol;
    sfBool no_vol;
    sfBool mute;
    sfBool no_sound;
    sfBool exit;
}state_t;

typedef struct button {
    sfSprite *s;
    sfText *txt;
    sfBool state;
    sfRectangleShape *d;
    struct button *tools;
}button_t;

typedef struct menue {
    sfSprite *dash;
    sfRectangleShape *vol;
    sfRectangleShape *d;
    button_t *tools;
    button_t *button;
}menu_t;

typedef struct settings1 {
    int volume;
    sfRectangleShape *s;
    sfRectangleShape *v;
    sfRectangleShape *e;
    sfRectangleShape *m;
    sfBool sound;
    sfBool exit;
    sfBool mute;
}set_t;

typedef struct dialogue{
    char *file;
    char *p_image;
    sfSprite *p_sprite;
    sfTexture *perso;
    sfColor back;
    sfVector2f dim;
    sfVector2f pos;
    sfRectangleShape *cadre;
    sfText *txt;
    int txt_len;
} dialogue_t;

typedef struct samurai {
    sfSprite* s;
    sfIntRect s_r;
    sfVector2f sam_size;
    sfVector2f sheet_size;
    int i;
    int j;
    int s_dir;
    bool atk;
    bool def;
    bool dle;
    bool hit;
    bool dead;
    sfClock* s_c;
} samourai_t;

typedef struct variables {
    int vol;
    sfUint8 *pix;
    sfSprite *main_back;
    sfRectangleShape **rain;
    sfClock *rc;
    sfMusic *mus;
    sfMusic *cli;
    sfRectangleShape **vol_graph;
    samourai_t **b_charac;
}var_t;

typedef struct cinematic {
    sfSprite *my_sprite;
    sfSprite **background;
    sfSprite **persos;
}cin_t;


    char *get_string(char *str, int len);
    int game_window(cin_t *p, var_t *t);
    void overtool_act(button_t *b, sfRenderWindow *win, sfEvent *evt, var_t *v, state_t *s);
    sfBool tool_over(sfSprite *s, sfRenderWindow* win);
    sfSprite *spriteFromFile(char *file);
    button_t *create_setting1(double win_lengh, double win_wight);
    menu_t *create_menue(double win_lengh, double win_wight);
    void over_set(button_t *t, int len, sfRenderWindow *win);
    sfBool set_over(sfSprite *s, sfRenderWindow* win);
    sfSprite *my_set_size(sfSprite *s, sfVector2f size, sfVector2f sc);
    sfBool tool_over(sfSprite *s, sfRenderWindow* win);
    void volume_design(sfRectangleShape **r, int vol, sfRenderWindow *win, state_t *s);
    sfRectangleShape **creation_vol_sequence();
    void draw_tool(button_t *t, sfRenderWindow *win, sfEvent evt,  var_t *v, state_t *s);
    void actions(menu_t *m, state_t *s, var_t *p, sfRenderWindow *win, sfEvent evt);
    void draw_set(sfRectangleShape *d, button_t *b, sfRenderWindow *win);
    void set_click(sfEvent *evt, menu_t *m, sfRenderWindow* win, state_t *s);
    samourai_t *init_samourai(char *str);
    int direction_evt(samourai_t *s);
    sfRectangleShape **creer_les_gouttes(sfRenderWindow *window);
    void effet_pluie(sfRenderWindow *win, sfRectangleShape **gouttes);
    void sa_moving(samourai_t *s);
    sfSprite *looping_display(cin_t *p);
    samourai_t *charge_red(void);
    samourai_t *charge_green(void);
    samourai_t *charge_princess(void);
    samourai_t *charge_soldier(void);
    samourai_t **avatar_creation(void);
    int my_rand_int(int a, int b);
    int direction_char(samourai_t *s, samourai_t *r);
    void red_size(int i, samourai_t *s);
    void green_size(int i, samourai_t *s);
    void maela_size(int i, samourai_t *s);
    void samy_size(int i, samourai_t *s);
    void anim_charact_j(samourai_t *s, int leng, sfVector2f size);
    void charge_state(samourai_t *s);
    void h_atk_manager(int i, samourai_t *h, samourai_t *ads);
    void interractions(samourai_t *h, samourai_t *ads);
    void ads_behavior(samourai_t *ads);
    int scene1_window(cin_t *p, var_t *t);
    sfSprite *looping_display1(cin_t *p);
#endif
