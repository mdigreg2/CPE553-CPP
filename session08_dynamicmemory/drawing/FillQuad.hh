#pragma once
#include "Quad.hh"
class FillQuad : public Quad {
 public:
  FillQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4,
           float y4, UINT32_t color)
      : Quad(x1, y1, x2, y2, x3, y3, x4, y4, color) {}
  void draw(std::ostream& s) const override {
    Quad::internalDraw(s);
    s << " fill\n";
  }
};
