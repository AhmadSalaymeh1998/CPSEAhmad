#ifndef _NOTE_PLAYER_PRINT_HPP
#define _NOTE_PLAYER_PRINT_HPP

#include "note_player.hpp"


class note_player_print : public note_player {
private:   
//   hwlib::pin_out & lsp;

public: 
//	hwlib::pin_out & lsp
   note_player_print(){}
   
   void play( const note & n ) override;
};

#endif
