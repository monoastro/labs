//curve fitting by method of least squares
#pragma once

#include <stdio.h>
#include <math.h>
#include "definitions.h"
#include <malloc.h>

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

	enterTable3(data);

	printf("Enter the data points in the form x y:\n");
	for(unsigned i = 0; i<n_user; i++)
	{
		//scanf("%f %f", &data[i][0], &data[i][1]);
		
		//compute sums simultaneously
		sumx += data[i][0];
		sumx2 += data[i][0]*data[i][0];
		sumy += data[i][1];
		sumxy += data[i][0] * data[i][1];
	}

	printf("\nData points entered are:\n");
	//display table
	for(unsigned i = 0; i<n_user; i++) printf("(%0.1f, %0.1f)\n", data[i][0], data[i][1]);

	//free memory
	free(data);

	//compute a and b
	b = (n_user*sumxy - sumx*sumy)/(n_user*sumx2 - sumx*sumx); 
	a = (sumy - b*sumx)/n_user;
	
	//display a and b
	printf("\nThe values of a and b are computed are %0.3f and %0.3f.\n", a, b);
	printf("Therefore, the required fitted straight line is y = %0.3f + %0.3fx\n", a ,b);
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
