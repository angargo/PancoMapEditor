#include "baseToolbar.h"

BaseToolbar::BaseToolbar(Gtk::ComboBox *pSwitcher) : Gtk::Toolbar() {
  // this->pSwitcher = pSwitcher;
  Gtk::ToolItem container;
  add(container);
  container.add(*pSwitcher);
}

Glib::RefPtr<BaseToolbar> BaseToolbar::create(Gtk::ComboBox *pSwitcher) {
  return Glib::RefPtr<BaseToolbar>(new BaseToolbar(pSwitcher));
}
