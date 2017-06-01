#include "hwlib.hpp"



class pin_in_two_and : public hwlib::pin_in{
private:
    hwlib::target::pin_in & slave_1;
    hwlib::target::pin_in & slave_2;
public:
    pin_in_two_and(hwlib::target::pin_in & slave_1, hwlib::target::pin_in & slave_2):
        slave_1(slave_1),
        slave_2(slave_2)
    {}
    bool get(hwlib::buffering buf = hwlib::buffering::unbuffered  )override{
        return (slave_1.get() && slave_2.get());
    }
};

int main( void ){	
   // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
   
    hwlib::target::pin_out led(hwlib::target::pins::d2);
    hwlib::target::pin_in but_1(hwlib::target::pins::d6);
    hwlib::target::pin_in but_2(hwlib::target::pins::d7);
    while(true){
        led.set(pin_in_two_and(but_1, but_2).get());
    }
    
}
