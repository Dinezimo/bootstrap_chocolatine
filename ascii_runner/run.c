#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} pos_t;

void draw_ground(int width, int height) {
    for (int i = 0; i < width; ++i) {
        mvaddch(height - 1, i, '-');
    }
}

void draw_athlete(pos_t athlete, int frame) {
    mvaddch(athlete.y, athlete.x, 'O');
    mvaddch(athlete.y + 1, athlete.x, '|');
    if ((frame / 4) % 2 == 0) {
        mvaddch(athlete.y + 1, athlete.x - 1, '/'); 
        mvaddch(athlete.y + 1, athlete.x + 1, '\\');
    } else {
        mvaddch(athlete.y + 1, athlete.x - 1, '\\');
        mvaddch(athlete.y + 1, athlete.x + 1, '/');
    }
    if (frame % 2 == 0) {
        mvaddch(athlete.y + 2, athlete.x, '/');
        mvaddch(athlete.y + 2, athlete.x + 1, '\\');
    } else {
        mvaddch(athlete.y + 2, athlete.x, '\\');
        mvaddch(athlete.y + 2, athlete.x + 1, '/');
    }
}

void draw_hurdle(pos_t hurdle, int frame) {
    mvaddch(hurdle.y, hurdle.x, '|');
    if ((frame / 4) % 2 == 0) {
        mvaddch(hurdle.y - 1, hurdle.x, '^');
        mvaddch(hurdle.y - 2, hurdle.x, '|');
    } else {
        mvaddch(hurdle.y - 1, hurdle.x, '|');
        mvaddch(hurdle.y - 2, hurdle.x, '^');
    }
}

void draw_cloud(pos_t cloud) {
    mvprintw(cloud.y, cloud.x, "     ..Brouhane...");
    mvprintw(cloud.y + 1, cloud.x, " /Let me disover \\ ");
    mvprintw(cloud.y + 2, cloud.x, "/ flamme inside you\\");
}

void draw_tree(pos_t tree) {
    mvprintw(tree.y, tree.x, "  #  ");
    mvprintw(tree.y + 1, tree.x, " ### ");
    mvprintw(tree.y + 2, tree.x, "#####");
    mvprintw(tree.y + 3, tree.x, "  | antoine ");
}
void draw_sun(int x, int y) {
    mvprintw(y, x, "\\  /");
    mvprintw(y + 1, x, " O  kenenth Sun");
    mvprintw(y + 2, x, "/  \\");
}
void draw_stars(int max_x, int max_y) {
    for (int i = 0; i < max_x; i += 10) {
        for (int j = 0; j < max_y / 2; j += 5) {
            mvaddch(j, i, '.');
        }
    }
}

void draw_flame(int x, int y, int size) {
    for (int i = 0; i < size; ++i) {
        if (i % 3 == 0) {
            mvaddch(y - i, x, '|');
        } else if (i % 3 == 1) {
            mvaddch(y - i, x, '/');
        } else {
            mvaddch(y - i, x, '\\');
        }
    }
}

void clear_athlete(pos_t athlete) {
    mvaddch(athlete.y, athlete.x, ' ');
    mvaddch(athlete.y + 1, athlete.x, ' ');
    mvaddch(athlete.y + 1, athlete.x - 1, ' ');
    mvaddch(athlete.y + 1, athlete.x + 1, ' ');
    mvaddch(athlete.y + 2, athlete.x, ' ');
    mvaddch(athlete.y + 2, athlete.x + 1, ' ');
}

void clear_hurdle(pos_t hurdle) {
    mvaddch(hurdle.y, hurdle.x, ' ');
    mvaddch(hurdle.y - 1, hurdle.x, ' ');
    mvaddch(hurdle.y - 2, hurdle.x, ' ');
}

void clear_cloud(pos_t cloud) {
    mvprintw(cloud.y, cloud.x, "            ");
    mvprintw(cloud.y + 1, cloud.x, "              ");
    mvprintw(cloud.y + 2, cloud.x, "              ");
}

void clear_tree(pos_t tree) {
    mvprintw(tree.y, tree.x, "     ");
    mvprintw(tree.y + 1, tree.x, "     ");
    mvprintw(tree.y + 2, tree.x, "     ");
    mvprintw(tree.y + 3, tree.x, "     ");
}

int main() {
    initscr();
    noecho();
    curs_set(FALSE);
    timeout(0);
    srand(time(NULL));

    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);
    pos_t athlete = {max_x / 4, max_y - 4};
    pos_t hurdle = {max_x - 1, max_y - 2};
    pos_t cloud = {max_x - 10, max_y / 4};
    pos_t tree = {max_x - 20, max_y - 5};
    pos_t flame = {12, 1};

    int jumping = 0;
    int jump_height = 0;
    int frame = 0;
    int score = 0;
    int day_time = 1;

    while (1) {
        clear();
        draw_ground(max_x, max_y);

        if (day_time) {
            draw_sun(2, 2);
            draw_cloud(cloud);
        } else {
            draw_stars(max_x, max_y);
        }

        draw_tree(tree);
        draw_athlete(athlete, frame);
        draw_hurdle(hurdle, frame);

        mvprintw(0, 0, "Score: %d", score);
        draw_flame(flame.x, flame.y + score / 10, score / 10);
        refresh();
        int ch = getch();
        if (ch == ' ' && !jumping) {
            jumping = 1;
            jump_height = 6;
        }
        if (jumping) {
            clear_athlete(athlete);
            athlete.y = max_y - 4 - jump_height;
            draw_athlete(athlete, frame);
            refresh();
            jump_height--;
            if (jump_height < 0) {
                jumping = 0;
                clear_athlete(athlete);
                athlete.y = max_y - 4;
            }
        }
        hurdle.x -= 1;
        cloud.x -= 1;
        tree.x -= 1;

        if (hurdle.x < 0) {
            hurdle.x = max_x - 1;
            score++;
        }

        if (cloud.x < -20) {
            cloud.x = max_x - 10;
        }

        if (tree.x < -10) {
            tree.x = max_x - 20;
        }

        if (athlete.x == hurdle.x && (athlete.y + 2 >= hurdle.y)) {
            break;
        }

        if (score % 50 == 0) {
            day_time = !day_time;
        }
        frame++;
        usleep(30000);
    }
    endwin();
    printf("Cool bro! Ta flamme la sumonté: %d obstacles\n", score);
    return 0;
}
