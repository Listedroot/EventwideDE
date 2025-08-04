#include "taskbar_tray.h"
#include <gtk/gtk.h>
static GtkWidget *tray_box = NULL;
void taskbar_tray_init(GtkWidget *parent) {
    tray_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    gtk_box_pack_end(GTK_BOX(parent), tray_box, FALSE, FALSE, 0);
}
void taskbar_tray_add(GtkWidget *icon) {
    gtk_box_pack_start(GTK_BOX(tray_box), icon, FALSE, FALSE, 0);
    gtk_widget_show_all(tray_box);
}
void taskbar_tray_remove(GtkWidget *icon) {
    gtk_container_remove(GTK_CONTAINER(tray_box), icon);
}
