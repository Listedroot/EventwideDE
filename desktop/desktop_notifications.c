#include <gtk/gtk.h>
#include "desktop_notifications.h"
#include <stdio.h>

typedef struct {
    char messages[10][256];
    int count;
} NotificationHistory;

static NotificationHistory notif_history = { .count = 0 };

void desktop_show_notification(GtkWidget *window, const char *message) {
    if (notif_history.count < 10) {
        strncpy(notif_history.messages[notif_history.count++], message, 255);
    }
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT,
        GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", message);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void desktop_show_error(GtkWidget *window, const char *message) {
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT,
        GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "%s", message);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void desktop_notifications_init(GtkWidget *window) {
    desktop_show_notification(window, "Welcome to EventwideDE!");
}
