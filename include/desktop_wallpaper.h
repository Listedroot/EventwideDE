#ifndef DESKTOP_WALLPAPER_H
#define DESKTOP_WALLPAPER_H
#include <gtk/gtk.h>
void desktop_wallpaper_set(GtkWidget *window);
void desktop_wallpaper_change(GtkWidget *window, const char *new_path, int mode);
void desktop_wallpaper_next(GtkWidget *window);
#endif
