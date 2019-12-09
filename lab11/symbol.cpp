// Zachary Sy 
// Symbol

#include <iostream>
#include <cmath>
#include "gfx.h"

using namespace std;

void square(int);
void circle(int);
void triangle(int);
void polygon(int,int);
  
int main()
{
  const int SIZE = 50, xsize = 500, ysize = 500;
  char c;

  gfx_open(xsize, ysize, "Symbolic Typewriter");

  while(true) {
    c = gfx_wait();
	
	switch(c){
		case 1:
			square(SIZE);
			break;
		case 'c':
			circle(SIZE);
			break;
		case 't':
			triangle(SIZE);
			break;
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			polygon(c,SIZE);
			break;
		case 27:
			gfx_clear();
			break;
		case 'q':
			return 0;
			break;
			
	}
  }

  return 0;
}

void square(int SIZE){
	int x = gfx_xpos(), y = gfx_ypos();
	
	gfx_color(0,0,255);
	
	//Points
	int left =  x-(SIZE/2);
	int right = x+(SIZE/2);
	int top = y-(SIZE/2);
	int bottom = y+(SIZE/2);
	
	// Lines
	gfx_line(left, top, right, top);
	gfx_line(left, bottom, right, bottom);
	gfx_line(left, top, left, bottom);
	gfx_line(right, top, right, bottom);
	
}

void circle(int SIZE){
	int x = gfx_xpos(), y = gfx_ypos();
	
	gfx_color(255,255,255);
	gfx_circle(x,y,SIZE/2);
}

void triangle(int SIZE){
	int x = gfx_xpos(), y = gfx_ypos();
	
	gfx_color(0,255,0);
	
	//Points
	int left =  x-(SIZE/2);
	int right = x+(SIZE/2);
	int top = y-(SIZE/2);
	int bottom = y+(SIZE/2);
	
	// Lines
	gfx_line(x, top, left, bottom);
	gfx_line(x, top, right, bottom);
	gfx_line(left, bottom, right, bottom);
	
}

void polygon(int n, int SIZE){
	int x = gfx_xpos(), y = gfx_ypos(), r = SIZE/2;
	n = n-48;
	gfx_color(128,0,128);
	
	for(int i = 0; i < n; i++){
		int x1 = x + r*cos((i*2*M_PI)/n);
		int y1 = y + r*sin((i*2*M_PI)/n);
		int x2 = x + r*cos(((i+1)*2*M_PI)/n);
		int y2 = y + r*sin(((i+1)*2*M_PI)/n);
		
		gfx_line(x1,y1,x2,y2);
	}
	
}