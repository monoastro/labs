//curve fitting by method of least squares
#pragma once

#include <stdio.h>
#include <math.h>
#include "definitions.h"

//data points
#define maxSize 100

void curveFitting()
{
	unsigned n_user = 0; 
	float data[maxSize][2], sumx = 0, sumx2 = 0, sumy = 0, sumxy = 0;
	float a, b;

	//read values from user
	printf("\nLinear Curve Fitting\n");
	printf("Enter the number of data points:\n");
	scanf("%u", &n_user);
	for(unsigned i = 0; i<n_user; i++)
	{
		scanf("%f %f", &data[i][0], &data[i][1]);
		
		//compute sums simultaneously
		sumx += data[i][0];
		sumx2 += data[i][0]*data[i][0];
		sumy += data[i][1];
		sumxy += data[i][0] * data[i][1];
	}


	//display table
	for(unsigned i = 0; i<n_user; i++) printf("(%f, %f)\n", data[i][0], data[i][1]);

	//compute a and b
	b = (n_user*sumxy - sumx*sumy)/(n_user*sumx2 - sumx*sumx); 
	a = (sumy - b*sumx)/n_user;
	
	//display a and b
	printf("The values of a and b are %10.6f and %10.6f\n", a, b);
	printf("\nThe required fitted straight line is y = %10.6f + %10.6fx\n", b ,a);
}
