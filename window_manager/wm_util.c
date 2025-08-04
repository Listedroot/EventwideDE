#include "wm_util.h"
#include <stdio.h>
#include <gtk/gtk.h>

void wm_util_log(const char *msg) {
    printf("[WM] %s\n", msg);
}

void wm_util_error(const char *msg) {
    fprintf(stderr, "[WM ERROR] %s\n", msg);
}

void wm_util_notify(const char *msg) {
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", msg);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}
