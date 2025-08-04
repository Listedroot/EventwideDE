#include "taskbar_power.h"
#include <gtk/gtk.h>
#include <stdio.h>
static GtkWidget *power_label = NULL;
static gboolean update_power(gpointer data) {
    FILE *f = fopen("/sys/class/power_supply/BAT0/capacity", "r");
    char buf[32] = "AC";
    if (f) {
        fgets(buf, sizeof(buf), f);
        fclose(f);
    }
    char label[64];
    snprintf(label, sizeof(label), "Power: %s%%", buf);
    gtk_label_set_text(GTK_LABEL(power_label), label);
    return TRUE;
}
void taskbar_power_init(GtkWidget *parent) {
    power_label = gtk_label_new("");
    gtk_box_pack_end(GTK_BOX(parent), power_label, FALSE, FALSE, 10);
    g_timeout_add_seconds(30, update_power, NULL);
}
