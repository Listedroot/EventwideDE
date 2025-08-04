#include "common_clipboard.h"
#include <gtk/gtk.h>
void common_clipboard_set_text(const char *text) {
    GtkClipboard *clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    gtk_clipboard_set_text(clipboard, text, -1);
}
char *common_clipboard_get_text(void) {
    GtkClipboard *clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    return gtk_clipboard_wait_for_text(clipboard);
}
