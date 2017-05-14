// template

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "filled_rectangle.hpp"
#include "composite_class.hpp"

int main(int argc, char **argv){
   window w( 600, 300, 2 );
   
   composite_class thing(w, 200, 150, 200);
   thing.print();
   
   return 0;
}
