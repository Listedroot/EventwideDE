#include "taskbar_windowlist.h"
#include "taskbar_clock.h"
#include "taskbar_tray.h"
#include "taskbar_launcher.h"
#include "taskbar_workspace.h"
#include "taskbar_menu.h"
#include "taskbar_volume.h"
#include "taskbar_network.h"
#include "taskbar_power.h"
#include "taskbar_notifications.h"
#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "EventwideDE Taskbar");
    gtk_window_set_type_hint(GTK_WINDOW(window), GDK_WINDOW_TYPE_HINT_DOCK);
    gtk_window_set_decorated(GTK_WINDOW(window), FALSE);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_window_set_default_size(GTK_WINDOW(window), 1920, 40);
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box);
    taskbar_windowlist_init(box);
    taskbar_workspace_init(box);
    taskbar_launcher_init(box);
    taskbar_tray_init(box);
    taskbar_clock_init(box);
    taskbar_volume_init(box);
    taskbar_network_init(box);
    taskbar_power_init(box);
    taskbar_notifications_init(box);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
