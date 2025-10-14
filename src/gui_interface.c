#include "gui_interface.h"
// #include <stdlib.h>
// #include <signal.h>
// #include <ctype.h>
// #include <unistd.h>
// #include <gtk/gtk.h>
// #include <gtk/gtkx.h>

GtkWidget* top_window;
GtkWidget* top_stack;

GtkWidget* top_grid_0;
GtkWidget* entry_workshop_id;
GtkWidget* button_fetch;

GtkWidget* top_grid_1;
GtkWidget* image_preview;
GtkWidget* box_fetch_info;
GtkWidget* label_consumer_app_name_and_id;
GtkWidget* label_title_and_workshop_id;
GtkWidget* button_folder_path;
GtkWidget* button_download;

GtkBuilder *builder;

void build_gtk_window(){
    int* k;
    char*** c;
    gtk_init(k,c);

    builder = gtk_builder_new_from_file(GLADE_FILE_LOCATION);

    top_window = GTK_WIDGET(gtk_builder_get_object(builder, "top_window"));
    g_signal_connect(top_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_builder_connect_signals(builder, NULL);
    gtk_widget_show(top_window);
    gtk_main();
}