#include "mainWindow.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
  Glib::RefPtr<Gtk::Application> app =
      Gtk::Application::create(argc, argv, "tk.mysticode.panco.mapeditor");

  MainWindow window;

  app->run(window);
  return 0;
}
