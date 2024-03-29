#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm.h>
#include "canvas.h"
#include "leftPane.h"
#include "rightPane.h"
#include "baseToolbar.h"
#include "toolbarMenu.h"

class MainWindow : public Gtk::Window {
public:
  MainWindow();
  virtual ~MainWindow();

private:
  Gtk::Box Box;
  Glib::RefPtr<Gtk::Builder> refBuilder;
  Glib::RefPtr<Gio::SimpleActionGroup> refActionGroup;
  Gtk::Paned HPaned;
  LeftPane leftPane;
  RightPane rightPane;
  ToolbarMenu* pToolbarMenu;
  BaseToolbar* pTestee;

  void filler();
  void on_menu_new();
  void on_menu_open();
  void on_menu_save();
  void on_menu_save_as();
  void on_menu_quit();

  void on_menu_help();
  void on_menu_about();

  void make_actions();
  void make_menu_bar();
  void make_toolbars();
};

#endif // MAINWINDOW_H
