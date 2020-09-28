#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

void bestand_schrijven(){
	std::string noten[15]={"A4","A4s","B4","C5","C5s","D5","D5s","E5","F5","F5s","G5","G5s","A5","A5s","B5"};
	
	std::ofstream myfile;
    myfile.open("melody.cpp");
	myfile<<"#include \"fur_elise.hpp\"\n#include \"melody.hpp\"\n\n";
	myfile<<"void myplay( note_player & p ){\n";
    for (unsigned int i=0; i< 15 ; i++ ){
		myfile<<"\tp.play( note{ note::"<< noten[i] << ",  note::dQ } ); \n"; 
    }
	 myfile << "}\n";
    myfile.close();
}

