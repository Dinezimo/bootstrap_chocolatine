#include <gtk/gtk.h>
#include "my.h"

int execute_command(const char *command)
{
    FILE *fp = popen(command, "r");

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
}

void execute_command_in_new_terminal(const char *command)
{
    char terminal_command[256];
    sprintf(terminal_command, "gnome-terminal -- \"%s\"", command);
    system(terminal_command);
}

void afficher_contenu(GtkLabel *label, const char *contenu)
{
    gtk_label_set_text(label, contenu);
}

void on_learn_clicked(GtkWidget *widget, GtkLabel *background_label)
{
    afficher_contenu(background_label, "Mode Learn activé");
    learn_win(4, NULL);
}

void on_help_clicked(GtkWidget *widget, GtkLabel *background_label)
{
     quizz(0, NULL);
    afficher_contenu(background_label, "Contenu pour Help");
}

void on_challenges_clicked(GtkWidget *widget, GtkWidget **challenge_buttons, int num_buttons)
{
    gboolean active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
    
    for (int i = 0; i < num_buttons; ++i) {
        if (active) {
            gtk_widget_show(challenge_buttons[i]);
        } else {
            gtk_widget_hide(challenge_buttons[i]);
        }
    }
}

void on_challenge_selected(GtkWidget *widget, gpointer data)
{
    const char *selected_challenge = (const char *)data;
}
void on_challenge_button_clicked(GtkWidget *widget, GtkWidget **buttons, int num_buttons)
{
    for (int i = 0; i < num_buttons; ++i) {
        if (buttons[i] == widget) {
            gtk_widget_set_state_flags(widget, GTK_STATE_FLAG_ACTIVE, TRUE);
        } else {
            gtk_widget_unset_state_flags(buttons[i], GTK_STATE_FLAG_ACTIVE);
        }
    }
}

void on_sokoban_clicked(GtkWidget *widget, gpointer data)
{
    sokoban_ai(4, NULL);
}

void on_need4speed_clicked(GtkWidget *widget, gpointer data)
{
    n4s_win(0, NULL);
}

void on_Challenge3_clicked(GtkWidget *widget, gpointer data)
{
    rpg_ai(0, NULL);
}

void on_manual_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *manual_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(manual_window), "Manuel d'utilisation");
    gtk_window_set_default_size(GTK_WINDOW(manual_window), 500, 300);
    gtk_container_set_border_width(GTK_CONTAINER(manual_window), 10);
    g_signal_connect(manual_window, "destroy", G_CALLBACK(gtk_widget_destroy), NULL);

    GtkWidget *manual_vbox = gtk_vbox_new(FALSE, 10);
    GtkWidget *manual_label = gtk_label_new("Voici le manuel d'utilisation de l'application :\n\n"
                                            "1. Cliquez sur le bouton 'Learn' pour accéder aux ressources d'apprentissage.\n"
                                            "2. Cliquez sur le bouton 'Challenges' pour accéder aux différents défis.\n"
                                            "3. Cliquez sur le bouton 'Quizz' pour accéder aux quizz en ligne.\n"
                                            "4. Cliquez sur le bouton 'Manuel' pour afficher ces instructions.");

    gtk_container_add(GTK_CONTAINER(manual_window), manual_vbox);
    gtk_box_pack_start(GTK_BOX(manual_vbox), manual_label, TRUE, TRUE, 0);

    gtk_widget_show_all(manual_window);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Elora Ai-learning");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    GtkWidget *vbox_main = gtk_vbox_new(FALSE, 5);
    GtkWidget *label_welcome = gtk_label_new("Welcome to Elora Ai-learning");
    GtkWidget *label_slogan = gtk_label_new("\"L'IA, au service du développement\"");
    GtkWidget *hbox_buttons = gtk_hbox_new(TRUE, 5);
    GtkWidget *button_learn = gtk_button_new_with_label("Learn");
    GtkWidget *button_challenges = gtk_toggle_button_new_with_label("Challenges");
    GtkWidget *button_quizz = gtk_button_new_with_label("Quizz");
    GtkWidget *button_manual = gtk_button_new_with_label("Manuel");
    GtkWidget *background_label = gtk_label_new(NULL);
    GtkWidget *button_sokoban = gtk_button_new_with_label("PLAYING SOKOBAN");
    GtkWidget *button_need4speed = gtk_button_new_with_label("NEED4SPEED");
    GtkWidget *button_fight_the_boss = gtk_button_new_with_label("Fight the boss");
    GtkWidget *challenge_buttons[] = {button_sokoban, button_need4speed, button_fight_the_boss};
    int num_challenge_buttons = sizeof(challenge_buttons) / sizeof(GtkWidget *);
    for (int i = 0; i < num_challenge_buttons; ++i) {
        gtk_widget_hide(challenge_buttons[i]);
    }
    gtk_container_add(GTK_CONTAINER(window), vbox_main);
    gtk_box_pack_start(GTK_BOX(vbox_main), label_welcome, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox_main), label_slogan, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox_main), hbox_buttons, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox_main), background_label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox_buttons), button_learn, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox_buttons), button_challenges, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox_buttons), button_quizz, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox_buttons), button_manual, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox_main), button_sokoban, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox_main), button_need4speed, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox_main), button_fight_the_boss, TRUE, TRUE, 0);
    g_signal_connect(button_learn, "clicked", G_CALLBACK(on_learn_clicked), background_label);
    g_signal_connect(button_quizz, "clicked", G_CALLBACK(on_help_clicked), NULL);
    g_signal_connect(button_challenges, "clicked", G_CALLBACK(on_challenges_clicked), challenge_buttons);
    g_signal_connect(button_sokoban, "clicked", G_CALLBACK(on_sokoban_clicked), "PLAYING SOKOBAN");
    g_signal_connect(button_need4speed, "clicked", G_CALLBACK(on_challenge_selected), "NEED4SPEED");
    g_signal_connect(button_need4speed, "clicked", G_CALLBACK(on_need4speed_clicked), NULL);
    g_signal_connect(button_fight_the_boss, "clicked", G_CALLBACK(on_Challenge3_clicked), NULL);
    g_signal_connect(button_manual, "clicked", G_CALLBACK(on_manual_clicked), NULL);

    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "styles.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                              GTK_STYLE_PROVIDER(provider),
                                              GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    g_object_unref(provider);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}


char *file_fromfile(char* filename)
{
    FILE *file = fopen(filename, "r");
    char *content = (char*)malloc(5000);

    fread(content, 1, 5000, file);
    fclose(file);

    return content;
}
void on_start_simulation_clicked(GtkWidget *widget, gpointer data)
{
    execute_command("./pipes.sh");
}


int n4s_win(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *box_v;
    GtkWidget *box_h;
    GtkWidget *text_view;
    GtkWidget *button;

    gtk_init(&argc, &argv);

    char *instuct_n4s = file_fromfile("n4s_instruction.txt");
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Challenge de l'IA");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    box_v = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box_v);
    box_h = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(box_v), box_h, FALSE, FALSE, 0);
    text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(text_view), FALSE);
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    gtk_text_buffer_set_text(buffer, instuct_n4s, -1);
    gtk_box_pack_start(GTK_BOX(box_h), text_view, TRUE, TRUE, 0);
    box_h = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_end(GTK_BOX(box_v), box_h, FALSE, FALSE, 0);
    button = gtk_button_new_with_label("START_SIMULATION");
    g_signal_connect(button, "clicked", G_CALLBACK(on_start_simulation_clicked), NULL);
    gtk_box_pack_end(GTK_BOX(box_h), button, FALSE, FALSE, 0);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

void open_link(GtkWidget *widget, gpointer data)
{
    const char *link = (const char *)data;

    GError *error = NULL;
    gtk_show_uri_on_window(NULL, link, GDK_CURRENT_TIME, &error);
    if (error) {
        g_warning("Erreur lors de l'ouverture du lien : %s", error->message);
        g_error_free(error);
    }
}

int learn_win(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "IA LEARNING");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    GtkWidget *title = gtk_label_new("Quelle notion souhaitez-vous aborder?");
    gtk_box_pack_start(GTK_BOX(vbox), title, FALSE, FALSE, 10);
    GtkWidget *button_base_ia = gtk_button_new_with_label("Bases de l'IA");
    gtk_box_pack_start(GTK_BOX(vbox), button_base_ia, FALSE, FALSE, 0);
    g_signal_connect(button_base_ia, "clicked", G_CALLBACK(open_link), "https://youtu.be/zrAEdlkLoV8?si=SQPzI8zW-krVUwQa");
    GtkWidget *button_computer_vision = gtk_button_new_with_label("Vision par ordinateur");
    gtk_box_pack_start(GTK_BOX(vbox), button_computer_vision, FALSE, FALSE, 0);
    g_signal_connect(button_computer_vision, "clicked", G_CALLBACK(open_link), "https://azure.microsoft.com/fr-fr/resources/cloud-computing-dictionary/what-is-computer-vision#classification-des-objets");
    GtkWidget *button_optimization = gtk_button_new_with_label("Techniques d'optimisation");
    gtk_box_pack_start(GTK_BOX(vbox), button_optimization, FALSE, FALSE, 0);
    g_signal_connect(button_optimization, "clicked", G_CALLBACK(open_link), "https://getgenie.ai/content-optimization-with-ai/");
    GtkWidget *button_ml_dl = gtk_button_new_with_label("Machine et deep learning");
    gtk_box_pack_start(GTK_BOX(vbox), button_ml_dl, FALSE, FALSE, 0);
    g_signal_connect(button_ml_dl, "clicked", G_CALLBACK(open_link), "https://youtu.be/XUFLq6dKQok?si=59jDIzYdYWhmHnka");
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

void on_start_fight_clicked(GtkWidget *widget, gpointer data)
{
    execute_command("./my_rpg");
}

int rpg_ai(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    char *instruct_rpg = file_fromfile("rpg.txt"); 
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Bienvenue au challenge \"Fight the boss\"");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    GtkWidget *title = gtk_label_new(instruct_rpg);
    gtk_box_pack_start(GTK_BOX(vbox), title, FALSE, FALSE, 10);
    GtkWidget *start_button = gtk_button_new_with_label("Start fight");
    g_signal_connect(start_button, "clicked", G_CALLBACK(on_start_fight_clicked), NULL);
    gtk_box_pack_end(GTK_BOX(vbox), start_button, FALSE, FALSE, 10);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

void on_quizz1_clicked(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Opening link: https://waytolearnx.com/2022/06/qcm-intelligence-artificielle-corrige.html#google_vignette");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    g_app_info_launch_default_for_uri("https://waytolearnx.com/2022/06/qcm-intelligence-artificielle-corrige.html#google_vignette", NULL, NULL);
}

void on_quizz2_clicked(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Opening link: https://ici.exploratv.ca/quiz/1-IA-questions-robots-technologie-inventions-informatique/");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    g_app_info_launch_default_for_uri("https://ici.exploratv.ca/quiz/1-IA-questions-robots-technologie-inventions-informatique/", NULL, NULL);
}

void on_quizz3_clicked(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Opening link: https://waytolearnx.com/2022/06/qcm-intelligence-artificielle-corrige.html#google_vignette");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    g_app_info_launch_default_for_uri("https://waytolearnx.com/2022/06/qcm-intelligence-artificielle-corrige.html#google_vignette", NULL, NULL);
}

int quizz(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Quizz");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 400);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    GtkWidget *vbox = gtk_vbox_new(FALSE, 10);
    GtkWidget *label = gtk_label_new("Voici une panoplie de quizz pour renforcer vos compétences");
    GtkWidget *quizz1_button = gtk_button_new_with_label("Quizz 1");
    GtkWidget *quizz2_button = gtk_button_new_with_label("Quizz 2");
    GtkWidget *quizz3_button = gtk_button_new_with_label("Quizz 3");
    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), quizz1_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), quizz2_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), quizz3_button, FALSE, FALSE, 0);
    g_signal_connect(quizz1_button, "clicked", G_CALLBACK(on_quizz1_clicked), NULL);
    g_signal_connect(quizz2_button, "clicked", G_CALLBACK(on_quizz2_clicked), NULL);
    g_signal_connect(quizz3_button, "clicked", G_CALLBACK(on_quizz3_clicked), NULL);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

void on_start_game_clicked(GtkWidget *widget, gpointer data)
{
    execute_command("./my_sokoban e");
}

void sokoban_ai(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    char *instruct_rpg = file_fromfile("SOKO.txt"); 
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Bienvenue au challenge \"MY SOKOBAN\"");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    GtkWidget *title = gtk_label_new(instruct_rpg);
    gtk_box_pack_start(GTK_BOX(vbox), title, FALSE, FALSE, 10);
    GtkWidget *start_button = gtk_button_new_with_label("Let' s Go to game");
    g_signal_connect(start_button, "clicked", G_CALLBACK(on_start_game_clicked), NULL);
    gtk_box_pack_end(GTK_BOX(vbox), start_button, FALSE, FALSE, 10);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}