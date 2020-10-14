/*
  You have to write:
  1. Constructor (that allocates dynamic memory)
  2. Destructor (free the memory delete [])
  3. Copy Constructor
  4. Operator = (use either old way or copy and swap)
  5. Move Constructor
  6. write image: see https://github.com/memononen/nanosvg/blob/master/example/example2.c
 */
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
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
// #include "FillQuad.hh"
#include "Text.hh"
#include "FillText.hh"
#include "StrokeText.hh"
#include "Drawing.hh"
#include "Grid.hh"

using namespace std;

class DynamicBitmap {
private:
	uint32_t color;
	uint32_t* p;
	uint32_t w, h;
// your class goes here!

public:
	// do 1D size w*h so that it is faster, array[i][j] = i*h+j
	DynamicBitmap(uint32_t w, uint32_t h, const uint32_t color): w(w), h(h), color(color), p(new uint32_t[w*h]) {}
	~DynamicBitmap() {
		delete [] p;
	}

	DynamicBitmap(DynamicBitmap &d): w(d.w), h(d.h), p(new uint32_t[d.w*d.h]) {
		// for(int i = 0; i < h; i++) {
		// 	for (int j = 0; j < w; j ++) {
		// 		(*this)(i, j) = d(i, j);
		// 	}
		// }
		memcpy(p, d.p, w*h*sizeof(uint32_t));
	}

	DynamicBitmap& operator =(DynamicBitmap &orig) {
		if (this != &orig) {
			delete [] p;
			w = orig.w;
			h = orig.h;
			p = new uint32_t[w*h];
			memcpy(p, orig.p, w*h*sizeof(uint32_t));
		}

		return *this;
	}

	uint32_t operator ()(int y, int x) const {
    return p[y * w + x];
	}

	uint32_t& operator ()(int y, int x) {
    return p[y * w + x];
	}
	void line(int x1, int y1, uint32_t color) {
		int x = x1, y = y1;

				// set(x,y, RED);
		(*this) (x,y) = color;
	}
};


int main() {
	// FIRST PART (ADD COLORS HERE)
	constexpr uint32_t BLACK = 0xFF000000; // black opaque
	constexpr uint32_t RED = 0xFFFF0000; // red opaque
	const uint32_t red = 0xFF0000;
	const uint32_t green = 0x00FF00;
	const uint32_t blue = 0x0000FF;
	const uint32_t purple = 0x800080;
	const uint32_t black = 0x000000;
	const uint32_t yellow = 0xFFFF00;
	const uint32_t gray = 0x808080;
	const uint32_t darkgreen = 0x008000;
	const uint32_t darkblue = 0x000080;

	Drawing draw("draw.ps");
	for (int x = 10; x <= 510; x += 100) {
		// draw.add(new Rect(x, 20, 50, 30, red));
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
	draw.add(new Quad(300,200, 320,290, 399,260, 250,220, black));
	// draw.add(new FillQuad(420,333, 420,390, 499,360, 350,320, red);

	// SECOND PART (DO NOT EDIT)
	int xcenter = 100;
	int ycenter = 100;
	int xdiameter = 200;
	int ydiameter = 100;

	DynamicBitmap b(1024, 1024, BLACK); // Potentially dynamic size (Now: 1024 x 1024 pixels)
	b(32,32) = RED;
	cout << b(32,32) << endl;
	DynamicBitmap a = b;
	cout << a(32, 32) << endl;
	DynamicBitmap c(2048, 2048, green);
	cout << c(32, 32) << endl;
	c = a;
	cout << c(32, 32) << endl;
	// b.horizLine(0, 500, 200, RED); // Red horizontal line, from x=0 to x=500, at y = 200
	// b.vertLine(0, 399, 300, RED); // Red vertical line, from y=0 to y=399, at x = 300
	
	// b.drawRect(200,200, 100,50, BLUE); // Blue rectangle, TOP-LEFT at x=200, y=200. width=100, height=50
	// b.fillRect(201,201, 98,48, WHITE); // White rectangle, same rules as above, but filled with color
	
	// b.line(400,0, 550,300, YELLOW); // Line drawn using https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
	
	// b.ellipse(xcenter, ycenter, xdiameter, ydiameter, GREEN); //Ellipse using specs from above
	
	// b.save("bitmap2.png");
	
}

