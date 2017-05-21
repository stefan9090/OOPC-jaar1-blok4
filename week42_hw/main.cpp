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
   
   auto led1 = hwlib::target::pin_out(1, 25);//pin 2 on arduino
   auto led2 = hwlib::target::pin_out(2, 28);//pin 3 on arduino
   auto led3 = hwlib::target::pin_out(2, 26);//pin 4 on arduino
   auto led4 = hwlib::target::pin_out(2, 25);//pin 5 on arduino
   
   auto button_more = hwlib::target::pin_in(2, 24);//pin 6 on arduino
   auto button_less = hwlib::target::pin_in(2, 23);//pin 7 on arduino
   
   hwlib::target::pin_out all_leds[] = {led1, led2, led3, led4};
   int led_index = 0;
   
   while(true){
       int state = handle_led(all_leds[led_index], button_more, button_less);
       if(state==-1){
           led_index--;
       }else if(state){
           led_index++;
       }
       
       if(led_index<0){
           led_index = 0;
       }else if(led_index>3){
           led_index = 3;
       }
       hwlib::wait_ms(200);
   }
}
