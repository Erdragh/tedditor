#include <gtk/gtk.h>

#include "tedditor.h"
#include "tedditorwin.h"

struct _TedditorWindow
{
    GtkApplicationWindow parent;

    GtkWidget *stack;
};

G_DEFINE_TYPE(TedditorWindow, tedditor_window, GTK_TYPE_APPLICATION_WINDOW);

static void
tedditor_window_init (TedditorWindow *win)
{
    gtk_widget_init_template (GTK_WIDGET (win));
}

static void
tedditor_window_class_init (TedditorWindowClass *class)
{
    gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (class), "/com/github/erdragh/tedditor/window.ui");

    gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (class), TedditorWindow, stack);
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
    char *basename;
    GtkWidget *scrolled, *view;
    char *contents;
    gsize length;

    basename = g_file_get_basename (file);

    scrolled = gtk_scrolled_window_new ();
    gtk_widget_set_hexpand (scrolled, TRUE);
    gtk_widget_set_vexpand (scrolled, TRUE);
    view = gtk_text_view_new ();
    gtk_text_view_set_editable (GTK_TEXT_VIEW (view), FALSE);
    gtk_text_view_set_cursor_visible (GTK_TEXT_VIEW (view), FALSE);
    gtk_text_view_set_monospace (GTK_TEXT_VIEW (view), TRUE);
    gtk_text_view_set_top_margin (GTK_TEXT_VIEW (view), 15);
    gtk_text_view_set_bottom_margin (GTK_TEXT_VIEW (view), 15);
    gtk_text_view_set_left_margin (GTK_TEXT_VIEW (view), 15);
    gtk_text_view_set_right_margin (GTK_TEXT_VIEW (view), 15);
    gtk_scrolled_window_set_child (GTK_SCROLLED_WINDOW (scrolled), view);
    gtk_stack_add_titled (GTK_STACK (win->stack), scrolled, basename, basename);

    if (g_file_load_contents (file, NULL, &contents, &length, NULL, NULL))
    {
        GtkTextBuffer *buffer;

        buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));
        gtk_text_buffer_set_text (buffer, contents, length);
        g_free (contents);
    }
    g_free (basename);
}