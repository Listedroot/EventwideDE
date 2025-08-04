#include "wm_input.h"
#include <gtk/gtk.h>
#include "wm_focus.h"
#include "wm_layout.h"
#include "wm_client.h"

static gboolean on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer user_data) {
    if ((event->state & GDK_CONTROL_MASK) && event->keyval == GDK_KEY_Tab) {
        wm_focus_next();
        return TRUE;
    }
    if ((event->state & GDK_CONTROL_MASK) && event->keyval == GDK_KEY_F4) {
        wm_client_remove(widget);
        return TRUE;
    }
    if ((event->state & GDK_MOD1_MASK) && event->keyval == GDK_KEY_space) {
        wm_layout_tile();
        return TRUE;
    }
    return FALSE;
}

static gboolean on_button_press(GtkWidget *widget, GdkEventButton *event, gpointer user_data) {
    if (event->button == 1) {
        wm_focus_next();
        return TRUE;
    }
    if (event->button == 3) {
        return TRUE;
    }
    return FALSE;
}

void wm_input_init_for_window(GtkWidget *window) {
    gtk_widget_add_events(window, GDK_KEY_PRESS_MASK | GDK_BUTTON_PRESS_MASK);
    g_signal_connect(window, "key-press-event", G_CALLBACK(on_key_press), NULL);
    g_signal_connect(window, "button-press-event", G_CALLBACK(on_button_press), NULL);
}

void wm_input_init(void) {}
