#include "./GUI/Graph.h"
#include "./GUI/Simple_window.h"
#include "./GUI/Window.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main ()
{
try
{

Point t1{100,100};
Simple_Window win{t1, 600, 600, "Function graphs"};
win.wait_for_button();

Axis xa{Axis::x, Point {300,500},400,20,"1 = = 20 pixels"};

Axis ya{Axis::y, Point{100,300},400,20, "1 = = 20 pixels"};

xa.set_color(Color::red);
ya.set_color(Color::red);
win.attach(xa);
win.attach(ya);

double one   (double x){return 1;}

constexpr int minrange = -10; constexpr int maxrange = 11;
constexpr int xscale = 20; constexpr int yscale = 20;
constexpr int points = 400;

Function onefunct{one, minrange, maxrange, Point{300,300}, points, xscale, yscale};
win.attach(onefunct);

double slope (double x){return x/2;}

Function slopefunct{slope, minrange, maxrange, Point{300,300}, points, xscale, yscale};
Text label{Point{100,385}, "x/2"};
win.attach(slopefunct);
win.attach(label);

double square(double x){return x*x;}
Function squarefunct{square, minrange, maxrange, Point{300,300}, points, xscale, yscale};
win.attach(squarefunct);

Function cosinus{cos, r_min, r_max, Origo, pts, xscale, yscale}; cosinus.set_color(Color::blue);
win.attach(cosinus);

double sloping_cos(double x){return cos(x)+slope(x);}
Function sloping_cosinus{sloping_cos, minrange, maxrange, Point{300,300}, points, xscale, yscale};
win.attach(sloping_cosinus);

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