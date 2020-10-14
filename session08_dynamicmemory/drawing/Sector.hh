#pragma once
#include "Shape.hh"

class Sector :public Shape {
private:
	float x, y, start, end, rad;
	unit32_t  color;
public:
	Sector(float x, float y, float rad, float start, float end, unit32_t color) :
		x(x), y(y), rad(rad), start(start),end(end), color(color){}

	void internalDraw(std::ostream& s) const {
		drawColor(s, color);
		s << x << ' ' << y << ' ' << rad << ' ' << start << ' ' << end << " arc";
	}

	void draw(std::ostream& s) const override{
		internalDraw(s);
		s << "stroke\n";
	}
};