#pragma once
#include "Rhombus.hh"
#include <cmath>

class FillRhombus : public Rhombus {
    public:
        FillRhombus(float x1, float y1, float zeta, float l, uint32_t color) 
        : Rhombus(x1, y1, zeta, l, color) {}

        void draw(std::ostream& s) const override {
            Rhombus::internalDraw(s);
            s << " fill\n";
        }
};
