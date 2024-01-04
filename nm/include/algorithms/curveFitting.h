//curve fitting by method of least squares
#pragma once

#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include "definitions.h"

#define manualInput 1

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
	enterTable3c(data);
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
	printLine(a, b);
}
