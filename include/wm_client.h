#ifndef WM_CLIENT_H
#define WM_CLIENT_H
#include <gtk/gtk.h>
void wm_client_init(void);
void wm_client_add(GtkWidget *window);
void wm_client_remove(GtkWidget *window);
#endif
