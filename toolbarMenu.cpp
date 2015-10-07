#include "toolbarMenu.h"

ToolbarMenu::ToolbarMenu() : Gtk::ComboBox() {
  pTable = Gtk::ListStore::create(columns);
  set_model(pTable);
  addEntry("Terrain", nullptr);
  addEntry("Sims", nullptr);
  addEntry("SFX", nullptr);
  addEntry("Logic", nullptr);
}

void ToolbarMenu::addEntry(Glib::ustring name, BaseToolbar *toolbar) {
  Gtk::TreeModel::Row row = *(pTable->append());
  row[columns.name] = name;
  row[columns.toolbar] = toolbar;
}

void ToolbarMenu::finishSetUp(){
  pack_start(columns.name);
}

Glib::RefPtr<ToolbarMenu> ToolbarMenu::create() {
  return Glib::RefPtr<ToolbarMenu>(new ToolbarMenu());
}
