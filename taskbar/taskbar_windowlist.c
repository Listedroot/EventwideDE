#include "taskbar_windowlist.h"
#include <gtk/gtk.h>
#include <gdk/gdk.h>
static GtkWidget *windowlist_box = NULL;
void taskbar_windowlist_init(GtkWidget *parent) {
    windowlist_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    gtk_box_pack_start(GTK_BOX(parent), windowlist_box, FALSE, FALSE, 0);
}
void taskbar_windowlist_add(const char *title, GdkWindow *gdk_window) {
    GtkWidget *btn = gtk_button_new_with_label(title);
    g_signal_connect(btn, "clicked", G_CALLBACK(gtk_window_present), gdk_window);
    gtk_box_pack_start(GTK_BOX(windowlist_box), btn, FALSE, FALSE, 0);
    gtk_widget_show_all(windowlist_box);
}
void taskbar_windowlist_remove(const char *title) {
    GList *children = gtk_container_get_children(GTK_CONTAINER(windowlist_box));
    for (GList *l = children; l; l = l->next) {
        GtkWidget *btn = GTK_WIDGET(l->data);
        const char *label = gtk_button_get_label(GTK_BUTTON(btn));
        if (label && strcmp(label, title) == 0) {
            gtk_widget_destroy(btn);
            break;
        }
    }
    g_list_free(children);
}
