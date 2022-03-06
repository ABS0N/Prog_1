#ifndef GRAPH_GUARD
#define GRAPH_GUARD

#include "Point.h"
#include <vector>
#include "fltk.h"
#include "std_lib_facilities.h"

namespace Graph_lib {

#undef major
#undef minor

struct Color {
	enum Color_type {
		red=FL_RED, blue=FL_BLUE,
	}
};

class Shape {
public:
	void draw() const;}
}

Polygon opl = {
	Point{100,100}, Point{150,200}, {300,200}, {250,250}
};

win.attach(opl);

win.wait_for_button();

return 0;
};
