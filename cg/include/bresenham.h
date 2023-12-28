#include <stdio.h>
#include <graphics.h>

void drawLineBresenham() 
{
	int x1, y1, x2, y2;

	printf("Enter the coordinates of the first point: ");
	scanf("%d %d", &x1, &y1);
	printf("Enter the coordinates of the second point: ");
	scanf("%d %d", &x2, &y2);

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int slope = dy > dx ? 1 : 0;

    if (dy > dx) {
        int temp = dx;
        dx = dy;
        dy = temp;
    }

    int p = 2 * dy - dx;
    int twoDy = 2 * dy;
    int twoDyMinusDx = 2 * (dy - dx);

    int x, y;

    if (x1 > x2) {
        x = x2;
        y = y2;
        x2 = x1;
    } else {
        x = x1;
        y = y1;
    }

    putpixel(x, y, GREEN);

    while (x < x2) {
        x++;
        if (p < 0) {
            p += twoDy;
        } else {
            if (slope) {
                y++;
            } else {
                y += (y2 > y1) ? 1 : -1;
            }
            p += twoDyMinusDx;
        }
        putpixel(x, y, GREEN);
    }

	getch();
	closegraph();
}
