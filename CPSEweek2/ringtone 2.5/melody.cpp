#include "fur_elise.hpp"
#include "melody.hpp"

void myplay( note_player & p ){
	p.play( note{ note::A4,  note::dQ } ); 
	p.play( note{ note::A4s,  note::dQ } ); 
	p.play( note{ note::B4,  note::dQ } ); 
	p.play( note{ note::C5,  note::dQ } ); 
	p.play( note{ note::C5s,  note::dQ } ); 
	p.play( note{ note::D5,  note::dQ } ); 
	p.play( note{ note::D5s,  note::dQ } ); 
	p.play( note{ note::E5,  note::dQ } ); 
	p.play( note{ note::F5,  note::dQ } ); 
	p.play( note{ note::F5s,  note::dQ } ); 
	p.play( note{ note::G5,  note::dQ } ); 
	p.play( note{ note::G5s,  note::dQ } ); 
	p.play( note{ note::A5,  note::dQ } ); 
	p.play( note{ note::A5s,  note::dQ } ); 
	p.play( note{ note::B5,  note::dQ } ); 
}
