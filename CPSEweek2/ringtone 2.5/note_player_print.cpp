#include "note_player_print.hpp"
#include <iostream>
   
void note_player_print::play( const note & n ){
   std::cout << n.duration << " " << n.frequency << " , ";
}
