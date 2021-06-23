#include <gtk/gtk.h>

#include "tedditor.h"
#include "tedditorwin.h"

struct _TedditorWindow
{
    GtkApplicationWindow parent;
};

G_DEFINE_TYPE(TedditorWindow, tedditor_window, GTK_TYPE_APPLICATION_WINDOW);

static void
tedditor_window_init (TedditorWindow *app)
{
}

static void
tedditor_window_class_init (TedditorWindowClass *class)
{
}

TedditorWindow *
tedditor_window_new (Tedditor *app)
{
    return g_object_new (TEDDITOR_WINDOW_TYPE, "application", app, NULL);
}

void
tedditor_window_open (TedditorWindow *win,
                      GFile          *file)
{
}