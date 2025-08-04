#ifndef WM_STACK_H
#define WM_STACK_H
#include <gtk/gtk.h>
void wm_stack_init(void);
void wm_stack_raise(GtkWidget *window);
void wm_stack_lower(GtkWidget *window);
#endif
