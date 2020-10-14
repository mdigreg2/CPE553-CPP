#pragma once
#include <iostream>

class Shape {
public:
  void drawColor(std::ostream& s, uint32_t color) const {
		s << color / 65536 << ' ' << color / 256 % 256 << ' ' << color % 256 <<
			" setrgbcolor\n";
		//		s << (color >> 16) << ' ' << ((color >> 8) & 0xFF) << ' ' << (color & 0xFF);
		
	}
	virtual void draw(std::ostream& s) const = 0;
	//	virtual ~Shape() = 0;
};
