#include <iostream>
#include "Rect.hh"
#include "Triangle.hh"
//#include <square.hh>
//#include "Circle.hh"
//#include "Line.hh"
//#include "Polygon.hh"
//#include "Pentagon.hh"
//#include "Ellipse.hh"
//#include "Octogon.hh"
#include "Quad.hh"
#include "FillQuad.hh"
#include "Text.hh"
#include "FillText.hh"
#include "StrokeText.hh"
#include "Drawing.hh"
#include "Grid.hh"

using namespace std;

const uint32_t red = 0xFF0000;
const uint32_t green = 0x00FF00;
const uint32_t blue = 0x0000FF;
const uint32_t purple = 0x800080;
const uint32_t black = 0x000000;
const uint32_t yellow = 0xFFFF00;
const uint32_t gray = 0x808080;
const uint32_t darkgreen = 0x008000;
const uint32_t darkblue = 0x000080;

int main() {

	Drawing draw("draw.ps");
	for (int x = 10; x <= 510; x += 100) {
		draw.add(new Rect(x, 20, 50, 30, red));
	    draw.add(new Triangle(0, 100, 100, 199, 90, 110, green));
		//draw.add(new square(100,100,100,100, blue));
	}
	draw.add(new Text(500,100, "Mike is bad at smite", Fonts::Helvetica, black, 12, 0)); // Has contructor overloading
	draw.add(new FillText(400, 150, "C++ is cool", Fonts::Times, blue, 40, 30));
	draw.add(new StrokeText(200, 200, "The Sun is a Deadly Lazer", Fonts::Times, yellow, 40, 10));
	//   draw.add(new Circle(150,150, 50, blue));
	//   draw.add(new Line(200,100, 299,199, black));
	//   draw.add(new Polygon(350,150, 50, 5, purple));
	
	draw.add(new Grid(400,100,499,199,8, 8, gray));
	//   draw.add(new Text(500, 100, "testing", black));
	//   draw.add(new Ellipse(150,250, 100, 40, yellow));
	draw.add(new Quad(300,200, 320,290, 399,260, 250,220, black);
	draw.add(new FillQuad(420,333, 420,390, 499,360, 350,320, red);

	/* Trapezoid: lower left corner is (400,400) bottom edge is 100 long
		 top edge is 50 long (centered) and distance between the two parallel faces is 75
	   draw.add(new Trapezoid(400,200, 100, 50, 75, darkgreen));
	*/
	/*
		Rhombus: center at (550,250), width=70, height = 100
   draw.add(new Rhombus(550,250, 70, 100, darkblue));
	*/
	//draw.add(new Sector(50, 350, 50, 0, 90, red));
}
