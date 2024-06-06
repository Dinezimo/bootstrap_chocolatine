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
    #include <stdio.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <math.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <stddef.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>

enum e_gui_state {
    NONE,
    HOVER,
    PRESSED,
    RELEASED
};

typedef struct color {
    sfBool red;
    sfBool green;
    sfBool blue;
    sfBool black;
    sfBool yellow;
    sfBool white;
    sfBool magenta;
    sfBool cyan;
}co_t;

typedef struct rep {
    sfVector2f pos;
    sfVector2f nb;
    sfVector2f size;
}rep_t;

typedef struct s_tool {
    char *name;
    sfSprite *sprite;
    sfTexture* texture;
    sfVector2f position;
    int ind;
    sfRectangleShape *r;
    struct s_tool *options;
    int state;
    sfText *txt;
    rep_t *gr;
}tool_t;

typedef struct state {
    sfBool draw_ok;
    sfBool color;
    sfBool file;
    sfBool edit;
    sfBool help;
    sfBool save;
    sfBool erase;
    sfBool new;
    sfBool import;
    sfBool login;
    sfBool tick;
    sfBool log;
    sfBool man;
    sfBool is_draw;
    sfBool is_erase;
}st_t;

typedef struct win {
    sfVideoMode mode;
    sfRenderWindow* win;
    sfEvent event;
    sfSprite *back;
    sfTexture *back_t;
    tool_t *princ;
    sfSprite *draw_sprite;
    tool_t *file;
    tool_t *edit;
    tool_t *help;
    tool_t *paper;
    tool_t *pencil;
    tool_t *col;
    tool_t *smile;
    tool_t *curs;
    sfText *man_t;
    sfRectangleShape *man_r;
    sfBool is_draw;
    sfBool is_erase;
    co_t *c;
    sfImage *img;
    sfColor colo;
    sfColor color;
}win_t;

typedef struct rools {
    sfRectangleShape *r;
    char *name;
    sfVector2f position;
    int ind;
}rect_list;

typedef struct res {
    int tool;
    int col;
}res_t;
tool_t *smile_sprite(void);
tool_t *curs_sprite(win_t *w);
sfRectangleShape *man_back(void);
tool_t *cols(void);
int h_tic(st_t *p, win_t *w);
st_t *h_bool(tool_t *t, st_t *p, win_t *w);
tool_t *pen_tick(void);
rep_t *copy_rep(rep_t *gr);
sfBool is_list_over(tool_t *t, sfRenderWindow* win, int len);
sfSprite *paper_definition(sfSprite *paper, win_t *w);
tool_t *just_princ(tool_t *el, int len);
sfText *tool_name(char *str, sfFont* font);
void display_tools(tool_t *l, int len, sfRenderWindow* win);
win_t *init_window(void);
tool_t *tool_parts(char **list, int len, rep_t *gr);
int my_strlen(char *str);
sfRectangleShape *cadre_func(void);
sfSprite* sprite_settings(char *test, sfVector2f scale, sfVector2f position);
char *my_strdup(char *src);
int ris_over(sfRectangleShape *r, sfRenderWindow* win);
int sis_over(sfSprite *s, sfRenderWindow* win);
tool_t *sprites_list(char **list, int len);
char *name(char *str);
tool_t *file(void);
tool_t *edit(void);
tool_t *help(void);
sfText *get_man(char *str);
void draw_in_paper(sfSprite *p, sfColor col, win_t *w, int e);
co_t *col_init(void);
sfColor pixel_color(co_t *c);
co_t *col_val(co_t *c, win_t *w);
st_t *state(st_t *p);
void display_tools2(tool_t *l, int len, sfRenderWindow* win);
sfBool is_over(sfRectangleShape *r, sfRenderWindow* win);
void over_tool(tool_t *t, int len, sfRenderWindow *win);
st_t *pen_bool(tool_t *t, st_t *p, win_t *w);
int pen_tic(st_t *w);
void paper_file_draw(win_t *w, st_t *p, co_t *c);
void file_evt(win_t *w, st_t *p, co_t *c);
void edit_evt(win_t *w, st_t *p, co_t *c);
void help_evt(win_t *w, st_t *p, co_t *c);
void draw_or_erase(win_t *w, st_t *p, co_t *c);
void edit_help_exec(win_t *w, st_t *p, co_t *c);
void draw_exec(win_t *w, st_t *p, co_t *c);
void is_open(win_t *w, st_t *p, co_t *c);
char **str_list(void);
sfColor *col_list(void);
st_t *pen_bool(tool_t *t, st_t *p, win_t *w);
int pen_tic(st_t *w);
void destroy_res(win_t *w);
void draw_spr(tool_t *s, int len, win_t *w);
void cool_cursor(sfBool d, sfBool e, win_t *w);
#endif
