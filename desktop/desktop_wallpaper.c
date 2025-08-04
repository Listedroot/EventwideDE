#include <gtk/gtk.h>
#include "desktop_wallpaper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char wallpaper_path[512] = "/usr/share/backgrounds/classy_wallpaper.jpg";
static int wallpaper_mode = 0; // 0: fill, 1: fit, 2: center

void desktop_wallpaper_set(GtkWidget *window) {
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(wallpaper_path, NULL);
    if (pixbuf) {
        GtkWidget *image;
        if (wallpaper_mode == 0) {
            // Fill
            GdkPixbuf *scaled = gdk_pixbuf_scale_simple(pixbuf, 1920, 1080, GDK_INTERP_BILINEAR);
            image = gtk_image_new_from_pixbuf(scaled);
            g_object_unref(scaled);
        } else if (wallpaper_mode == 1) {
            // Fit
            int w = gdk_pixbuf_get_width(pixbuf);
            int h = gdk_pixbuf_get_height(pixbuf);
            double scale = fmin(1920.0/w, 1080.0/h);
            GdkPixbuf *scaled = gdk_pixbuf_scale_simple(pixbuf, w*scale, h*scale, GDK_INTERP_BILINEAR);
            image = gtk_image_new_from_pixbuf(scaled);
            g_object_unref(scaled);
        } else {
            // Center
            image = gtk_image_new_from_pixbuf(pixbuf);
        }
        gtk_fixed_put(GTK_FIXED(window), image, 0, 0);
        gtk_widget_lower(image);
    }
}

void desktop_wallpaper_change(GtkWidget *window, const char *new_path, int mode) {
    strncpy(wallpaper_path, new_path, sizeof(wallpaper_path)-1);
    wallpaper_mode = mode;
    desktop_wallpaper_set(window);
    FILE *f = fopen("~/.eventwidede_wallpaper", "w");
    if (f) { fprintf(f, "%s\n%d\n", wallpaper_path, wallpaper_mode); fclose(f); }
}

void desktop_wallpaper_next(GtkWidget *window) {
    // Cycle wallpapers in /usr/share/backgrounds
    DIR *dir = opendir("/usr/share/backgrounds");
    if (!dir) return;
    struct dirent *entry;
    int found = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".jpg") || strstr(entry->d_name, ".png")) {
            if (found) {
                snprintf(wallpaper_path, sizeof(wallpaper_path), "/usr/share/backgrounds/%s", entry->d_name);
                break;
            }
            if (strcmp(wallpaper_path, entry->d_name) == 0) found = 1;
        }
    }
    closedir(dir);
    desktop_wallpaper_set(window);
}
