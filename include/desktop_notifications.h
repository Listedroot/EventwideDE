#ifndef DESKTOP_NOTIFICATIONS_H
#define DESKTOP_NOTIFICATIONS_H
#include <gtk/gtk.h>
void desktop_notifications_init(GtkWidget *window);
void desktop_show_notification(GtkWidget *window, const char *message);
void desktop_show_error(GtkWidget *window, const char *message);
#endif
