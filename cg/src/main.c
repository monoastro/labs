#include "dda.h"
#include "bresenham.h"
#include "midpoint.h"

#define width 640
#define height 480

int main()
{	
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");


	//draw a diamond using bla
	drawLineBresenham(0, height/2, width/2, 0);
	drawLineBresenham(width/2, 0, width, height/2);
	drawLineBresenham(0, height/2, width/2, height);
	drawLineBresenham(width/2, height, width, height/2);

	//draw a circle using mid point
	midpointCircle(width/2, height/2, width / 4);

	getch();
	closegraph();

	return 0;
}
