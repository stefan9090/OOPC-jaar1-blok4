#include "hwlib.hpp"

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   auto led1 = hwlib::target::pin_in_out(1, 25);//pin 2 op arduino
   auto led2 = hwlib::target::pin_in_out(2, 28);//pin 3 op arduino
   auto led3 = hwlib::target::pin_in_out(2, 26);//pin 4 op arduino
   auto led4 = hwlib::target::pin_in_out(2, 25);//pin 5 op arduino
   
   led1.direction_set_output();
   led2.direction_set_output();
   led3.direction_set_output();
   led4.direction_set_output();
   
   while(true){
       led1.set(1);
       led2.set(1);
       led3.set(0);
       led4.set(0);
       hwlib::wait_ms(500);
       
       led1.set(0);
       led2.set(1);
       led3.set(1);
       led4.set(0);
       hwlib::wait_ms(500);
       
       led1.set(0);
       led2.set(0);
       led3.set(1);
       led4.set(1);
       hwlib::wait_ms(500);
       
       led1.set(0);
       led2.set(1);
       led3.set(1);
       led4.set(0);
       hwlib::wait_ms(500);
   }
}
