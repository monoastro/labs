#pragma once
#include "definitions.h"

void printMatrix(float **matrix, unsigned size_m, unsigned size_n)
{
	for(size_t i = 0; i<size_m; i++)
	{
		for(size_t j = 0; j<size_n; j++)
		{
			printf("%10.6f ", matrix[i][j]);
		}
		printf("\n");
	}
}
void gaussElimination()
{
	unsigned size_m, size_n;
	float **matrix;
	
	printf("Enter the values of row and column of augumented matrix [A:C] :\n");
	scanf("%u %u", &size_m, &size_n);

	//allocate memory for the row
	matrix = (float**)malloc(size_m*sizeof(float*));
	//allocate memory for the remaining elements
	for(size_t i = 0; i<size_m; i++) matrix[i] = (float*)malloc(size_n*sizeof(float));
/*
	printf("Enter values of the matrix in order\n");
	//read values from user
	for(size_t i = 0; i<size_m; i++)
	{
		for(size_t j = 0; j<size_n; j++)
		{
			scanf("%f", &matrix[i][j]);
			if((i == j) && !(matrix[i][j]))
			{
				printf("Gauss Jordan cannot be applied\n");
				return;
			}
		}
	}
*/
	for(size_t i = 0; i<size_m; i++)
	{
		for(size_t j = 0; j<size_n; j++)
		{
			matrix[i][j] = i*j +1;
			printf("%10.6f", matrix[i][j]);
		}
		printf("\n");
	}
	//Change [A:C] into upper triangular form
	for(size_t i = 0; i<size_m; i++)
	{
		for(size_t j = 0; j<size_n; j++)
		{
			if(i == 1 && j == 0)
			{
				float ratio = matrix[i][j] / matrix[0][0];
				for(size_t k = j; k<size_n; k++)
				{
					matrix[i][k] -= ratio*matrix[i-1][k];
				}
			}

			if(i == 2 && j == 0)
			{
				float ratio = matrix[i][j] / matrix[0][0];
				for(size_t k = j; k<size_n; k++)
				{
					matrix[i][k] -= ratio*matrix[i-2][k];
				}
			}

			if(i == 2 && j == 1)
			{
				float ratio = matrix[i][j] / matrix[1][1];
				for(size_t k = j; k<size_n; k++)
				{
					matrix[i][k] -= ratio*matrix[i-1][k];
				}
			}
		}
	}
	
	//print
	printf("\n");
	printMatrix(matrix, size_m, size_n);

	for(size_t i = 0; i<size_m; i++) free(matrix[i]);
	free(matrix);


	//3 failure cases
}

