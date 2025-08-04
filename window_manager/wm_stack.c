#include "wm_stack.h"
#include <gtk/gtk.h>

static GList *window_stack = NULL;

void wm_stack_init(void) {
    window_stack = NULL;
}

void wm_stack_raise(GtkWidget *window) {
    if (!g_list_find(window_stack, window))
        window_stack = g_list_append(window_stack, window);
    gtk_window_present(GTK_WINDOW(window));
}

void wm_stack_lower(GtkWidget *window) {
    if (g_list_find(window_stack, window)) {
        window_stack = g_list_remove(window_stack, window);
        window_stack = g_list_append(window_stack, window);
    }
    gdk_window_lower(gtk_widget_get_window(window));
}
