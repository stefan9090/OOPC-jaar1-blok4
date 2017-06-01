#include "hwlib.hpp"

class pin_out_invert : public hwlib::pin_out{
private:
    hwlib::pin_out & slave;
public:
    pin_out_invert(hwlib::pin_out & slave):
        slave(slave)
    {}
    void set(bool x, hwlib::buffering buf = hwlib::buffering::unbuffered)override{
        slave.set(!x);
    }
};

class pin_out_all : public hwlib::pin_out {
private:
   hwlib::pin_out * list[ 8 ];     
   
public:

   pin_out_all( 
      hwlib::pin_out & p0, 
      hwlib::pin_out & p1 = hwlib::pin_out_dummy,  
      hwlib::pin_out & p2 = hwlib::pin_out_dummy, 
      hwlib::pin_out & p3 = hwlib::pin_out_dummy,
      hwlib::pin_out & p4 = hwlib::pin_out_dummy,  
      hwlib::pin_out & p5 = hwlib::pin_out_dummy, 
      hwlib::pin_out & p6 = hwlib::pin_out_dummy, 
      hwlib::pin_out & p7 = hwlib::pin_out_dummy  
   ):
      list{ &p0, &p1, &p2, &p3, &p4, &p5, &p6, &p7 }
   {}
   
   void set( 
      bool v, 
      hwlib::buffering buf = hwlib::buffering::unbuffered  
   ){
      for( auto p  : list ){
          p->set( v );
      }
   }
};

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;

   auto led1 = hwlib::target::pin_out(hwlib::target::pins::d2);
   auto led2 = hwlib::target::pin_out(hwlib::target::pins::d3);
   auto led3 = hwlib::target::pin_out(hwlib::target::pins::d4);
   auto led4 = hwlib::target::pin_out(hwlib::target::pins::d5);
   auto led5 = hwlib::target::pin_out(hwlib::target::pins::d6);
   auto led6 = hwlib::target::pin_out(hwlib::target::pins::d7);
   auto led7 = hwlib::target::pin_out(hwlib::target::pins::d8);
   auto led8 = hwlib::target::pin_out(hwlib::target::pins::d9);
   pin_out_invert led1_inv(led1);
   pin_out_invert led2_inv(led2); 
   pin_out_invert led3_inv(led3);
   pin_out_invert led4_inv(led4);
   pin_out_invert led5_inv(led5);
   pin_out_invert led6_inv(led6);
   pin_out_invert led7_inv(led7);
   pin_out_invert led8_inv(led8);
   
   pin_out_all leds_1( 
      led1_inv, 
      led2_inv, 
      led3_inv,
      led4_inv
   );
   
   pin_out_all leds_2( 
      led5_inv,
      led6_inv,
      led7_inv,
      led8_inv
   );
    
   hwlib::port_out_from_pins leds(
      leds_1,
      leds_2
   );
   
    while(true){
        hwlib::kitt(leds);
    }
}
