#include <gtk/gtk.h>

typedef struct
{
    GtkWidget *def;
} Widget;

Widget *create_cal(void)
{
    Widget *new_cal = g_new(Widget, 1);
    new_cal->def = gtk_calendar_new();

    return new_cal;
}
Widget *create_button(void)
{
    Widget *new_button = g_new(Widget, 1);
    new_button->def = gtk_button_new_with_label("hayden");

    return new_button;
}

static void on_activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Default Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 100);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6); // vertical box with spacing 6px

    gtk_box_append(GTK_BOX(box), create_cal()->def);
    gtk_box_append(GTK_BOX(box), create_button()->def);

    gtk_window_set_child(GTK_WINDOW(window), box);
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[])
{
    GtkApplication *app = gtk_application_new("com.example.CommandRunner", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
