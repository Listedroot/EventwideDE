#ifndef DESKTOP_CLIPBOARD_H
#define DESKTOP_CLIPBOARD_H
#include <gtk/gtk.h>
void desktop_clipboard_init(GtkWidget *window);
void desktop_clipboard_set_text(const char *text);
char *desktop_clipboard_get_text(void);
void desktop_clipboard_set_image(GdkPixbuf *pixbuf);
GdkPixbuf *desktop_clipboard_get_image(void);
#endif
