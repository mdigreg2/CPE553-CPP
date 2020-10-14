// Author: Brian and Avro
// Ellipse Design

#pragma once
#include "Shape.hh"

class Ellipse : public Shape {
private:
  float x, y, major, minor, startAngle, stopAngle;
  uint32_t color;
public:
  Ellipse(float x, float y, float major, float minor, uint32_t color) : 
    x(x), y(y), major(major), minor(minor), startAngle(0), stopAngle(360), color(color) {}

  void internalDraw(std::ostream& s) const{
    drawColor(s, color);
    s << x << ' ' << y << ' ' << major << ' ' << minor << ' ' << startAngle << ' ' << stopAngle << ' ' << "arc";
  }

  void draw(std::ostream& s) const override {
    internalDraw(s); 
    s << " stroke\n";
  }
};
