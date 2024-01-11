#include "recursive.h"

void lab5()
{
	unsigned num = 5;

	toh(num, 'A', 'B', 'C');

	std::cout<<"\nThe fibonacci numbers are:\n";
	for(unsigned i = 0; i<num; i++) 
		std::cout<<fibonacci(i)<<"\n";

	std::cout<<"\nThe factorial of "<<num<<" is "<<factorial(num)<<".\n";
}
