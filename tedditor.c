#include <gtk/gtk.h>

#include "tedditor.h"
#include "tedditorwin.h"

struct _Tedditor
{
    GtkApplication parent;
};

G_DEFINE_TYPE (Tedditor, tedditor, GTK_TYPE_APPLICATION);

static void
tedditor_init (Tedditor *app)
{
}

static void
tedditor_activate (GApplication *app)
{
    TedditorWindow *win;

    win = tedditor_window_new (TEDDITOR_APP (app));
    gtk_window_present (GTK_WINDOW (win));
}

static void
tedditor_open (GApplication *app,
               GFile **files,
               int n_files,
               const char *hint)
{
    GList *windows;
    TedditorWindow *win;
    int i;

    windows = gtk_application_get_windows (GTK_APPLICATION (app));
    if (windows)
        win = TEDDITOR_APP_WINDOW (windows->data);
    else
        win = tedditor_window_new (TEDDITOR_APP (app));

    for (i = 0; i < n_files; i++)
        tedditor_window_open (win, files[i]);
    
    gtk_window_present (GTK_WINDOW (win));
}

static void
tedditor_class_init (TedditorClass *class) {
    G_APPLICATION_CLASS (class)->activate = tedditor_activate;
    G_APPLICATION_CLASS (class)->open = tedditor_open;
}

Tedditor *
tedditor_new (void)
{
    return g_object_new (TEDDITOR_TYPE,
                         "application-id", "com.github.erdragh.tedditor",
                         "flags", G_APPLICATION_HANDLES_OPEN,
                         NULL);
}