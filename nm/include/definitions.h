#pragma once
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <iostream>

//constants go here
#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067
#define euler 2.718281828

//functions go here
//fnx_y for lab x, question y

//lab 1
double fn1_1(double x) { return (x * x - 3*x + 2); }
double dfn1_1(double x) { return (2*x - 3); }
double fn1_2(double x) { return (x * log10(x) - 1.2); }
double dfn1_2(double x) { return (log10(euler) + log10(x)); }
double fn1_3(double x) { return (x * log(x) - 1.2); }
double dfn1_3(double x) { return (1 + log(x)); }
double fn1_4(double x) { return (3*x - cos(x) - 1); }
double dfn1_4(double x) { return (3 + sin(x)); }
double fn1_5(double x) { return (4*sin(x) - exp(x)); }
double dfn1_5(double x) { return (4*cos(x) - exp(x)); }
double fn1_6(double x) { return (1/x - 3); } //find the reciprocal of 3
double dfn1_6(double x) { return (-1/(x*x)); }
//lab 2
double fn2_1(double x) { return (x * x * x - 4 * x - 9); }
double fn2_2(double x) { return (pow(euler, x) - 3 * x); }
double fn2_3(double x) { return (x * log10(x) - 1.2); }
double fn2_4(double x) { return (x * log(x) - 1.2); }
double fn2_5(double x) { return (x * sin(x) - 1); }
double fn2_6(double x) { return (pow(5, x) - 6 * x); }
//lab 3
//function so that I don't have to input the table values to make a slight cosmetic change
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
//lab 4
//tbb got lazy
double fn4_1(double x) { return (x*x - 1); }
double fn4_4(double x) { return (x*x*x - 5*x + 1); } 
double fn4_5(double x) { return (x*x*x - x -1); } 

// General cosmetic functions
void printSeparator()
{
    for (unsigned i = 0; i < 67; i++) { printf("-"); }
    printf("\n");
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
	else printf("%0.2f%c%0.2fx\n", a, sign, b);
}

void printExp(float a, float b)
{
	printf("The equation of the curve is y =");
	if(!a) printf("0\n");
	else if(!b) printf("%0.6f\n", a);
	else printf("%0.6fe^(%0.6fx).\n", a, b);
}
