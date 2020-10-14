// Author: Brian and Avro
// Ellipse Fill

#pragma once
#include "Ellipse.hh"

class FillEllipse : public Ellipse {
public:
  FillEllipse(float x, float y, float major, float minor, uint32_t color) : 
    Ellipse(x, y, major, minor, color) {}

  void draw(std::ostream& s) const override {
    Ellipse::internalDraw(s);
    s << " fill\n";
  }
};
