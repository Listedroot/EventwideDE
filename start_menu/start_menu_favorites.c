#include "start_menu_favorites.h"
#include <gtk/gtk.h>
static GtkWidget *fav_box = NULL;
void start_menu_favorites_init(GtkWidget *parent) {
    fav_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    gtk_box_pack_start(GTK_BOX(parent), fav_box, FALSE, FALSE, 0);
}
void start_menu_favorites_add(const char *app) {
    GtkWidget *btn = gtk_button_new_with_label(app);
    gtk_box_pack_start(GTK_BOX(fav_box), btn, FALSE, FALSE, 0);
    gtk_widget_show_all(fav_box);
}
void start_menu_favorites_remove(const char *app) {
    GList *children = gtk_container_get_children(GTK_CONTAINER(fav_box));
    for (GList *l = children; l; l = l->next) {
        GtkWidget *btn = GTK_WIDGET(l->data);
        const char *label = gtk_button_get_label(GTK_BUTTON(btn));
        if (label && strcmp(label, app) == 0) {
            gtk_widget_destroy(btn);
            break;
        }
    }
    g_list_free(children);
}
