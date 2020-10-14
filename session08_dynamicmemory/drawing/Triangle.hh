#pragma once
#include "Shape.hh"

class Triangle : public Shape {
private:
	float x1, y1, x2, y2, x3, y3;
	uint32_t color;
public:
	Triangle(float x1, float y1, float x2, float y2, float x3, float y3, uint32_t color) :
		x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), color(color) {}

	void internalDraw(std::ostream& s) const {
		drawColor(s, color);
		s << x1 << ' ' << y1 << " moveto " <<
			x2 << ' ' << y2 << " lineto " <<
			x3 << ' ' << y3 << " lineto closepath stroke\n";
	}

	void draw(std::ostream& s) const override{
		internalDraw(s);
		s << " stroke\n";
	}

};
