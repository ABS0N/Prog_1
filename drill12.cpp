
#include "Graph.h"
#include "Simple_window.h"

#include <string>
#include <iostream>

using namespace Graph_lib;


int main ()
{
	try 
	{
	Point t1 {100, 100};
	Simple_window win {t1, 600, 400, "My Window"};
	win.wait_for_button();
	

	Axis xa{Axis::x, Point{20,300}, 280, 10, "x axis"};
	win.attach(xa);
	
	
	Axis ya{Axis::y, Point{20,300}, 280, 10, "y axis"};
	win.attach(ya)
	
	win.set_label("Axis");
	win.wait_for_button();
	
	Function sine {sin,0,100,Point{20,150},1000,50,50};
	sine.set_color(Color::magenta);
	win.attach(sine);
	win.set_label("Function");
	win.wait_for_button();

	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	poly.set_color(Color::dark_magenta);
	poly.set_fill_color(Color::dark_cyan)
	poly.set_style(Line_style::dot);
	win.attach(poly);
	win.set_label("Polygon");
	win.wait_for_button();

	Rectangle r {Point{200,200},100,50};
	r.set_color(Color::dark_green);
	r.set_fill_color(Color::green);
	win.attach(r);
	win.set_label("Rectangle");
	win.wait_for_button();

	Text t {Point{150,150}"Sasdasdadasdadasdasd"};
	win.attach(t);
	t.set_font(Font::courier_italic);
	t.set_font_size(40);
	win.set_label("Tupturuptuptup");
	win.wait_for_button();

	//12.7.9 Images
	Image ii {Point{100,50},"smile.jpg"};
	win.attach(ii);
	win.set_label("Supsup");
	win.wait_for_button();

	//12.7.10 More
	Circle c {Point{100,200},50};
	Ellipse e {Point{100,200},75,25};
	e.set_color(Color::dark_red);
	Mark m {Point{100,200},'supdub'};
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.set_label("More");
	win.wait_for_button();

	}
}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
    }
catch (...) {
	cerr << "error\n";
	return 1;
	}