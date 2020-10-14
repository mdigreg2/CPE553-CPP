// Author Krishna
// Trapezoid design

#pragma once
#include "Shape.hh"

class Trapezoid : public Shape {
private:
	float x1, y1, base_x_len, small_line, height;
	uint64_t color;
public:
	Trapezoid(float x1, float y1, float x_len, float small_line, float hgt, uint64_t color): 
	x1(x1), y1(y1), base_x_len(x_len), small_line(small_line), height(hgt), color(color) {}

	void internalDraw(std::ostream& s) const {
		drawColor(s, color);
		s << x1 << ' ' << y1 << " moveto " <<
			 
			x1 + base_x_len  << ' ' << y1 << " lineto " <<
			
			x1 + base_x_len - ((base_x_len - small_line)/ 2.0) << ' ' << y1 + height << " lineto " <<
			
			x1 + ((base_x_len - small_line)/ 2.0) << ' ' << y1 + height << " lineto closepath";
	}

	void draw(std::ostream& s) const override {
		internalDraw(s);
		s << " stroke\n";
	}
}