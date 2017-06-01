#include "hwlib.hpp"

int handle_led(hwlib::target::pin_out & led, hwlib::target::pin_in & button_on, hwlib::target::pin_in & button_off){
    if(!button_on.get()){
        led.set(1);
        return 1;
    }
    if(!button_off.get()){
        led.set(0);
        return -1;
    }
    return 0;
}

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   auto ds   = hwlib::target::pin_out( hwlib::target::pins::d8 );
   auto shcp = hwlib::target::pin_out( hwlib::target::pins::d9 );
   auto stcp = hwlib::target::pin_out( hwlib::target::pins::d10 );
   auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
      stcp, ds, hwlib::pin_in_dummy 
   );
   auto hc595 = hwlib::hc595(spi, shcp);
   auto led1 = hwlib::target::pin_out(1, 25);//pin 2 on arduino
   auto led2 = hwlib::target::pin_out(2, 28);//pin 3 on arduino
   auto led3 = hwlib::target::pin_out(2, 26);//pin 4 on arduino
   auto led4 = hwlib::target::pin_out(2, 25);//pin 5 on arduino
   
   
   auto button_more = hwlib::target::pin_in(2, 24);//pin 6 on arduino
   auto button_less = hwlib::target::pin_in(2, 23);//pin 7 on arduino
   
   auto leds = hwlib::port_out_from_pins( 
      hc595.p0, 
      hc595.p1, 
      hc595.p2,
      hc595.p3,
      led1, 
      led2, 
      led3,
      led4
   );

   uint8_t state = 0;
   while(true){
       if(!button_more.get()&&state<=0xFF){
           state <<= 1;
           state |= 0x1;
       }
       if(!button_less.get()&&state>=0){
           state >>= 1;
       }
       hwlib::cout<<(int)state<<'\n';
       leds.set(state);
       hwlib::wait_ms(500);
   }
    
}
