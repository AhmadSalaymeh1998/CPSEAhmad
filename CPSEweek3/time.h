#ifndef TIME_H
#define TIME_H

#include "hwlib.hpp"
class time{
private:
	int seconds, minutes, hours, secondsplus=0, minutesplus=0, hoursplus=0;
public:
	time(){};
	int get_seconds(){return seconds;}
	int get_minutes(){return minutes;}
	int get_hours(){return hours;}
	void set_minutes(){minutesplus++;}
	void set_hours(){hoursplus++;}
	void update(){ 
		unsigned int hwlib_time= hwlib::now_us();
		unsigned int time_in_s= hwlib_time/ 1000000;
		seconds = time_in_s % 60;
		minutes = (minutesplus + (time_in_s / 60)) % 60;
		hours   = (hoursplus + ((time_in_s +(minutesplus *60))/3600)) %12;
	}
};





#endif