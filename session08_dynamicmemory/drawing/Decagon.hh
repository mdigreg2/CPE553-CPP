#pragma once
#include "Shape.hh"

class Decagon : public Shape {
private:
    float x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8, x9, y9, x10, y10;
    uint32_t color;

public:
    Decagon(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float x5, float y5, float x6, float y6, float x7, float y7, float x8, float y8, float x9, float y9, float x10, float y10, uint32_t color)
            : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4), x5(x5), y5(y5), x6(x6), y6(y6), x7(x7), y7(y7), x8(x8), y8(y8), x9(x9), y9(y9), x10(x10), y10(y10), color(color) {}

    void internalDraw(std::ostream& s) const {
        drawColor(s, color);
        s << x1 << ' ' << y1 << " moveto " << x2 << ' ' << y2 << " lineto "
          << x3 << ' ' << y3 << " moveto " << x4 << ' ' << y4 << " lineto "
          << x5 << ' ' << y5 << " moveto " << x6 << ' ' << y6 << " lineto "
          << x7 << ' ' << y7 << " moveto " << x8 << ' ' << y8 << " lineto "
          << x9 << ' ' << y9 << " moveto " << x10 << ' ' << y10 << " lineto "
          << " lineto closepath stroke \n";
    }

    void draw(std::ostream& s) const override {
        internalDraw(s);
        s << " stroke\n";
    }


};
