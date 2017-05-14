#ifndef FILLED_RECTANGLE_HPP
#define FILLED_RECTANGLE_HPP

#include "rectangle.hpp"
#include "drawable.hpp"
#include "window.hpp"
#include "vector.hpp"

class filled_rectangle : public drawable
{
private:
    vector rec_loc;
    vector rec_size;
public:
    filled_rectangle( window & w, const vector & start, const vector & end );
    void draw() override;
};

#endif // FILLED_RECTANGLE_HPP
