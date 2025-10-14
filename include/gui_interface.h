#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H

#include <gtk/gtk.h>
#include <gtk/gtkx.h>

#ifdef __cplusplus
extern "C" {
#endif
#include <stdlib.h>
#include <signal.h>
#include <ctype.h>
#include <unistd.h>
    
#define GLADE_FILE_LOCATION "./glade_gui/steam_Workdown_gui.glade"

void build_gtk_window();

void on_button_fetch_clicked(GtkButton* button_fetch, gpointer user_data);

void on_button_download_clicked(GtkButton* button_download, gpointer user_data);


#ifdef __cplusplus
}
#endif

#endif // GUI_INTERFACE_H