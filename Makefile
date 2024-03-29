ADDED_CXXFLAGS=
CXXFLAGS=-Wall -g -p -std=c++11
GTKCFLAGS=-pthread -I/usr/include/gtkmm-3.0 -I/usr/lib/x86_64-linux-gnu/gtkmm-3.0/include -I/usr/include/atkmm-1.6 -I/usr/include/giomm-2.4 -I/usr/lib/x86_64-linux-gnu/giomm-2.4/include -I/usr/include/pangomm-1.4 -I/usr/lib/x86_64-linux-gnu/pangomm-1.4/include -I/usr/include/gtk-3.0 -I/usr/include/cairomm-1.0 -I/usr/lib/x86_64-linux-gnu/cairomm-1.0/include -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/gtk-3.0/unix-print -I/usr/include/gdkmm-3.0 -I/usr/lib/x86_64-linux-gnu/gdkmm-3.0/include -I/usr/include/atk-1.0 -I/usr/include/glibmm-2.4 -I/usr/lib/x86_64-linux-gnu/glibmm-2.4/include -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/sigc++-2.0 -I/usr/lib/x86_64-linux-gnu/sigc++-2.0/include -I/usr/include/pango-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/harfbuzz
GTKLFLAGS=-lgtkmm-3.0 -latkmm-1.6 -lgdkmm-3.0 -lgiomm-2.4 -lpangomm-1.4 -lgtk-3 -lglibmm-2.4 -lcairomm-1.0 -lgdk-3 -latk-1.0 -lgio-2.0 -lpangocairo-1.0 -lgdk_pixbuf-2.0 -lcairo-gobject -lpango-1.0 -lcairo -lsigc-2.0 -lgobject-2.0 -lglib-2.0
LFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

BNAME=MapEditor
OBJS=main.o mainWindow.o canvas.o leftPane.o rightPane.o baseToolbar.o toolbarMenu.o

all: $(BNAME)

run: $(BNAME)
	@./$(BNAME)

$(BNAME): objects
	@echo "Building executable $(BNAME)..."
	@$(CXX) $(ADDED_CXXFLAGS) $(CXXFLAGS) -o $(BNAME) $(OBJS) $(LFLAGS) $(GTKLFLAGS)

objects: $(OBJS)

%.o: %.cpp
	@echo "Building $@..."
	@$(CXX) $(GTKCFLAGS) $(ADDED_CXXFLAGS)  $(CXXFLAGS) -c -o $@ $^

clean:
	@rm *o $(BNAME)

