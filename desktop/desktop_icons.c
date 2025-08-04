#include <gtk/gtk.h>
#include "desktop_icons.h"
#include "desktop_dragdrop.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Path to .desktop files (Linux/Freedesktop standard)
#define APPLICATIONS_DIR "/usr/share/applications"

static void launch_app(const char *exec_cmd) {
    if (fork() == 0) {
        setsid();
        execl("/bin/sh", "sh", "-c", exec_cmd, NULL);
        exit(1);
    }
}

static void on_icon_clicked(GtkWidget *widget, gpointer user_data) {
    const char *exec_cmd = (const char *)user_data;
    launch_app(exec_cmd);
}

static void add_app_icon(GtkWidget *fixed, const char *name, const char *icon_path, const char *exec_cmd, int x, int y) {
    GtkWidget *icon_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *image = gtk_image_new_from_file(icon_path);
    GtkWidget *label = gtk_label_new(name);
    GtkWidget *button = gtk_button_new();
    gtk_container_add(GTK_CONTAINER(button), icon_box);
    gtk_box_pack_start(GTK_BOX(icon_box), image, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(icon_box), label, FALSE, FALSE, 0);
    g_signal_connect(button, "clicked", G_CALLBACK(on_icon_clicked), g_strdup(exec_cmd));
    gtk_fixed_put(GTK_FIXED(fixed), button, x, y);
    desktop_dragdrop_enable_icon(button, fixed);
}

static void parse_desktop_file(GtkWidget *fixed, const char *filepath, int *x, int *y) {
    FILE *f = fopen(filepath, "r");
    if (!f) return;
    char line[512], name[128] = "", icon[256] = "", exec[256] = "";
    while (fgets(line, sizeof(line), f)) {
        if (strncmp(line, "Name=", 5) == 0) {
            strncpy(name, line+5, sizeof(name)-1);
            name[strcspn(name, "\n")] = 0;
        } else if (strncmp(line, "Icon=", 5) == 0) {
            strncpy(icon, line+5, sizeof(icon)-1);
            icon[strcspn(icon, "\n")] = 0;
        } else if (strncmp(line, "Exec=", 5) == 0) {
            strncpy(exec, line+5, sizeof(exec)-1);
            exec[strcspn(exec, "\n")] = 0;
        }
    }
    fclose(f);
    if (name[0] && exec[0]) {
        char icon_path[512];
        if (icon[0] && icon[0] != '/') {
            snprintf(icon_path, sizeof(icon_path), "/usr/share/icons/hicolor/48x48/apps/%s.png", icon);
        } else if (icon[0]) {
            strncpy(icon_path, icon, sizeof(icon_path)-1);
        } else {
            strcpy(icon_path, "/usr/share/pixmaps/application-default-icon.png");
        }
        add_app_icon(fixed, name, icon_path, exec, *x, *y);
        *x += 100;
        if (*x > 800) { *x = 50; *y += 100; }
    }
}

void desktop_icons_init(GtkWidget *window) {
    GtkWidget *fixed = window;
    DIR *dir = opendir(APPLICATIONS_DIR);
    if (!dir) return;
    struct dirent *entry;
    int x = 50, y = 50;
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".desktop")) {
            char filepath[512];
            snprintf(filepath, sizeof(filepath), "%s/%s", APPLICATIONS_DIR, entry->d_name);
            parse_desktop_file(fixed, filepath, &x, &y);
        }
    }
    closedir(dir);
}
