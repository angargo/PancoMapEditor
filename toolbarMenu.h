#ifndef _TOOLMENU_
#define _TOOLMENU_

#include <gtkmm/comboboxtext.h>
#include <gtkmm/liststore.h>
#include "baseToolbar.h"

class ToolbarMenu : public Gtk::ComboBox {
public:
  ToolbarMenu();
  static Glib::RefPtr<ToolbarMenu> create();
  void addEntry(Glib::ustring name, BaseToolbar *toolbar);
  void finishSetUp();

protected:
  class ModelColumns : public Gtk::TreeModel::ColumnRecord {
  public:
    ModelColumns() {
      add(name);
      add(toolbar);
    }
    Gtk::TreeModelColumn<Glib::ustring> name;
    Gtk::TreeModelColumn<BaseToolbar *> toolbar;
  };
  ModelColumns columns;

  Glib::RefPtr<Gtk::ListStore> pTable;
};

#endif
