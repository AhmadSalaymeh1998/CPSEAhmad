#include <iostream>
#include <fstream>

#include "compressor.hpp" 
#include "decompressor.hpp" 

int main( void ){	
   lz_compressor< 4096 > compressor;
 
   std::ifstream f1;
   f1.open( "wilhelmus.txt" );
   if( ! f1.is_open()){
      std::cerr << "input file not opened";
      return -1;      
   }
   
   std::ofstream f2( "compressed.asm" );
//   f2.open( "compressed.asm" );
   if( ! f2.is_open()){
      std::cerr << "output file not opened";
      return -1;      
   }
   
   f2 <<".cpu cortex-m0\n" << ".align 2\n" << ".data\n" << ".global compressed\n" << "compressed:\n" << "\t.asciz \"";
   
   compressor.compress( 
      [ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
      [ &f2 ]( char c ){ f2.put( c ); }
  );
   f2 << "\0\"";
   f1.close();
   f2.close();
   
   f1.open( "compressed.txt" );
   if( ! f1.is_open()){
      std::cerr << "compressed file not opened";
      return -1;      
   }   
   
   lz_decompressor decompressor;
   decompressor.decompress( 
      [ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
      [ &f2 ]( char c ){ std::cout << c; }
   );
}