#pragma once

//secant method
#include <stdio.h>
#include <math.h>
#include "definitions.h"

//functions
#define fn(x) (x*x*x - 2*x - 5)

void secantMethod()
{
	double x_0, x_1, x_final, epsilon, error_threshold;
    unsigned MAX_ITERATION, iter = 0;
    int err_flag = 1;

	//input
	printf("Enter your initial guesses, x_0 and x_1\n");
	scanf("%lf %lf", &x_0, &x_1);
    printf("Enter error threshold:\n");
    scanf("%lf", &error_threshold);
    printf("Enter MAX_ITERATION value: \n");
    scanf("%u", &MAX_ITERATION);

	//what it says below
	printf("Secant Method\n");
    printSeparator();
	printf("Iteration\tx_0\tx_1\tx_final\tf(x_final)\n");
    printSeparator();
	do
	{
		if(!(fn(x_1) - fn(x_0))) 
		{
			printf("Mathematical error detected. Please try again.\n");
			err_flag = 2;
		}
		
		//secant method
		x_final = x_1 - (fn(x_1) * (x_1 - x_0)) / (fn(x_1) - fn(x_0));

        // Printing the table
        printf("%10u %10.6f %10.6f %10.6f %10.6f\n", iter, x_0, x_1, x_final, fn(x_final));

		//error function
		epsilon = abs((x_final - x_1) / x_final);

		//update values
		x_0 = x_1;
		x_1 = x_final;

		if(++iter == MAX_ITERATION)
		{
			err_flag = 0;
			break;
		}
	} while(epsilon > error_threshold);
	printSeparator();

	//and finally, the output
	if(!(err_flag)) printf("\nMethod failed after %u iterations\n", MAX_ITERATION);
	else if(err_flag == 1) printf("\nThe value of the root is %0.8lf\n", x_final);
}
