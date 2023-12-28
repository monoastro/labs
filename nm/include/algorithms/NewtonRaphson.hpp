#include <iostream>
#include <math.h>
#include "definitions.h"
#include "nrFns.h"


void NewtonRaphsonCpp()
{
	float x_initial, epsilon, error_threshold, x_final;
	unsigned MAX_ITERATION, iter = 0;
	int err_flag = 1;
	std::cout<<"Enter your initial guess\n";
	std::cin>>x_initial;
	std::cout<<"Enter error threshold:\n";
	std::cin>>error_threshold;
	std::cout<<"Enter MAX_ITERATION value: \n";
	std::cin>>MAX_ITERATION;

	printSeparator();
	printRow();
	printSeparator();

	do
	{
		if(!dfn(x_initial))
		{
			std::cout<<"\nMathematical Error\n";
			err_flag = 2;
			break;
		}
		x_final = x_initial - fn(x_initial)/dfn(x_initial);
	
		//printing the table
        printf("%10u %10.6f %10.6f %10.6f %10.6f\n", iter, x_initial, fn(x_initial), x_final, fn(x_final));

		//further calc
		x_initial = x_final;
		
		epsilon = abs(fn(x_final));
		if(++iter == MAX_ITERATION)
		{
			err_flag = 0;
			break;
		}

	} while(epsilon > error_threshold);

	printSeparator();

	if (!err_flag)
	{
		printf("\nSolution does not converge below given error within the given iterations\n");
	}
	else if (err_flag == 1)
    {
        printf("\nThe value of the root is %0.8f\n", x_final);
    }
    else if (err_flag == 2)
	{
		return;
	}
}
