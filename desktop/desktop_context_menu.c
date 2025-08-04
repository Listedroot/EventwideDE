#include <gtk/gtk.h>
#include "desktop_context_menu.h"
#include "desktop_wallpaper.h"
#include <stdio.h>


static void on_create_folder(GtkMenuItem *item, gpointer user_data) {
    char path[512];
    snprintf(path, sizeof(path), "%s/NewFolder_%ld", getenv("HOME"), time(NULL));
    mkdir(path, 0755);
}

static void on_open_settings(GtkMenuItem *item, gpointer user_data) {
    desktop_settings_init(GTK_WIDGET(user_data));
}

static void on_cycle_wallpaper(GtkMenuItem *item, gpointer user_data) {
    desktop_wallpaper_next(GTK_WIDGET(user_data));
}

static void on_about(GtkMenuItem *item, gpointer user_data) {
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(user_data), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
        "EventwideDE\nA modern, classy desktop environment.");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

static void on_change_wallpaper(GtkMenuItem *item, gpointer user_data) {
    GtkWidget *dialog = gtk_file_chooser_dialog_new("Select Wallpaper", GTK_WINDOW(user_data), GTK_FILE_CHOOSER_ACTION_OPEN,
        "Cancel", GTK_RESPONSE_CANCEL, "Open", GTK_RESPONSE_ACCEPT, NULL);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        desktop_wallpaper_change(GTK_WIDGET(user_data), filename, 0);
        g_free(filename);
    }
    gtk_widget_destroy(dialog);
}

static gboolean on_button_press(GtkWidget *widget, GdkEventButton *event, gpointer user_data) {
    if (event->type == GDK_BUTTON_PRESS && event->button == 3) {
        GtkWidget *menu = gtk_menu_new();
        GtkWidget *change_wp = gtk_menu_item_new_with_label("Change Wallpaper");
        GtkWidget *cycle_wp = gtk_menu_item_new_with_label("Next Wallpaper");
        GtkWidget *create_folder = gtk_menu_item_new_with_label("Create Folder");
        GtkWidget *open_settings = gtk_menu_item_new_with_label("Settings");
        GtkWidget *about = gtk_menu_item_new_with_label("About EventwideDE");
        g_signal_connect(change_wp, "activate", G_CALLBACK(on_change_wallpaper), user_data);
        g_signal_connect(cycle_wp, "activate", G_CALLBACK(on_cycle_wallpaper), user_data);
        g_signal_connect(create_folder, "activate", G_CALLBACK(on_create_folder), user_data);
        g_signal_connect(open_settings, "activate", G_CALLBACK(on_open_settings), user_data);
        g_signal_connect(about, "activate", G_CALLBACK(on_about), user_data);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), change_wp);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), cycle_wp);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), create_folder);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), open_settings);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), about);
        gtk_widget_show_all(menu);
        gtk_menu_popup_at_pointer(GTK_MENU(menu), (GdkEvent*)event);
        return TRUE;
    }
    return FALSE;
}

void desktop_context_menu_init(GtkWidget *window) {
    g_signal_connect(window, "button-press-event", G_CALLBACK(on_button_press), window);
}
