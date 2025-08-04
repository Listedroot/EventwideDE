#ifndef TASKBAR_WINDOWLIST_H
#define TASKBAR_WINDOWLIST_H
#include <gtk/gtk.h>
#include <gdk/gdk.h>
void taskbar_windowlist_init(GtkWidget *parent);
void taskbar_windowlist_add(const char *title, GdkWindow *gdk_window);
void taskbar_windowlist_remove(const char *title);
#endif
