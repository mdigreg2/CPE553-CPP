
//Author Rituraj Gaikawad @bleaksunshine

#pragma once 
#include "Trapezoid.hh" 
class FillTrapezoid : public Trapezoid {
public:
  FillTrape(float x1, float y1, float x_len, float small_line, float hgt,  uint64_t color) : 
    Trapezoid(x1, y1, x_len, small_line, hgt, color) {}

  void draw(std::ostream& s) const override {
    Trapezoid::internalDraw(s);
    s << " fill\n";
  }
}; 