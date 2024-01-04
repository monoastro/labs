//curve fitting by method of least squares
#pragma once

#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include "definitions.h"

#define manualInput 1
void enterTable3(float **data);

void curveFitting()
{
	float **data;
	unsigned n_user = 0; 

	float sumx = 0, sumx2 = 0, sumy = 0, sumxy = 0;
	float a, b;

	//read values from user
	printf("\nLinear Curve Fitting\n");
	printf("Enter the number of data points:\n");
	scanf("%u", &n_user);

	//allocate memory for a 2D array of size n_user*2; n rows and 2 columns
	data = (float**)malloc(n_user*sizeof(float*));
	for(unsigned i = 0; i<n_user; i++) data[i] = (float*)malloc(2*sizeof(float));	

#if !manualInput
	enterTable3(data);
#else 
	printf("Enter the data points in the form x y:\n");
#endif

	//read values from user if you are masochistic
	for(unsigned i = 0; i<n_user; i++)
	{

	#if manualInput
		scanf("%f %f", &data[i][0], &data[i][1]);
	#endif
		
		//compute sums simultaneously as we input data
		sumx += data[i][0];
		sumx2 += data[i][0]*data[i][0];
		sumy += data[i][1];
		sumxy += data[i][0] * data[i][1];
	}

	printf("\nData points entered are:\n");
	//display table
	for(unsigned i = 0; i<n_user; i++) printf("(%0.0f, %0.0f)\n", data[i][0], data[i][1]);

	//free memory
	free(data);

	//compute a and b
	b = (n_user*sumxy - sumx*sumy)/(n_user*sumx2 - sumx*sumx); 
	a = (sumy - b*sumx)/n_user;
	
	//display stuff 
	printf("\nThe values of a and b are computed are %0.6f and %0.6f.\n", a, b);

	//very cosmetic printing; tbb is not coming to check my output and i'm bored
	//check sign of b; if positive put sign as + else put sign as empty
	char sign = (b > 0 ? '+' : '\0');
	printf("Therefore, the required fitted straight line is:\n\t\t");
	//cases; y = 0, y = bx
	if(!a)
	{
		if(!b) printf("y = 0\n"); 
		else printf("y = %0.2fx\n", b);
	}
	//case y = a
	else if(!b) printf("y = %0.2f\n", a);
	//case y = a + x, y = a + bx 
	else
	{
		printf("y = %0.2f%c%0.2fx\n", a, sign, b);
	}
}

//function so that I don't have to input the table values
//to make a slight cosmetic change
void enterTable3(float **data)
{
	data[0][0] = 2468; data[0][1] = 25000;
	data[1][0] = 4268; data[1][1] = 3800;
	data[2][0] = 6824; data[2][1] = 5600;
	data[3][0] = 8246; data[3][1] = 8400;
	data[4][0] = 2648; data[4][1] = 6500;
	data[5][0] = 8426; data[5][1] = 4800;
	data[6][0] = 4628; data[6][1] = 8300;
}
