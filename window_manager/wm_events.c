#include "wm_events.h"
#include <gtk/gtk.h>
#include <stdio.h>

void wm_events_init(void) {
    // Register for X events, window signals, etc.
    printf("Window manager events initialized.\n");
}
void wm_events_init(void) {
    GMainLoop *loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(loop);
}
