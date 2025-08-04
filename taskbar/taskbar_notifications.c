#include "taskbar_notifications.h"
#include <gtk/gtk.h>
static GtkWidget *notif_btn = NULL;
void taskbar_notifications_init(GtkWidget *parent) {
    notif_btn = gtk_button_new_with_label("!");
    gtk_box_pack_end(GTK_BOX(parent), notif_btn, FALSE, FALSE, 0);
}
