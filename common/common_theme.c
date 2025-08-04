#include "common_theme.h"
#include <gtk/gtk.h>
void common_theme_apply(GtkWidget *widget, const char *theme) {
    GtkCssProvider *provider = gtk_css_provider_new();
    char css[256];
    snprintf(css, sizeof(css), "@import url('file:///%s.css');", theme);
    gtk_css_provider_load_from_data(provider, css, -1, NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(provider);
}
