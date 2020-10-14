#pragma once
#include "Hexagon.hh"

class FillHexagon : public Hexagon {
    public:
        FillHexagon(float x1, float y1, float x2, float y2, float x3, float y3, float x4,
            float y4, float x5, float y5, float x6, float y6, uint32_t color)
        : Hexagon(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, color) {}

        void draw(std::ostream& s) const override {
            Hexagon::internalDraw(s);
            s << " fill\n";
        }
};