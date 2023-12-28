#include <stdio.h>
#include <graphics.h>
#include <math.h>

void dda()
{
	int x1, y1, x2, y2, dx, dy, steps, i;
	float x, y, x_inc, y_inc;

	printf("Enter the coordinates of the first point: ");
	scanf("%d %d", &x1, &y1);
	printf("Enter the coordinates of the second point: ");
	scanf("%d %d", &x2, &y2);

	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	dx = x2 - x1;
	dy = y2 - y1;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	x_inc = dx / (float)steps;
	y_inc = dy / (float)steps;

	x = x1;
	y = y1;

	putpixel(x, y, GREEN);

	for (i = 0; i < steps; i++)
	{
		x += x_inc;
		y += y_inc;

		putpixel(round(x), round(y), GREEN);
	}

	getch();
	closegraph();
};
