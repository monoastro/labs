#include <stdio.h>
#include <math.h>

#include "dda.h"
#include "bresenham.h"
#include "circle.h"
#include "ellipse.h"
#include "transformation.h"

#define width 640
#define height 480

#define PI 3.1415926535889

void lab2();
void lab3();
void lab4();

void axes()
{
	//print axes
	line(width/2, 0, width/2, height);
	line(0, height/2, width, height/2);
}

void translate(unsigned *x, unsigned *y)
{
	//translates the coordinates to the new axes
	*x = (*x + width/2) % width;
	*y = (- *y + height/2) %height;
}

void drawTriangle(unsigned coordinates[3][2])
{
	//draw functions guarantee that the data received is not modified
	//so work with a copy of the coordinates; it's a pointer
	unsigned copy[3][2];
	for(unsigned i = 0; i<3; i++)
	{
		copy[i][0] = coordinates[i][0];
		copy[i][1] = coordinates[i][1];
	}
	//translate to the axes defined by the computer
	for(unsigned i = 0; i<3; i++) translate(&copy[i][0], &copy[i][1]);
	//plot the translated points
	for(unsigned i = 0; i<3; i++) line(copy[i][0], copy[i][1], copy[(i+1)%3][0], copy[(i+1)%3][1]);
}

void reflectXaxis(unsigned num_points, unsigned coordinates[][2])
{
	//make the y coordinates negative
	for(unsigned i = 0; i<num_points; i++) coordinates[i][1] = -coordinates[i][1];
}

void reflectYaxis(unsigned num_points, unsigned coordinates[][2])
{
	//make the x coordinates negative
	for(unsigned i = 0; i<num_points; i++) coordinates[i][0] = -coordinates[i][0];
}

void rotate(unsigned num_points, unsigned coordinates[][2], int theta, unsigned axis[2])
{
	//buffer the coordinates because the updates are simultaneous
	unsigned copy[2];

	//rotate the coordinates by theta degrees
	for(unsigned i = 0; i<num_points; i++)
	{
		copy[0] = axis[0] + (coordinates[i][0] - axis[0]) * cos(theta * PI / 180) - (coordinates[i][1] - axis[1]) * sin(theta * PI / 180);
		copy[1] = axis[1] + (coordinates[i][0] - axis[0]) * sin(theta * PI / 180) + (coordinates[i][1] - axis[1]) * cos(theta * PI / 180);

		//copy the rotated coordinates back to the original array
		coordinates[i][0] = copy[0];
		coordinates[i][1] = copy[1];
	}
}

int main()
{	
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	setcolor(GREEN);

	axes();
	//coordinates of a triangle in the first quadrant
	unsigned triangle[3][2] = 
	{
		{50, 50},
		{100, 200},
		{220, 30}
	};
	//draw the triangle in the first quadrant 
	drawTriangle(triangle);

	//REFLECTION stuff
	//reflect the triangle with respect to the x-axis
	reflectXaxis(3, triangle);
	drawTriangle(triangle);
	//reflect the above triangle with respect to the y-axis
	reflectYaxis(3, triangle);
	drawTriangle(triangle);

	//reflect the above triangle with respect to the x-axis
	reflectXaxis(3, triangle);
	drawTriangle(triangle);

	//reflect once again to get the original triangle
	reflectYaxis(3, triangle);
	setcolor(RED);
	drawTriangle(triangle);

	//ROTATION stuff
	setcolor(BLUE);
	unsigned axis[2] = {50, 50};
	translate(&axis[0], &axis[1]);
	int theta = -60;
	rotate(3, triangle, theta, axis);
	drawTriangle(triangle);

	getch();
	closegraph();
	return 0;
}


















void lab2()
{
	//draw a diamond using bla
	drawLineBresenham(0, height/2, width/2, 0);
	drawLineBresenham(width/2, 0, width, height/2);
	drawLineBresenham(0, height/2, width/2, height);
	drawLineBresenham(width/2, height, width, height/2);

	//draw a circle using mid point
	midpointCircle(width/2, height/2, width / 4);
}

void lab3()
{
	midpointEllipse(width/2, height/2, width/4, height/8);
}
