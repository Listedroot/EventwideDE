#ifndef START_MENU_SHORTCUTS_H
#define START_MENU_SHORTCUTS_H
#include <gtk/gtk.h>
void start_menu_shortcuts_init(GtkWidget *parent);
void start_menu_shortcuts_add(const char *name, const char *cmd);
void start_menu_shortcuts_remove(const char *name);
#endif
