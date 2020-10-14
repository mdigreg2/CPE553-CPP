#pragma once
#include "Sector.hh"

class FillSector :public Sector {
	FillSector(float x, float y, float rad, float start, float end, unit32_t color) :
		Sector(x, y, rad, start, end, color){}

	void draw(std::ostream& s)const override {
		Sector::internalDraw(s);
		s << " fill\n";
	}
};