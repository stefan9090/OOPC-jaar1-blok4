#include "hwlib.hpp"

void draw_square(hwlib::window & test, const hwlib::location start, const hwlib::location end){
    for(unsigned int i = start.x; i < end.x ; i++ ){
       test.write( hwlib::location( i, start.y ), hwlib::black );
    }
    for(unsigned int i = start.y; i < end.y ; i++ ){
       test.write( hwlib::location( start.x, i ), hwlib::black );
    }
    
    for(unsigned int i = start.y; i < end.y ; i++ ){
       test.write( hwlib::location( end.x, i ), hwlib::black );
    }
    for(unsigned int i = start.x; i < end.x ; i++ ){
       test.write( hwlib::location( i, end.y ), hwlib::black );
    }
}

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;
   
   auto scl = target::pin_oc( target::pins::scl );
   auto sda = target::pin_oc( target::pins::sda );
   
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
   
   auto display = hwlib::glcd_oled( i2c_bus, 0x3c );  
     
   display.clear();
   draw_square(display, hwlib::location(10, 10), hwlib::location(120, 60));
   draw_square(display, hwlib::location(105, 40), hwlib::location(115, 60));
   draw_square(display, hwlib::location(105, 40), hwlib::location(115, 60));
}
