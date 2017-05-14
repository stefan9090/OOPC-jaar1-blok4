#include "filled_rectangle.hpp"
#include <iostream>

filled_rectangle::filled_rectangle( window & w, int start_x, int start_y, int end_x, int end_y ):
    w(w),
    start_x(start_x),
    start_y(start_y),
    end_x(end_x),
    end_y(end_y)
{}

void filled_rectangle::print(){
    int len_x = (end_x - start_x)/2+1;
    int len_y = end_y - end_x;
    
    for(int x = 0;x<len_x;x++){
        rectangle buf(w, start_x+x, start_y, end_x-x, end_y);
        buf.print();
    }
}


