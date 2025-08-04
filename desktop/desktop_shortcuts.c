#include <gtk/gtk.h>
#include "desktop_shortcuts.h"
#include <stdio.h>

static gboolean on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer user_data) {
    if ((event->state & GDK_CONTROL_MASK) && event->keyval == GDK_KEY_r) {
        // Ctrl+R: Refresh desktop
        gtk_widget_queue_draw(widget);
        return TRUE;
    }
    if ((event->state & GDK_CONTROL_MASK) && event->keyval == GDK_KEY_d) {
        // Ctrl+D: Show desktop (minimize all windows)
        printf("Show desktop\n");
        return TRUE;
    }
    if ((event->state & GDK_CONTROL_MASK) && event->keyval == GDK_KEY_s) {
        // Ctrl+S: Open settings
        extern void desktop_settings_init(GtkWidget*);
        desktop_settings_init(widget);
        return TRUE;
    }
    if ((event->state & GDK_CONTROL_MASK) && event->keyval == GDK_KEY_n) {
        // Ctrl+N: Show notification
        extern void desktop_show_notification(GtkWidget*, const char*);
        desktop_show_notification(widget, "This is a test notification.");
        return TRUE;
    }
    if ((event->state & GDK_CONTROL_MASK) && event->keyval == GDK_KEY_w) {
        // Ctrl+W: Next wallpaper
        extern void desktop_wallpaper_next(GtkWidget*);
        desktop_wallpaper_next(widget);
        return TRUE;
    }
    if ((event->state & GDK_CONTROL_MASK) && event->keyval == GDK_KEY_l) {
        // Ctrl+L: Lock screen (stub)
        printf("Lock screen\n");
        return TRUE;
    }
    return FALSE;
}

void desktop_shortcuts_init(GtkWidget *window) {
    gtk_widget_add_events(window, GDK_KEY_PRESS_MASK);
    g_signal_connect(window, "key-press-event", G_CALLBACK(on_key_press), NULL);
}
