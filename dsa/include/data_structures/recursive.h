#include <iostream>

void toh(int n, char from, char to, char aux)
{
	if(n==1)
	{
		std::cout<<"Move disk 1 from "<<from<<" to "<<to<<"\n";
		return;
	}

	toh(n-1, from, aux, to);
	std::cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<"\n";
	toh(n-1, aux, to, from);
}

unsigned fibonacci(unsigned n)
{
	return n<2 ? n : fibonacci(n-1) + fibonacci(n-2);
}

unsigned factorial(unsigned n)
{
	return n<2 ? 1 : n*factorial(n-1);
}
