#include "gui_interface.h"
#include "fetch_download_wrapper.hpp"

GtkWidget* top_window;
GtkWidget* top_stack;

GtkWidget* top_grid_0;
GtkWidget* entry_workshop_id;
GtkWidget* button_fetch;

GtkWidget* top_grid_1;
GtkWidget* image_preview;
GtkWidget* box_fetch_info;
GtkWidget* label_title_and_workshop_id;
GtkWidget* label_filesize;
GtkWidget* label_consumer_app_name_and_id;
GtkWidget* button_folder_path;
GtkWidget* button_download;

GtkBuilder *builder;

void build_gtk_window(){
    int argc = 0;
    char **argv = NULL;
    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file(GLADE_FILE_LOCATION);

    top_window = GTK_WIDGET(gtk_builder_get_object(builder, "top_window"));
    g_signal_connect(top_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //assests on window
    top_stack = GTK_WIDGET(gtk_builder_get_object(builder, "top_stack"));
    
    top_grid_0 = GTK_WIDGET(gtk_builder_get_object(builder, "top_grid_0"));
    entry_workshop_id = GTK_WIDGET(gtk_builder_get_object(builder, "entry_workshop_id"));
    button_fetch = GTK_WIDGET(gtk_builder_get_object(builder, "button_fetch"));

    top_grid_1 = GTK_WIDGET(gtk_builder_get_object(builder, "top_grid_1"));
    image_preview = GTK_WIDGET(gtk_builder_get_object(builder, "image_preview"));
    box_fetch_info = GTK_WIDGET(gtk_builder_get_object(builder, "box_fetch_info"));
    label_title_and_workshop_id = GTK_WIDGET(gtk_builder_get_object(builder, "label_consumer_app_name_and_id"));
    label_filesize = GTK_WIDGET(gtk_builder_get_object(builder, "label_filesize"));
    button_folder_path = GTK_WIDGET(gtk_builder_get_object(builder, "button_folder_path"));
    button_download = GTK_WIDGET(gtk_builder_get_object(builder, "button_download"));

    gtk_builder_connect_signals(builder, NULL);
    gtk_widget_show_all(top_window);
    gtk_main();
}


fetch_download* FETCH_DOWNLOAD;
void on_button_fetch_clicked(GtkButton* button_fetch, gpointer user_data){
    GtkEntry *entry_workshop_id = GTK_ENTRY(user_data);
    const gchar *workshop_id = gtk_entry_get_text(entry_workshop_id);
    fetch_download* object = fetch_download_c((char*)workshop_id);
    FETCH_DOWNLOAD = object;

    fetch_download_c_fetch(FETCH_DOWNLOAD);
    fetch_download_c_delete(FETCH_DOWNLOAD);
}

void on_button_download_clicked(GtkButton* button_download, gpointer user_data){
    
}