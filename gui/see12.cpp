#include "Window.h"
#include "Graph.h"
#include "Point.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"

int main (){
	using namespace Graph_lib;
	
	Point tl(100, 100);
	
	Simple_window win = {tl, 600, 400, "My window"};
	
	Axis xa {Axis::x, Point (20,300), 280, 10, "x axis"};
	win.attach(xa);
	win.set_label("My window #2?");
	
	win.wait_for_button();
	
	Axis ya {Axis::y, Point(20, 300), 280, 10, "y axis"};
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);
	win.set_label("My window #3?");
	
	win.wait_for_button();
	
	Function sine{sin,0,100,Point{20, 150}, 1000, 50, 50};
	win.attach(sine);
	win.label("My Window Comedy was Wrong, as I Expected");
	win.wait_for_button();
	
	sine.set_color(Color::blue);
	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.label("That time I got windowed as a window");
	win.wait_for_button();
	
	Rectangle r(Point{200, 200}, 100, 50);
	win.attach(r);
	win.set_label("Windowju kaisen");
	win.wait_for_button();
}
