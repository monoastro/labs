#pragma once
#include "definitions.h"

void secantMethodCpp(double (*fn)(double))
{
	std::cout<<"Secant Method cpp\n";
	double x_0, x_1, x_final, epsilon, error_threshold;
    unsigned MAX_ITERATION, iter = 0;
    int err_flag = 1;

	//input
	std::cout<<"Enter your initial guesses, x_0 and x_1\n";
	std::cin>>x_0>> x_1;
    std::cout<<"Enter error threshold:\n";
    std::cin>>error_threshold;
    std::cout<<"Enter MAX_ITERATION value: \n";
    std::cin>>MAX_ITERATION;

	//what it says below
	std::cout<<"Secant Method\n";
    printSeparator();
	std::cout<<"Iteration\tx_0\tx_1\tx_final\tf(x_final)\n";
    printSeparator();
	do
	{
		if(!(fn(x_1) - fn(x_0))) 
		{
			std::cout<<"Mathematical error detected. Please try again.\n";
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
	if(!(err_flag)) std::cout<<"\nMethod failed after "<<MAX_ITERATION<<" iterations\n";
	else if(err_flag == 1) std::cout<<"\nThe value of the root is "<<x_final<<"\n";
}
