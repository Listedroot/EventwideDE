#include <gtk/gtk.h>
#include "desktop_settings.h"
#include <stdio.h>

void desktop_settings_init(GtkWidget *window) {
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Desktop Settings", GTK_WINDOW(window), GTK_DIALOG_MODAL,
        "Close", GTK_RESPONSE_CLOSE, NULL);
    GtkWidget *content = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *wallpaper_label = gtk_label_new("Wallpaper:");
    GtkWidget *wallpaper_entry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(wallpaper_entry), "/usr/share/backgrounds/classy_wallpaper.jpg");
    GtkWidget *icon_size_label = gtk_label_new("Icon Size:");
    GtkWidget *icon_size_spin = gtk_spin_button_new_with_range(32, 128, 8);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(icon_size_spin), 48);
    GtkWidget *theme_label = gtk_label_new("Theme:");
    GtkWidget *theme_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(theme_combo), "Light");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(theme_combo), "Dark");
    gtk_combo_box_set_active(GTK_COMBO_BOX(theme_combo), 0);
    GtkWidget *notif_label = gtk_label_new("Enable Notifications:");
    GtkWidget *notif_switch = gtk_switch_new();
    gtk_switch_set_active(GTK_SWITCH(notif_switch), TRUE);
    gtk_box_pack_start(GTK_BOX(content), wallpaper_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(content), wallpaper_entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(content), icon_size_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(content), icon_size_spin, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(content), theme_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(content), theme_combo, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(content), notif_label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(content), notif_switch, FALSE, FALSE, 0);
    gtk_widget_show_all(dialog);
    g_signal_connect_swapped(dialog, "response", G_CALLBACK(gtk_widget_destroy), dialog);
}
