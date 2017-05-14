#include "filled_rectangle.hpp"
#include <iostream>

filled_rectangle::filled_rectangle( window & w, const vector & start, const vector & end ):
    drawable(w, start, end),
    rec_loc(start),
    rec_size(end)
{}

void filled_rectangle::draw(){
    vector buf_loc = rec_loc;
    vector buf_size = rec_size;
    if(rec_size.x>=rec_size.y){
        for(int i = 0;i<rec_size.y/2+1;i++){
            rectangle buf_rec(w, buf_loc, buf_size+rec_loc);
            buf_rec.draw();
            buf_size.y--;
            buf_loc.y++;
        }
    }else{
        for(int i = 0;i<rec_size.x/2+1;i++){
            rectangle buf_rec(w, buf_loc, buf_size+rec_loc);
            buf_rec.draw();
            buf_size.x--;
            buf_loc.x++;
        }        
    }
}


