#include <gtk/gtk.h>

static void open (GtkWidget *widget, gpointer data)
{
  g_print ("Warning: Not yet implemented\n");
}

static void save (GtkWidget *widget, gpointer data)
{
  g_print ("Warning: Not yet implemented\n");
}

static void save_as (GtkWidget *widget, gpointer data)
{
  g_print ("Warning: Not yet implemented\n");
}

static void activate (GtkApplication* app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *grid;

  //Create new window and set its title
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Tedditor");

  //construct the grid / the container for the buttons
  grid = gtk_grid_new();

  //Packing the grid / the container into the window
  gtk_window_set_child (GTK_WINDOW (window), grid);

  button = gtk_button_new_with_label ("Open...");
  g_signal_connect (button, "clicked", G_CALLBACK (open), NULL);

  //Place the first button in the grid cell (0,0) and make it fill just 1 cell horizontally and vertically (ie no spanning)
  gtk_grid_attach (GTK_GRID (grid), button, 0, 0, 1, 1);

  button = gtk_button_new_with_label ("Save");
  g_signal_connect (button, "clicked", G_CALLBACK (save), NULL);

  gtk_grid_attach (GTK_GRID (grid), button, 1, 0, 1, 1);

  button = gtk_button_new_with_label ("Quit");
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window);

  gtk_grid_attach (GTK_GRID (grid), button, 0, 1, 2, 1);

  gtk_widget_show (window);
}

int main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("com.github.erdragh.tedditor", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}