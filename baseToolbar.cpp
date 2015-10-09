#include "baseToolbar.h"

BaseToolbar::BaseToolbar(Gtk::ComboBox *pSwitcher) : Gtk::Toolbar() {
  // this->pSwitcher = pSwitcher;
  Gtk::ToolItem* container = Gtk::manage(new Gtk::ToolItem());
  add(*container);
  container->add(*pSwitcher);
  Gtk::ToolButton* button = Gtk::manage(new Gtk::ToolButton());
  button->set_icon_name("document-new");
  add(*button);
}

Glib::RefPtr<BaseToolbar> BaseToolbar::create(Gtk::ComboBox *pSwitcher) {
  return Glib::RefPtr<BaseToolbar>(new BaseToolbar(pSwitcher));
}
