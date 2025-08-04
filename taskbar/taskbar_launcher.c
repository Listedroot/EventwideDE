#include "taskbar_launcher.h"
#include <gtk/gtk.h>
static GtkWidget *launcher_box = NULL;
void taskbar_launcher_init(GtkWidget *parent) {
    launcher_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    gtk_box_pack_start(GTK_BOX(parent), launcher_box, FALSE, FALSE, 0);
}
void taskbar_launcher_add(const char *icon_path, const char *exec_cmd) {
    GtkWidget *img = gtk_image_new_from_file(icon_path);
    GtkWidget *btn = gtk_button_new();
    gtk_container_add(GTK_CONTAINER(btn), img);
    g_signal_connect(btn, "clicked", G_CALLBACK(g_spawn_command_line_async), (gpointer)exec_cmd);
    gtk_box_pack_start(GTK_BOX(launcher_box), btn, FALSE, FALSE, 0);
    gtk_widget_show_all(launcher_box);
}
void taskbar_launcher_remove(const char *exec_cmd) {
    GList *children = gtk_container_get_children(GTK_CONTAINER(launcher_box));
    for (GList *l = children; l; l = l->next) {
        GtkWidget *btn = GTK_WIDGET(l->data);
        // Removal logic can be implemented by storing exec_cmd in button data
    }
    g_list_free(children);
}
