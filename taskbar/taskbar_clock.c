#include "taskbar_clock.h"
#include <gtk/gtk.h>
#include <time.h>
static GtkWidget *clock_label = NULL;
static gboolean update_clock(gpointer data) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char buf[64];
    strftime(buf, sizeof(buf), "%H:%M:%S", tm);
    gtk_label_set_text(GTK_LABEL(clock_label), buf);
    return TRUE;
}
void taskbar_clock_init(GtkWidget *parent) {
    clock_label = gtk_label_new("");
    gtk_box_pack_end(GTK_BOX(parent), clock_label, FALSE, FALSE, 10);
    g_timeout_add_seconds(1, update_clock, NULL);
}
