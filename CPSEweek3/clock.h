#ifndef CLOCK_H
#define CLOCK_H

#include "hwlib.hpp"
#include "calculation.h"
#include "time.h"

class clock{
private:
	hwlib::xy midpoint;
	time & tijd;
public:
	clock(const hwlib::xy midpoint,time & tijd):
	midpoint(midpoint), tijd(tijd)
	{}
	
	void draw(const auto & sinusses,const auto & cosinusses, auto & display){
		for(int i=0; i<360; i+=30){
			hwlib::circle(hwlib::xy(sinusses.get(i),cosinusses.get(i)),1).draw(display);
		}
		hwlib::line(midpoint,hwlib::xy(sinusses.get((tijd.get_seconds()*6)),cosinusses.get((tijd.get_seconds()*6)))).draw(display);
		hwlib::line(midpoint,hwlib::xy(sinusses.get((tijd.get_minutes()*6)),cosinusses.get((tijd.get_minutes()*6)))).draw(display);
		hwlib::line(midpoint,hwlib::xy(sinusses.get((tijd.get_hours()*30)),cosinusses.get((tijd.get_hours()*30)))).draw(display);
		display.flush();
	}

};


#endif