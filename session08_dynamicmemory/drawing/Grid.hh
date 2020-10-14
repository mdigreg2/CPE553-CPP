#pragma once
#include "Shape.hh"

//define class grid
class Grid : public Shape {

    private:
        float x,x1, y,y1, w, h;
        uint32_t color;

    public:
        //Parameters in constructor
        //Start X, Start Y, End X, End Y, Width of grid, Height of grid, Color
        //class constructor
        Grid(float x, float y, float x1, float y1, float w, float h, uint32_t color):
                    x(x), y(y), x1(x1), y1(y1), w(w), h(h), color(color) {}

        //overide the shape draw function for grid
        void draw(std::ostream& s) const override {
            drawColor(s, color);

            //figure out the dimensions of each cell
            float cellX = w;    //Kept variable names, W is width of a grid
            float cellY = h;    //Kept variable names, H is height of a grid

            //draw a grid of boxes with no filling
            for(float i = x; i < x1; i+=w){   //Loop from Start X to End X with width(w) of grid
                for(float j = y; j < y1; j+=h){   //Loop from Start Y to End Y with height(h) of grid
                    
                    //get the x and y for the top left corner
                    float x_ = i;   //Start Corner
                    float y_ = j;   //Start Corner

                    //draw a single cell
                    s << x_ << ' ' << y_ << " moveto " <<   //Start Corner
                    x_ + cellX << ' ' << y_ << " lineto " <<    //Move Along X axis
                    x_ + cellX << ' ' << y_ + cellY << " lineto " <<    //Move along Y axis
                    x_ << ' ' << y_ + cellY << " lineto closepath stroke\n";    //Move along X axis, close path on Y axis

                }
            }  
        }

};


