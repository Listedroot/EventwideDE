#include "wm_main.h"
#include "wm_config.h"
#include "wm_events.h"
#include "wm_layout.h"
#include "wm_client.h"
#include "wm_focus.h"
#include "wm_stack.h"
#include "wm_compositor.h"
#include "wm_input.h"
#include "wm_rules.h"
#include "wm_util.h"
#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    wm_config_load();
    wm_compositor_init();
    wm_layout_init();
    wm_events_init();
    wm_input_init();
    wm_stack_init();
    wm_rules_init();
    wm_focus_init();
    wm_client_init();
    wm_util_log("EventwideDE Window Manager started.");
    gtk_main();
    return 0;
}
