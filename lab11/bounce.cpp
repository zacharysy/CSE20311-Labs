// Zachary Sy 
// Ball

#include <iostream>
#include <cmath>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "gfx.h"

using namespace std;

const int sleepTime = 20000;
const int xsize = 500;
const int ysize = 500;
	
void balls(int& x, int& y, float& vx, float& vy, int rad);

int main(){
	int c;
	const int rad = 25;

  	gfx_open(xsize, ysize, "Bouncing Ball");
	
	int x = xsize/2;
	int y = ysize/2;
	
	srand(time(0));
    float vx = pow(-1,rand())*(rand()%(rad/2)+10);
    float vy = pow(-1,rand())*(rand()%(rad/2)+10);
	
  	while(true){	
		balls(x,y, vx, vy, rad);

    	if(gfx_event_waiting()){
    		c = gfx_wait();
    		
    		if(c == 1){
    			srand(time(0));
	            vx = pow(-1,rand())*(rand()%(rad/2)+10);
    	        vy = pow(-1,rand())*(rand()%(rad/2)+10);
				x = gfx_xpos();
				y = gfx_ypos();
    		}
	    }
  	}


  return 0;
}

void balls(int& x, int& y, float& vx, float& vy, int rad){
	while((x <= xsize-rad  && x >= rad) && (y <= ysize-rad && y > rad)){
		gfx_clear();
		gfx_circle(x,y,rad);
		gfx_flush();
		usleep(sleepTime);
		x += vx;
		y += vy;
		
		if(gfx_event_waiting()){
    		gfx_wait();
    		
    		srand(time(0));
            vx = pow(-1,rand())*(rand()%(rad/2)+10);
            vy = pow(-1,rand())*(rand()%(rad/2)+10);
            x = gfx_xpos();
            y = gfx_ypos();

	    }
	}
	
	if(x <= rad || x >= xsize-rad){
		vx = -vx;
	}
	
	if(y <= rad || y >= ysize-rad){
		vy = -vy;
	}
    
    x += vx;
    y += vy;
}
