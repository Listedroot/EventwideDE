#include "start_menu_applications.h"
#include "start_menu_search.h"
#include "start_menu_favorites.h"
#include "start_menu_power.h"
#include "start_menu_user.h"
#include "start_menu_recent.h"
#include "start_menu_settings.h"
#include "start_menu_session.h"
#include "start_menu_shortcuts.h"
#include "start_menu_utils.h"
#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "EventwideDE Start Menu");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 600);
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    start_menu_user_init(vbox);
    start_menu_search_init(vbox);
    start_menu_favorites_init(vbox);
    start_menu_applications_init(vbox);
    start_menu_recent_init(vbox);
    start_menu_shortcuts_init(vbox);
    start_menu_settings_init(vbox);
    start_menu_power_init(vbox);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
