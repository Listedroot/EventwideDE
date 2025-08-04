#include "start_menu_shortcuts.h"
#include <gtk/gtk.h>
static GtkWidget *shortcuts_box = NULL;
void start_menu_shortcuts_init(GtkWidget *parent) {
    shortcuts_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    gtk_box_pack_start(GTK_BOX(parent), shortcuts_box, FALSE, FALSE, 0);
}
void start_menu_shortcuts_add(const char *name, const char *cmd) {
    GtkWidget *btn = gtk_button_new_with_label(name);
    g_signal_connect(btn, "clicked", G_CALLBACK(g_spawn_command_line_async), (gpointer)cmd);
    gtk_box_pack_start(GTK_BOX(shortcuts_box), btn, FALSE, FALSE, 0);
    gtk_widget_show_all(shortcuts_box);
}
void start_menu_shortcuts_remove(const char *name) {
    GList *children = gtk_container_get_children(GTK_CONTAINER(shortcuts_box));
    for (GList *l = children; l; l = l->next) {
        GtkWidget *btn = GTK_WIDGET(l->data);
        const char *label = gtk_button_get_label(GTK_BUTTON(btn));
        if (label && strcmp(label, name) == 0) {
            gtk_widget_destroy(btn);
            break;
        }
    }
    g_list_free(children);
}
