#pragma once
#include "Decagon.hh"

class FillDecagon : public Decagon {
public:
    FillDecagon(float x1, float y1, float x2, float y2, float x3, float y3, float x4,
                float y4, float x5, float y5, float x6, float y6, float x7, float y7,
                float x8, float y8, float x9, float y9, float x10, float y10, uint32_t color)
            : Decagon(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, color) {}

    void draw(std::ostream& s) const override {
        Decagon::internalDraw(s);
        s << " fill\n";
    }
};
