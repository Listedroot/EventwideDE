#include "start_menu_power.h"
#include <gtk/gtk.h>
void start_menu_power_init(GtkWidget *parent) {
    GtkWidget *shutdown_btn = gtk_button_new_with_label("Shutdown");
    GtkWidget *reboot_btn = gtk_button_new_with_label("Reboot");
    GtkWidget *logout_btn = gtk_button_new_with_label("Logout");
    g_signal_connect(shutdown_btn, "clicked", G_CALLBACK(g_spawn_command_line_async), "poweroff");
    g_signal_connect(reboot_btn, "clicked", G_CALLBACK(g_spawn_command_line_async), "reboot");
    g_signal_connect(logout_btn, "clicked", G_CALLBACK(g_spawn_command_line_async), "pkill -KILL -u $USER");
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    gtk_box_pack_start(GTK_BOX(box), shutdown_btn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), reboot_btn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), logout_btn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(parent), box, FALSE, FALSE, 0);
}
