#ifndef _BASEBAR_
#define _BASEBAR_

#include <gtkmm.h>

class BaseToolbar : public Gtk::Toolbar {
public:
  BaseToolbar(Gtk::ComboBox *pSwitcher);
  static Glib::RefPtr<BaseToolbar> create(Gtk::ComboBox *pSwitcher);

protected:
  //Gtk::ComboBox *pSwitcher;
};

#endif
