#include "labs.h"
#include "definitions.h"

int main()
{	
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	setcolor(GREEN);

	lab5();

	getch();
	closegraph();
	return 0;
}

void lab5()
{
	delay(10);
	//coordinates of a triangle in the first quadrant	
	int triangle[3][2] = 
	{
		{-50, 0},
		{-100, -100},
		{-50, -100 }
	};
	int axis[2] = {0, 0};
	drawTriangle(triangle);

	// translation stuff
	for(size_t i = 0; i<200; i++)
	{
		cleardevice();
		translate(3, triangle, 1, 0);
		drawTriangle(triangle);
		delay(10);
	}

	//scaling stuff
	scale(3, triangle, 0.6, 0.6, axis);
	drawTriangle(triangle);

	//shearing stuff
	shear(3, triangle, 1.1, 1.1, axis);
	drawTriangle(triangle);

	return;
	int car[4][2] = 
	{
		{0, 0},
		{100, 0},
		{100, 50},
		{0, 50}
	};

	//draw the car
	drawObject(4, car);

	//for(size_t i = 0; i<3; i++) printf("%d %d\n", triangle[i][0], triangle[i][1]);
	//for(size_t i = 0; i<4; i++) printf("%d %d\n", car[i][0], car[i][1]);
}

void lab4()
{	
	axes();
	//coordinates of a triangle in the first quadrant
	int triangle[3][2] = 
	{
		{50, 50},
		{50, 200},
		{200, 50}
	};
	//draw the triangle in the first quadrant 
	drawTriangle(triangle);
	
	//REFLECTION stuff reflect the triangle with respect to the x-axis
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
	int axis[2] = {50, 50};
	printf("%u %u\n", axis[0], axis[1]);
	float theta = -60.f;
	rotate(3, triangle, theta, axis);
	drawTriangle(triangle);
}

void lab3()
{
	midpointEllipse(WIDTH/2, HEIGHT/2, WIDTH/4, HEIGHT/8);
}

void lab2()
{
	//draw a diamond using bla
	drawLineBresenham(0, HEIGHT/2, WIDTH/2, 0);
	drawLineBresenham(WIDTH/2, 0, WIDTH, HEIGHT/2);
	drawLineBresenham(0, HEIGHT/2, WIDTH/2, HEIGHT);
	drawLineBresenham(WIDTH/2, HEIGHT, WIDTH, HEIGHT/2);

	//draw a circle using mid point
	midpointCircle(WIDTH/2, HEIGHT/2, WIDTH / 4);
}
