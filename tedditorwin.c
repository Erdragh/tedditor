#include <gtk/gtk.h>

#include "tedditor.h"
#include "tedditorwin.h"

struct _TedditorWindow
{
    GtkApplicationWindow parent;

    GSettings *settings;
    GtkWidget *stack;
    GtkWidget *gears;
};

G_DEFINE_TYPE(TedditorWindow, tedditor_window, GTK_TYPE_APPLICATION_WINDOW);

static void
tedditor_window_init (TedditorWindow *win)
{
    GtkBuilder *builder;
    GMenuModel *menu;

    gtk_widget_init_template (GTK_WIDGET (win));

    builder = gtk_builder_new_from_resource ("/com/github/erdragh/tedditor/gears-menu.ui");
    menu = G_MENU_MODEL (gtk_builder_get_object (builder, "menu"));
    gtk_menu_button_set_menu_model (GTK_MENU_BUTTON (win->gears), menu);
    g_object_unref (builder);

    win->settings = g_settings_new ("com.github.erdragh.tedditor");
    g_settings_bind (win->settings, "transition", win->stack, "transition-type", G_SETTINGS_BIND_DEFAULT);
}

static void 
tedditor_window_dispose (GObject *object)
{
    TedditorWindow *win;

    win = TEDDITOR_APP_WINDOW (object);

    g_clear_object (&win->settings);

    G_OBJECT_CLASS (tedditor_window_parent_class)->dispose (object);
}

static void
tedditor_window_class_init (TedditorWindowClass *class)
{
    G_OBJECT_CLASS (class)->dispose = tedditor_window_dispose;

    gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (class), "/com/github/erdragh/tedditor/window.ui");

    gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (class), TedditorWindow, stack);
    gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (class), TedditorWindow, gears);
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
    GtkTextBuffer *buffer;
    GtkTextTag *tag;
    GtkTextIter start_iter, end_iter;

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

    buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));

    if (g_file_load_contents (file, NULL, &contents, &length, NULL, NULL))
    {
        gtk_text_buffer_set_text (buffer, contents, length);
        g_free (contents);
    }

    tag = gtk_text_buffer_create_tag (buffer, NULL, NULL);
    g_settings_bind (win->settings, "font", tag, "font", G_SETTINGS_BIND_DEFAULT);

    gtk_text_buffer_get_start_iter (buffer, &start_iter);
    gtk_text_buffer_get_end_iter (buffer, &end_iter);
    gtk_text_buffer_apply_tag (buffer, tag, &start_iter, &end_iter);

    g_free (basename);
}