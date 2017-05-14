#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "wall.hpp"
#include "filled_rectangle.hpp"

#define window_width 128
#define window_height 64
#define wall_size 3

int main(){
   window w( vector( window_width, window_height ), 2 );
   ball b( w, vector( 50, 20 ), 9, vector( 5, 2 ) );
   
   wall wall_left(w, vector(0, 0), vector(3, window_height), 2, vector(-1, 1));
   wall wall_up(w, vector(0, 0), vector(window_width, wall_size), 2, vector(1, -1));
   wall wall_right(w, vector(window_width-wall_size, 0), vector(window_width, window_height), 2, vector(-1, 1));
   wall wall_down(w, vector(0, window_height-wall_size), vector(window_width, window_height), 2, vector(1, -1));
   
   drawable * objects[] = { &b, &wall_left, &wall_up, &wall_right, &wall_down};

   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
      wait_ms( 200 );
      for( auto & p : objects ){
          p->update();
      }
      for( auto & p : objects ){
         for( auto & other : objects ){
            p->interact( *other );
         } 
      }
   }
}

