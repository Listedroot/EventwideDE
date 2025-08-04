#include "start_menu_applications.h"
#include <gtk/gtk.h>
#include <dirent.h>
#include <stdio.h>
void start_menu_applications_init(GtkWidget *parent) {
    GtkWidget *apps_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    DIR *dir = opendir("/usr/share/applications");
    if (dir) {
        struct dirent *entry;
        while ((entry = readdir(dir))) {
            if (strstr(entry->d_name, ".desktop")) {
                GtkWidget *btn = gtk_button_new_with_label(entry->d_name);
                g_signal_connect(btn, "clicked", G_CALLBACK(g_spawn_command_line_async), entry->d_name);
                gtk_box_pack_start(GTK_BOX(apps_box), btn, FALSE, FALSE, 0);
            }
        }
        closedir(dir);
    }
    gtk_box_pack_start(GTK_BOX(parent), apps_box, TRUE, TRUE, 0);
}
