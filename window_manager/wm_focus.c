#include "wm_focus.h"
#include <gtk/gtk.h>

void wm_focus_init(void) {
    // Focus management
}
void wm_focus_init(void) {
    // Initialize focus management
}

static GList *focus_list = NULL;
static GtkWidget *focused_window = NULL;

void wm_focus_init(void) {
    focus_list = NULL;
    focused_window = NULL;
}

void wm_focus_next(void) {
    if (!focus_list) return;
    if (!focused_window) {
        focused_window = GTK_WIDGET(focus_list->data);
    } else {
        GList *node = g_list_find(focus_list, focused_window);
        if (node && node->next)
            focused_window = GTK_WIDGET(node->next->data);
        else
            focused_window = GTK_WIDGET(focus_list->data);
    }
    gtk_window_present(GTK_WINDOW(focused_window));
}

void wm_focus_prev(void) {
    if (!focus_list) return;
    if (!focused_window) {
        focused_window = GTK_WIDGET(g_list_last(focus_list)->data);
    } else {
        GList *node = g_list_find(focus_list, focused_window);
        if (node && node->prev)
            focused_window = GTK_WIDGET(node->prev->data);
        else
            focused_window = GTK_WIDGET(g_list_last(focus_list)->data);
    }
    gtk_window_present(GTK_WINDOW(focused_window));
}
    // Focus the previous window in the stack
}
