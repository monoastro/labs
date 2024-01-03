#pragma once

#include <stdio.h>
#include <math.h>
#include "definitions.h"

//#define f(x) (x * x * x - 4 * x - 9)
//#define f(x) (pow(euler, x) - 3 * x)
//#define f(x) (x * log10(x) - 1.2)

//#define f(x) (x * log(x) - 1.2)
//#define f(x) (x * sin(x) - 1)

#define f(x) (pow(5, x) - 6 * x)

void lab2()
{
	double x_lower, x_upper, x_mid, error_threshold;
	unsigned iter = 0;
	while(true)
	{
		printf("Enter the upper and lower bound.\n");
		scanf("%lf %lf", &x_lower, &x_upper);
		printf("Enter the desired predefined error_threshold.\n");
		scanf("%lf", &error_threshold);

		if(f(x_lower)*f(x_upper) < 0)
	{
			break;
		}

		printf("Initial guesses are wrong, try again\n\n");
	}
	printSeparator();
	printf("Iteration\tx_lower\tx_upper\tx_mid\tf(x_mid)\n");
	printSeparator();
	
	do
	{
		x_mid = (x_lower + x_upper)/2.0f;
		printf("%10d %10.6lf %10.6lf %10.6lf %10.6lf\n", ++iter, x_lower, x_upper, x_mid, f(x_mid));

		if(f(x_mid)*f(x_upper) < 0)
		{
			x_lower = x_mid;
		}
		else
		{
			x_upper = x_mid;
		}
	} while(abs(f(x_mid)) > error_threshold);
	printf("The desired root below the predefined error is %0.20lf\n", x_mid);
}
