#include <gtk/gtk.h>
#include "desktop_clipboard.h"
#include <stdio.h>

static char clipboard_history[10][256];
static int clipboard_count = 0;

void desktop_clipboard_set_text(const char *text) {
    GtkClipboard *clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    gtk_clipboard_set_text(clipboard, text, -1);
    if (clipboard_count < 10) {
        strncpy(clipboard_history[clipboard_count++], text, 255);
    }
}

char *desktop_clipboard_get_text(void) {
    GtkClipboard *clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    return gtk_clipboard_wait_for_text(clipboard);
}

void desktop_clipboard_set_image(GdkPixbuf *pixbuf) {
    GtkClipboard *clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    gtk_clipboard_set_image(clipboard, pixbuf);
}

GdkPixbuf *desktop_clipboard_get_image(void) {
    GtkClipboard *clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    return gtk_clipboard_wait_for_image(clipboard);
}

void desktop_clipboard_init(GtkWidget *window) {
    // Clipboard ready for text and image copy/paste
}
