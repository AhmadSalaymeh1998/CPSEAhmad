#include "hwlib.hpp"
#include "calculation.h"
#include "clock.h"
#include "time.h"


int main( void ){	
	constexpr auto sinusses = lookup<60,int>(scaled_sine_from_degrees);
	constexpr auto cosinusses = lookup<60,int>(scaled_cosine_from_degrees);

	namespace target = hwlib::target;
	auto scl = target::pin_oc( target::pins::scl );
	auto sda = target::pin_oc( target::pins::sda );   
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
   
	auto w = hwlib::glcd_oled( i2c_bus, 0x3c );  
	
	auto hoursbutton  = target::pin_in( target::pins::d10 );
	auto minutesbutton= target::pin_in( target::pins::d9 );
	
	time tijd;
	clock c(hwlib::xy(64,32),tijd);
	w.clear();
	for(;;){
		tijd.update();
		if(hoursbutton.read()){
			tijd.set_hours();
		}
		if(minutesbutton.read()){
			tijd.set_minutes();
		}
		c.draw(sinusses, cosinusses, w);
//    hwlib::cout << "\r hours: " << tijd.get_hours() << "  minutes: " << tijd.get_minutes() << "  seconds: " << tijd.get_seconds() <<"           ";
 		hwlib::wait_ms(100);
		w.clear();
	}
}