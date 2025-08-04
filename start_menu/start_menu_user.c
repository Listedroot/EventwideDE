#include "start_menu_user.h"
#include <gtk/gtk.h>
#include <pwd.h>
#include <unistd.h>
void start_menu_user_init(GtkWidget *parent) {
    struct passwd *pw = getpwuid(getuid());
    GtkWidget *label = gtk_label_new(pw ? pw->pw_name : "User");
    gtk_box_pack_start(GTK_BOX(parent), label, FALSE, FALSE, 0);
}
