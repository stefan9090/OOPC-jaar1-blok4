#ifndef FILLED_RECTANGLE_HPP
#define FILLED_RECTANGLE_HPP

#include "rectangle.hpp"
#include "window.hpp"

class filled_rectangle
{
private:
    window & w;
    int start_x, start_y, end_x, end_y;
public:
    filled_rectangle( window & w, int start_x, int start_y, int end_x, int end_y );
    void print();
};

#endif // FILLED_RECTANGLE_HPP
