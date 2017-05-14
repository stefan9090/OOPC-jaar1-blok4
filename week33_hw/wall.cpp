#include "wall.hpp"
#include <iostream>

wall::wall(window & w, const vector & location, const vector & end, int update_interval, const vector & bounce):
    drawable(w, location, end, bounce),
    filled(0),
    update_interval(update_interval),
    update_count(0),
    rec(w, location, end+location),
    filled_rec(w, location, end)
{}

void wall::draw(){
    if(filled){
        filled_rec.draw();
    }else{
        rec.draw();
    }
    if(++update_count == update_interval){
        filled = !filled;
        update_count = 0;
    }     
}


