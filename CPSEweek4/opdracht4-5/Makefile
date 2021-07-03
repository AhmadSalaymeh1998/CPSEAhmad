#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################
gcc := g++ -std=c++17

# source files in this project (main.cpp is automatically assumed)
SOURCES := decompress.asm compressed.asm

# header files in this project
HEADERS := 
#match.hpp compressor.hpp decompressor.hpp

# other places to look for files for this project
SEARCH  := 

CLEAN += main2.o
######
compressed.asm : main2.exe
	./main2.exe
main2.exe : main2.o
	$(gcc) main2.o -o main2.exe
			
main2.o : main2.cpp compressor.hpp
	$(gcc) -c main2.cpp -o main2.o



# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due