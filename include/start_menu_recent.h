#ifndef START_MENU_RECENT_H
#define START_MENU_RECENT_H
#include <gtk/gtk.h>
void start_menu_recent_init(GtkWidget *parent);
void start_menu_recent_add(const char *app);
void start_menu_recent_clear(void);
#endif
