#include "recursive.h"

void lab5()
{
	TOH tower(3);

	unsigned num = 5;
	std::cout<<"\nThe fibonacci numbers are:\n";
	for(unsigned i = 0; i<num; i++) 
		std::cout<<fibonacci(i)<<"\n";

	std::cout<<"\nThe factorial of "<<num<<" is "<<factorial(num)<<".\n";
}
