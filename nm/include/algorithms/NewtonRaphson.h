#include <stdio.h>
#include <math.h>
#include "definitions.h" //cosmetics and constants are defined here
#include "nrFns.h" //functions are defined here

void NewtonRaphsonC()
{
    float x_initial, epsilon, error_threshold, x_final;
    unsigned MAX_ITERATION, iter = 0;
    int err_flag = 1;
    printf("Enter your initial guess\n");
    scanf("%f", &x_initial);
    printf("Enter error threshold:\n");
    scanf("%f", &error_threshold);
    printf("Enter MAX_ITERATION value: \n");
    scanf("%u", &MAX_ITERATION);

    printSeparator();
    printRow();
    printSeparator();

    do
    {
        if (!dfn(x_initial))
        {
            printf("\nMathematical Error\n");
			err_flag = 2;
            break;
        }

        // Newton-Raphson
        x_final = x_initial - fn(x_initial) / dfn(x_initial);

        // Printing the table
        printf("%10u %10.6f %10.6f %10.6f %10.6f\n", iter, x_initial, fn(x_initial), x_final, fn(x_final));

        // Further calculations
        x_initial = x_final;

        epsilon = abs(fn(x_final));

        if (++iter == MAX_ITERATION)
        {
            err_flag = 0;
            break;
        }

    } while (epsilon > error_threshold);

    printSeparator();

	if (!err_flag)
	{
		printf("\nSolution does not converge below given error within the given iterations\n");
	}
	else if (err_flag == 1)
    {
        printf("\nThe value of the root is %0.8f\n", x_final);
    }
}

