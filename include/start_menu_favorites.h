#ifndef START_MENU_FAVORITES_H
#define START_MENU_FAVORITES_H
#include <gtk/gtk.h>
void start_menu_favorites_init(GtkWidget *parent);
void start_menu_favorites_add(const char *app);
void start_menu_favorites_remove(const char *app);
#endif
