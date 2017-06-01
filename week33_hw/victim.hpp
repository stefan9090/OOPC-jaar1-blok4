#ifndef VICTIM_HPP
#define VICTIM_HPP

#include "vector.hpp"
#include "rectangle.hpp"
#include "window.hpp"
#include "drawable.hpp"

class victim : public rectangle
{
private:
    bool hit;
public:
    victim(window & w, const vector & location, const vector & size);
    void draw();
    void interact( drawable & other ) override;
};

#endif // VICTIM_HPP
