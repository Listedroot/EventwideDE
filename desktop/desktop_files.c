#include <gtk/gtk.h>
#include "desktop_files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>


static void create_folder(const char *path) {
    mkdir(path, 0755);
}

static void delete_file(const char *path) {
    remove(path);
}

static void rename_file(const char *old_path, const char *new_path) {
    rename(old_path, new_path);
}

static void move_file(const char *src, const char *dst) {
    rename(src, dst);
}

static void copy_file(const char *src, const char *dst) {
    FILE *f1 = fopen(src, "rb");
    FILE *f2 = fopen(dst, "wb");
    if (!f1 || !f2) return;
    char buf[4096];
    size_t n;
    while ((n = fread(buf, 1, sizeof(buf), f1)) > 0) fwrite(buf, 1, n, f2);
    fclose(f1); fclose(f2);
}

static void show_file_properties(const char *path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        printf("File: %s\nSize: %ld\n", path, st.st_size);
    }
}

void desktop_files_init(GtkWidget *window) {
    // Integrate with context menu for file ops
    // Example: create_folder("~/Desktop/NewFolder");
}
