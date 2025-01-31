#ifndef _MELODY_HPP
#define _MELODY_HPP

#include "note_player.hpp"

// an abstract melody

class melody {
public:
   virtual void play( note_player & p ) =0;
   
};

class mymelody : public melody {
public:
	void play(note_player & p) override ;
};

void bestand_schrijven();

#endif
