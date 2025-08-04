#include "taskbar_menu.h"
#include <gtk/gtk.h>
static GtkWidget *menu_btn = NULL;
void taskbar_menu_init(GtkWidget *parent) {
    menu_btn = gtk_button_new_with_label("Menu");
    gtk_box_pack_start(GTK_BOX(parent), menu_btn, FALSE, FALSE, 0);
    g_signal_connect(menu_btn, "clicked", G_CALLBACK(gtk_main_quit), NULL);
}
