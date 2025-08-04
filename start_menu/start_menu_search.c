#include "start_menu_search.h"
#include <gtk/gtk.h>
#include <string.h>
static GtkWidget *search_entry = NULL;
void on_search_changed(GtkEntry *entry, gpointer user_data) {
    const char *text = gtk_entry_get_text(entry);
    // Integrate with application list filtering
}
void start_menu_search_init(GtkWidget *parent) {
    search_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(search_entry), "Search apps...");
    g_signal_connect(search_entry, "changed", G_CALLBACK(on_search_changed), NULL);
    gtk_box_pack_start(GTK_BOX(parent), search_entry, FALSE, FALSE, 0);
}
