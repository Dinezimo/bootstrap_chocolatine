/*
** EPITECH PROJECT, 2024
** pojet c
** File description:
** to build an menu
*/

#include "paint.h"

sfText *tool_name(char *str)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile("main/assets/name_pol.ttf");

    sfText_setString(txt, str);
    sfText_setFont(txt, font);
    sfText_setCharacterSize(txt, 20);
    sfText_setColor(txt, sfWhite);
    return txt;
}

void set_button(char *name, sfVector2f pos, button_t *b)
{
    b->s = spriteFromFile("main/assets/setting_button.png");
    sfSprite_setScale(b->s, (sfVector2f){0.3, 0.3});
    sfSprite_setPosition(b->s, pos);
    b->txt = tool_name(name);
    sfText_setPosition(b->txt, (sfVector2f){pos.x + 50, pos.y + 70});
    b->state = sfFalse;
    return;
}

button_t *tools_button(void)
{
    char *map[4] = {"main/assets/play.png", "main/assets/resume.png", "main/assets/option.png", "main/assets/quit.png",};
    button_t *b = malloc(sizeof(button_t) * 5);
    sfVector2f pos = (sfVector2f){700, 350};

    for (int i = 0; i < 4; i++) {
        b[i].s = spriteFromFile(map[i]);
        sfSprite_setScale(b[i].s, (sfVector2f){0.12, 0.1});
        sfSprite_setPosition(b[i].s, pos);
        pos.y += 100;
    }
    b[0].d = sfRectangleShape_create();
    sfRectangleShape_setSize(b[0].d, (sfVector2f){380, 440});
    sfRectangleShape_setOutlineThickness(b[0].d, 5);
    sfRectangleShape_setOutlineColor(b[0].d, sfColor_fromRGBA(255, 255, 255, 150));
    sfRectangleShape_setFillColor(b[0].d, sfColor_fromRGBA(0, 0, 0, 200));
    sfRectangleShape_setPosition(b[0].d, (sfVector2f){680, 370});
    return b;
}

menu_t *create_menue(double win_lengh, double win_wight)
{
    sfColor flou = sfColor_fromRGBA(0, 0, 0, 150);
    menu_t *m = malloc(sizeof(menu_t));
    sfVector2f pos = (sfVector2f){win_lengh * 0.5 - 100, win_lengh * 0.5 - 300};

    m->tools = tools_button();
    m->button = malloc(sizeof(button_t) * 6);
    m->d = sfRectangleShape_create();
    sfRectangleShape_setSize(m->d, (sfVector2f){560, 560});
    sfRectangleShape_setOutlineThickness(m->d, 2);
    sfRectangleShape_setOutlineColor(m->d, sfColor_fromRGBA(255, 255, 255, 150));
    sfRectangleShape_setFillColor(m->d, flou);
    sfRectangleShape_setPosition(m->d, pos);
    (set_button("vol +", (sfVector2f){pos.x + 25, pos.y + 25}, &(m->button[0])));
    set_button("vol -", (sfVector2f){pos.x + + 25, pos.y + 125}, &(m->button[1]));
    set_button("Sound", (sfVector2f){pos.x + 25, pos.y + 225}, &(m->button[2]));
    set_button("Musique", (sfVector2f){pos.x + 25, pos.y + 325}, &(m->button[3]));
    set_button("quit", (sfVector2f){pos.x + 25, pos.y + 425}, &(m->button[4]));
    return m;
}
