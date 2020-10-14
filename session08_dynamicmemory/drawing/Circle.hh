#pragma once
#include <iostream>

class Circle : public Shape {
private:
    float x, y, startAngle, stopAngle, radius;
    uint32_t color;

public:
    Circle(float x, float y, float radius, uint32_t color) : 
        x(x), y(y), radius(radius), startAngle(0), stopAngle(360), color(color) {}

    Circle(float x, float y, float radius, float startAngle, float stopAngle, uint32_t color) : 
        x(x), y(y), radius(radius), startAngle(startAngle), stopAngle(stopAngle), color(color) {}

    void internalDraw(std::ostream& s) const {
        drawColor(s, color);
        s << x << ' ' << y << ' ' << startAngle << ' ' <<
            stopAngle << " arc";
    }

    void draw(std::ostream& s) const override{
        internalDraw(s);
        s <<  " fill\n"
    }
};