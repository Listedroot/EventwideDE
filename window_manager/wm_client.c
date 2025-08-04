#include "wm_client.h"
#include <gtk/gtk.h>
#include <stdio.h>

static GList *clients = NULL;

void wm_client_init(void) {
    clients = NULL;
}

void wm_client_add(GtkWidget *window) {
    if (!g_list_find(clients, window))
        clients = g_list_append(clients, window);
}

void wm_client_remove(GtkWidget *window) {
    clients = g_list_remove(clients, window);
}
