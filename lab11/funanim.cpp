// Zachary Sy 
// Funanim

#include <iostream>
#include <cmath>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "gfx.h"

using namespace std;

void polygon(int n,int,int, float ,float&);

const int SIZE = 500;
const int xsize = 500, ysize = 500;

float r = SIZE/2;
int sleepTime = 10000;
  
int main(){
  	int n = 3+48;
  	float rate = 50;
  	char c;
  	
  	gfx_open(xsize, ysize, "Rotating Animation");

	while(true) {
		polygon(n,xsize/2,ysize/2, r, rate);
		if(gfx_event_waiting()){
			c = gfx_wait();
		
			switch(c){
				case 'R':
					r += 5;
					break;
				case 'T':
					if(r > 0){
						r -= 5;
					}
					break;
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':{
					int n = c;
					polygon(n,xsize/2,ysize/2,r, rate);
					break;}
				case 'c':
					gfx_clear();
					break;
				case 'p':{
						bool stop = true;
						while(stop){
							c = gfx_wait();
							switch(c){
								case 'r':
									stop = false;
									break;
								case 'R':
									r += 5;
									break;
								case 'T':
									if(r > 0){
										r -= 5;
									}
									break;
								case 'c':
									gfx_clear();
									break;
								case 'q':
									return 0;
									break;
								case '3':
								case '4':
								case '5':
								case '6':
								case '7':
								case '8':
								case '9':{
									int n = c;
									polygon(n,xsize/2,ysize/2,r, rate);
									break;}	
							}
						}
					}
					
					break;
				case 'q':
					return 0;
					break;
				
			
			}
		}
  	}

  return 0;
}

void polygon(int n, int x, int y, float r, float& rate){
	n = n-48;
	gfx_color(rand()%256,rand()%256,rand()%256);
	
	
	for(int i = 0; i < n; i++){
		int theta1 = (i*2*M_PI)/n + rate; 
		int theta2 = ((i+1)*2*M_PI)/n + rate;
		
		int x1 = x + r*cos(theta1);
		int y1 = y + r*sin(theta1);
		int x2 = x + r*cos(theta2);
		int y2 = y + r*sin(theta2);
		
		gfx_line(x1,y1,x2,y2);
	}
	
	usleep(sleepTime);
	rate++;
}