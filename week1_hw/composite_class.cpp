#include "composite_class.hpp"

composite_class::composite_class(window & w, int pos_x, int pos_y, int length):
    line1(w, pos_x+WINDOW_WIDTH, pos_y-REC_HEIGHT-WHEEL_SIZE, pos_x+WINDOW_START, pos_y-REC_HEIGHT*2-WHEEL_SIZE),
    line2(w, pos_x+40, pos_y-WHEEL_SIZE-REC_HEIGHT*2, pos_x+100, pos_y-WHEEL_SIZE),
    wheel1(w, pos_x+WHEEL_SIZE, pos_y, WHEEL_SIZE),
    wheel2(w, pos_x+length-WHEEL_SIZE, pos_y, WHEEL_SIZE),
    rec1(w, pos_x, pos_y-WHEEL_SIZE-REC_HEIGHT, pos_x+length, pos_y-WHEEL_SIZE),
    rec2(w, pos_x+WINDOW_START, pos_y-WHEEL_SIZE*2, pos_x+40, pos_y-WHEEL_SIZE-REC_HEIGHT)
{
    
}


void composite_class::print(){
    line1.print();
    line2.print();
    wheel1.print();
    wheel2.print();
    rec1.print();
    rec2.print();
}


