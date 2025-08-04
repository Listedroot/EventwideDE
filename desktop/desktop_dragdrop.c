#include <gtk/gtk.h>
#include "desktop_dragdrop.h"
#include <string.h>

static void on_drag_data_received(GtkWidget *widget, GdkDragContext *context, gint x, gint y,
                                  GtkSelectionData *data, guint info, guint time, gpointer user_data) {
    const gchar *dropped_data = (const gchar *)gtk_selection_data_get_data(data);
    if (dropped_data) {
        // Move the icon to the new position
        gtk_fixed_move(GTK_FIXED(user_data), widget, x, y);
    }
    gtk_drag_finish(context, TRUE, FALSE, time);
}

static void on_drag_begin(GtkWidget *widget, GdkDragContext *context, gpointer user_data) {
    // Optionally set a drag icon
    gtk_drag_set_icon_widget(context, widget, 0, 0);
}

void desktop_dragdrop_enable_icon(GtkWidget *icon, GtkWidget *fixed) {
    static GtkTargetEntry targets[] = {
        {"text/plain", 0, 0}
    };
    gtk_drag_source_set(icon, GDK_BUTTON1_MASK, targets, 1, GDK_ACTION_MOVE);
    gtk_drag_dest_set(icon, GTK_DEST_DEFAULT_ALL, targets, 1, GDK_ACTION_MOVE);
    g_signal_connect(icon, "drag-begin", G_CALLBACK(on_drag_begin), NULL);
    g_signal_connect(icon, "drag-data-received", G_CALLBACK(on_drag_data_received), fixed);
}

void desktop_dragdrop_init(GtkWidget *window) {
    // This function should be called after icons are added to the fixed container
    GList *children = gtk_container_get_children(GTK_CONTAINER(window));
    for (GList *l = children; l != NULL; l = l->next) {
        if (GTK_IS_BUTTON(l->data)) {
            desktop_dragdrop_enable_icon(GTK_WIDGET(l->data), window);
        }
    }
    g_list_free(children);
}
