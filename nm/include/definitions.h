#pragma once
#include <stdio.h>

#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067
#define euler 2.718281828

// Cosmetic functions
void printSeparator()
{
    printf("\n");
    for (unsigned i = 0; i < 54; i++) { printf("-"); }
    printf("\n");
}

void printRow()
{
    printf("Iteration\t  x_0\t  f(x_0)       x_1\tf(x_1)");
}
