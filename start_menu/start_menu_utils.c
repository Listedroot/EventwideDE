#include "start_menu_utils.h"
#include <gtk/gtk.h>
#include <stdio.h>
void start_menu_utils_notify(const char *msg) {
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", msg);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}
