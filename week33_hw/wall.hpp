#ifndef WALL_HPP
#define WALL_HPP

#include "rectangle.hpp"
#include "filled_rectangle.hpp"

class wall : public drawable
{
private:
    bool filled;
    int update_interval;
    int update_count;
    rectangle rec;
    filled_rectangle filled_rec;
public:
    wall(window & w, const vector & location, const vector & end, int update_interval, const vector & bounce);
    void draw();
};

#endif // WALL_HPP
