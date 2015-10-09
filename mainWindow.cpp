#include "mainWindow.h"
#include <iostream>

MainWindow::MainWindow()
    : Box(Gtk::ORIENTATION_VERTICAL), HPaned(Gtk::ORIENTATION_HORIZONTAL),
      leftPane(), rightPane() {
  set_title("Map Editor");
  set_size_request(1200, 900);
  set_border_width(6);

  add(Box);

  // create actions
  refActionGroup = Gio::SimpleActionGroup::create();
  make_actions();

  refBuilder = Gtk::Builder::create();
  make_menu_bar();

  make_toolbars();

  HPaned.add1(leftPane);
  HPaned.add2(rightPane);
  HPaned.set_position(1000);
  Box.pack_start(HPaned, Gtk::PACK_EXPAND_WIDGET);
  show_all_children();
}

MainWindow::~MainWindow() {
  std::cout << "destroying window" << std::endl;
  delete pToolbarMenu;
  delete pTestee;
}

void MainWindow::make_actions() {
  refActionGroup->add_action("new",
                             []() { std::cout << "new lambda" << std::endl; });
  refActionGroup->add_action("open",
                             []() { std::cout << "open lambda" << std::endl; });
  refActionGroup->add_action("save",
                             []() { std::cout << "save lambda" << std::endl; });
  refActionGroup->add_action(
      "save_as", []() { std::cout << "save as lambda" << std::endl; });
  refActionGroup->add_action("quit", [this]() { this->hide(); });
  refActionGroup->add_action("help",
                             []() { std::cout << "help lambda" << std::endl; });
  refActionGroup->add_action(
      "about", []() { std::cout << "about lambda" << std::endl; });

  insert_action_group("menu_actions", refActionGroup);
}

void MainWindow::make_toolbars() {
  pToolbarMenu = new ToolbarMenu();
  pTestee = new BaseToolbar(pToolbarMenu);
  pToolbarMenu->finishSetUp();
  Box.pack_start(*pTestee, Gtk::PACK_SHRINK);
}

void MainWindow::make_menu_bar() {
  Glib::ustring ui_info =
      "<interface>"
      "  <menu id='top-menu'>"
      "    <submenu>"
      "      <attribute name='label'>_File</attribute>"
      "      <section>"
      "        <item>"
      "          <attribute name='label'>_New</attribute>"
      "          <attribute name='action'>menu_actions.new</attribute>"
      "          <attribute name='accel'>&lt;Primary&gt;n</attribute>"
      "        </item>"
      "        <item>"
      "          <attribute name='label'>_Open</attribute>"
      "          <attribute name='action'>menu_actions.open</attribute>"
      "          <attribute name='accel'>&lt;Primary&gt;o</attribute>"
      "        </item>"
      "      </section>"
      "      <section>"
      "        <item>"
      "          <attribute name='label'>_Save</attribute>"
      "          <attribute name='action'>menu_actions.save</attribute>"
      "          <attribute name='accel'>&lt;Primary&gt;s</attribute>"
      "        </item>"
      "        <item>"
      "          <attribute name='label'>Save as</attribute>"
      "          <attribute name='action'>menu_actions.save_as</attribute>"
      "        </item>"
      "      </section>"
      "      <section>"
      "        <item>"
      "          <attribute name='label'>_Quit</attribute>"
      "          <attribute name='action'>menu_actions.quit</attribute>"
      "          <attribute name='accel'>&lt;Primary&gt;q</attribute>"
      "        </item>"
      "      </section>"
      "    </submenu>"
      "    <submenu>"
      "      <attribute name='label'>_Help</attribute>"
      "      <section>"
      "        <item>"
      "          <attribute name='label'>_Help</attribute>"
      "          <attribute name='action'>menu_actions.help</attribute>"
      "          <attribute name='accel'>&lt;Primary&gt;h</attribute>"
      "        </item>"
      "      </section>"
      "      <section>"
      "        <item>"
      "          <attribute name='label'>_About</attribute>"
      "          <attribute name='action'>menu_actions.about</attribute>"
      "        </item>"
      "      </section>"
      "    </submenu>"
      "  </menu>"
      "</interface>";

  try {
    refBuilder->add_from_string(ui_info);
  } catch (const Glib::Error &ex) {
    std::cerr << "building menus failed: " << ex.what();
  }

  // get menubar
  Glib::RefPtr<Glib::Object> object = refBuilder->get_object("top-menu");
  Glib::RefPtr<Gio::Menu> gmenu = Glib::RefPtr<Gio::Menu>::cast_dynamic(object);
  if (!gmenu)
    g_warning("GMenu not found");

  // put it there
  Gtk::MenuBar *pMenubar = Gtk::manage(new Gtk::MenuBar(gmenu));
  Box.pack_start(*pMenubar, Gtk::PACK_SHRINK);
}
