#include "taskbar_network.h"
#include <gtk/gtk.h>
#include <stdio.h>
static GtkWidget *net_label = NULL;
static gboolean update_network(gpointer data) {
    FILE *f = fopen("/proc/net/wireless", "r");
    char buf[128] = "Disconnected";
    if (f) {
        fgets(buf, sizeof(buf), f);
        fgets(buf, sizeof(buf), f);
        fgets(buf, sizeof(buf), f);
        char *p = strchr(buf, ':');
        if (p) snprintf(buf, sizeof(buf), "WiFi: %s", p+1);
        fclose(f);
    }
    gtk_label_set_text(GTK_LABEL(net_label), buf);
    return TRUE;
}
void taskbar_network_init(GtkWidget *parent) {
    net_label = gtk_label_new("");
    gtk_box_pack_end(GTK_BOX(parent), net_label, FALSE, FALSE, 10);
    g_timeout_add_seconds(5, update_network, NULL);
}
