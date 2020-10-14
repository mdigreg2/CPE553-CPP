
#pragma once
#include "Shape.hh"
#include <cmath>

class Rhombus : public Shape
{
private:
    float x1, y1, x2, y2, x3, y3,x4,y4;
    float zeta;
    float l;
    uint32_t color;

public:
    Rhombus(float x1, float y1, float zeta, float l, uint32_t color) : 
    x1(x1), y1(y1), zeta(zeta), l(l), color(color){
        x2=x1+l;
        y2=y2;
        x3=x2+cos(zeta);
        y3=y2+sin(zeta);
        x4=x3-l;
        y4=y3;
    }

    void internalDraw(std::ostream &s) const
    {
        drawColor(s, color);
        s << x1 << ' ' << y1 << " moveto " 
        << x2 << ' ' << y2 << " lineto " 
        << x3 << ' ' << y3 << " lineto " 
        << x4 << ' ' << y4 <<" lineto closepath stroke\n";
    }

    void draw(std::ostream &s) const override
    {
        internalDraw(s);
        s << " stroke\n";
    }
};