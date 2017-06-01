#ifndef COMPOSITE_CLASS_HPP
#define COMPOSITE_CLASS_HPP

#include "filled_rectangle.hpp"
#include "circle.hpp"
#include "line.hpp"
#include "window.hpp"

#define CAR_LENGTH 200
#define WHEEL_SIZE 20
#define REC_HEIGHT 10

#define WINDOW_START 20
#define WINDOW_WIDTH 10


class composite_class
{
private:
    line line1, line2;
    circle wheel1, wheel2;
    filled_rectangle rec1, rec2;
public:
    composite_class(window & w, int pos_x, int pos_y, int length);
    void print();
};

#endif // COMPOSITE_CLASS_HPP
