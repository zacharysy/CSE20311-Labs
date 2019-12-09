# Makefile for lab 11
#   "make" or "make all : creates all three executables
#   "make symbol" : creates the symbol executable
#   (similar for "make bounce" and "make funanim")
#   if you need a post 2011 c++ feature, adjust the g++ line
 
all: symbol bounce funanim

inlab: example.cpp
	g++ example.cpp gfx.o -lX11 -o inLab

symbol: symbol.cpp 
	g++ symbol.cpp gfx.o -lX11 -o symbol

bounce: bounce.cpp 
	g++ bounce.cpp gfx.o -lX11 -o bounce

funanim: funanim.cpp 
	g++ funanim.cpp gfx.o -lX11 -o funanim

clean:
	rm symbol bounce funanim inLab

