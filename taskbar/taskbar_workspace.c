#include "taskbar_workspace.h"
#include <gtk/gtk.h>
static GtkWidget *workspace_box = NULL;
static int current_ws = 0;
#define NUM_WORKSPACES 4
void switch_workspace(GtkWidget *btn, gpointer data) {
    current_ws = GPOINTER_TO_INT(data);
    // Integrate with window manager to show/hide windows per workspace
}
void taskbar_workspace_init(GtkWidget *parent) {
    workspace_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    for (int i = 0; i < NUM_WORKSPACES; ++i) {
        char label[8];
        snprintf(label, sizeof(label), "%d", i+1);
        GtkWidget *btn = gtk_button_new_with_label(label);
        g_signal_connect(btn, "clicked", G_CALLBACK(switch_workspace), GINT_TO_POINTER(i));
        gtk_box_pack_start(GTK_BOX(workspace_box), btn, FALSE, FALSE, 0);
    }
    gtk_box_pack_start(GTK_BOX(parent), workspace_box, FALSE, FALSE, 0);
}
