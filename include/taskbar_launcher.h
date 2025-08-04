#ifndef TASKBAR_LAUNCHER_H
#define TASKBAR_LAUNCHER_H
#include <gtk/gtk.h>
void taskbar_launcher_init(GtkWidget *parent);
void taskbar_launcher_add(const char *icon_path, const char *exec_cmd);
void taskbar_launcher_remove(const char *exec_cmd);
#endif
