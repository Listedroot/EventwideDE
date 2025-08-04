#include "start_menu_settings.h"
#include <gtk/gtk.h>
void start_menu_settings_init(GtkWidget *parent) {
    GtkWidget *btn = gtk_button_new_with_label("Settings");
    g_signal_connect(btn, "clicked", G_CALLBACK(g_spawn_command_line_async), "eventwidede-settings");
    gtk_box_pack_start(GTK_BOX(parent), btn, FALSE, FALSE, 0);
}
