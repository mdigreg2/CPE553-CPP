#pragma once
#include "Triangle.hh"

class FillTriangle : public Triangle {
public:
  FillTriangle(float x1, float y1, float x2, float y2, float x3, float y3, uint32_t color) : 
    Triangle(x1, y1, x2, y2, x3, y3, color) {}

  void draw(std::ostream& s) const override {
    Triangle::internalDraw(s);
    s << " fill\n";
  }
}; 