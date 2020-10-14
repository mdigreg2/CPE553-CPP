#pragma once
#include "Octogon.hh"

class FillOctogon : public Octogon {
 public:
  FillOctogon(float x1, float y1, float x2, float y2, float x3, float y3,
              float x4, float y4, float x5, float y5, float x6, float y6,
              float x7, float y7, float x8, float y8, uint32_t color)
      : Octogon(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8,
                color) {}

  void draw(std::ostream& s) const override {
    Octogon::internalDraw(s);
    s << " fill\n";
  }
};