// file: get_example.c

#include <stdio.h>
#include <curl/curl.h>
#include <gtk/gtk.h>
#include <glib.h>

void get_req()
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init(); // Initialize curl
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/posts");

        // Optional: follow HTTP redirects
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        // Cleanup
        curl_easy_cleanup(curl);
    }
}

#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    g_print("hell owrld");
    gtk_init(&argc, &argv);

    // WINDOW
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GTK 3 Text Widgets");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // VERTICAL BOX
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // HORIZONTAL BOX FOR BUTTONS
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 20);
    gtk_widget_set_halign(hbox, GTK_ALIGN_CENTER);

    // LABELS
    GtkWidget *label = gtk_label_new("This is a GtkLabel");
    GtkWidget *label2 = gtk_label_new("P(A | B)");
    GtkWidget *label3 = gtk_label_new("P(B | A)");
    GtkWidget *btn1 = gtk_button_new_with_label("Reset");
    GtkWidget *btn2 = gtk_button_new_with_label("Calc");

    // label
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER);
    gtk_widget_set_margin_top(label, 20);

    // label2
    gtk_widget_set_halign(label2, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label2, 30);

    // label3
    gtk_widget_set_halign(label3, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label3, 30);

    // buttons
    gtk_widget_set_size_request(btn1, 40, 30);
    gtk_widget_set_size_request(btn2, 40, 30);

    // PACK LABELS INTO VBOX
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), label2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), label3, FALSE, FALSE, 0);
    // ADD HBOX TO VBOX
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

    // PACK BUTTONS INTO HBOX
    gtk_box_pack_start(GTK_BOX(hbox), btn1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), btn2, FALSE, FALSE, 0);

    // SHOW EVERYTHING
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
