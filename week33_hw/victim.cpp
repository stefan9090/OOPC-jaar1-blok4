#include "victim.hpp"
#include <iostream>

victim::victim(window & w, const vector & location, const vector & size):
    rectangle(w, location, size),
    hit(false)
{}

void victim::draw(){
    if(hit){
        std::cout<<size<<' '<<location<<std::endl;
        if(size.x+location.x > location.x){
            size -= vector(2, 0); 
            location += vector(1, 0);
        }
        if( size.y+location.y > location.y){
            size -= vector(0, 2); 
            location += vector(0, 1);
        }
    }
    rectangle rec(w, location, size+location);
    rec.draw();
}

void victim::interact( drawable & other ){
   if( this != & other){
      if( overlaps( other )){
         hit = true;
      }
   }
}

