#pragma once
#include <stdio.h>

//constants go here
#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067
#define euler 2.718281828

// General cosmetic functions
void printSeparator()
{
    printf("\n");
    for (unsigned i = 0; i < 54; i++) { printf("-"); }
    printf("\n");
}

//lab 3
//function so that I don't have to input the table values
//to make a slight cosmetic change
void enterTable3c(float **data)
{
	data[0][0] = 2468; data[0][1] = 25000;
	data[1][0] = 4268; data[1][1] = 3800;
	data[2][0] = 6824; data[2][1] = 5600;
	data[3][0] = 8246; data[3][1] = 8400;
	data[4][0] = 2648; data[4][1] = 6500;
	data[5][0] = 8426; data[5][1] = 4800;
	data[6][0] = 4628; data[6][1] = 8300;
}

void printLine(float a, float b)
{	
	//very cosmetic printing; tbb is not coming to check my output and i'm bored
	//check sign of b; if positive put sign as + else put sign as empty
	char sign = (b > 0 ? '+' : '\0');
	printf("Therefore, the required fitted straight line is:\n\t\t y = ");
	//cases; y = 0, y = bx
	if(!a)
	{
		if(!b) printf("0\n"); 
		else printf("%0.2fx\n", b);
	}
	//case y = a
	else if(!b) printf("%0.2f\n", a);
	//case y = a + x, y = a + bx 
	else
	{
		printf("%0.2f%c%0.2fx\n", a, sign, b);
	}
}
