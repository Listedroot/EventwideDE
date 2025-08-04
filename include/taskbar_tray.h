#ifndef TASKBAR_TRAY_H
#define TASKBAR_TRAY_H
#include <gtk/gtk.h>
void taskbar_tray_init(GtkWidget *parent);
void taskbar_tray_add(GtkWidget *icon);
void taskbar_tray_remove(GtkWidget *icon);
#endif
