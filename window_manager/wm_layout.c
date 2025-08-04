#include "wm_layout.h"
#include <gtk/gtk.h>

void wm_layout_init(void) {
    // Tiling, floating, and stacking layouts
}
void wm_layout_init(void) {
    // Initialize tiling, floating, and stacking layouts
}

void wm_layout_tile(void) {
    // Arrange windows in a grid
}
void wm_layout_tile(void) {
    // Arrange windows in a grid layout
}

void wm_layout_float(void) {
    // Allow windows to be freely moved
}
void wm_layout_float(void) {
    // Enable floating window mode
}

static GList *layout_windows = NULL;

void wm_layout_init(void) {
    layout_windows = NULL;
}

void wm_layout_tile(void) {
    int n = g_list_length(layout_windows);
    if (n == 0) return;
    int cols = (int)ceil(sqrt(n));
    int rows = (n + cols - 1) / cols;
    int w = 1920 / cols;
    int h = 1080 / rows;
    int i = 0;
    for (GList *l = layout_windows; l; l = l->next, ++i) {
        int x = (i % cols) * w;
        int y = (i / cols) * h;
        gtk_window_move(GTK_WINDOW(l->data), x, y);
        gtk_window_resize(GTK_WINDOW(l->data), w, h);
    }
}

void wm_layout_float(void) {
    for (GList *l = layout_windows; l; l = l->next) {
        gtk_window_set_resizable(GTK_WINDOW(l->data), TRUE);
    }
}

void wm_layout_stack(void) {
    int y = 0;
    for (GList *l = layout_windows; l; l = l->next, y += 40) {
        gtk_window_move(GTK_WINDOW(l->data), 100, y);
        gtk_window_resize(GTK_WINDOW(l->data), 800, 40);
    }
}
    // Stack windows in Z-order
