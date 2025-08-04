#include "start_menu_recent.h"
#include <gtk/gtk.h>
static GtkWidget *recent_box = NULL;
void start_menu_recent_init(GtkWidget *parent) {
    recent_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(parent), recent_box, FALSE, FALSE, 0);
}
void start_menu_recent_add(const char *app) {
    GtkWidget *btn = gtk_button_new_with_label(app);
    gtk_box_pack_start(GTK_BOX(recent_box), btn, FALSE, FALSE, 0);
    gtk_widget_show_all(recent_box);
}
void start_menu_recent_clear(void) {
    GList *children = gtk_container_get_children(GTK_CONTAINER(recent_box));
    for (GList *l = children; l; l = l->next) gtk_widget_destroy(GTK_WIDGET(l->data));
    g_list_free(children);
}
