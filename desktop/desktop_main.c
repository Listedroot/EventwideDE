#include <gtk/gtk.h>
#include "desktop_wallpaper.h"
#include "desktop_icons.h"
#include "desktop_context_menu.h"
#include "desktop_dragdrop.h"
#include "desktop_shortcuts.h"
#include "desktop_files.h"
#include "desktop_settings.h"
#include "desktop_notifications.h"
#include "desktop_clipboard.h"
#include "desktop_utils.h"

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "EventwideDE Desktop");
    gtk_window_set_default_size(GTK_WINDOW(window), 1920, 1080);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    GtkWidget *fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);
    desktop_wallpaper_set(fixed);
    desktop_icons_init(fixed);
    desktop_context_menu_init(fixed);
    desktop_dragdrop_init(fixed);
    desktop_shortcuts_init(window);
    desktop_files_init(fixed);
    desktop_settings_init(window);
    desktop_notifications_init(window);
    desktop_clipboard_init(window);
    gtk_widget_show_all(window);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();
    return 0;
}
