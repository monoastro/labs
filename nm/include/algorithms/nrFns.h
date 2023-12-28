#pragma once
#include <math.h>
#include "definitions.h"

// Define the functions for NewtonRhapson and its derivative here
//#define fn(x) (x * x - 3*x + 2)
//#define dfn(x) (2*x - 3)

//#define fn(x) (x * log10(x) - 1.2)
//#define dfn(x) (log10(euler) + log10(x))

//#define fn(x) (x * log(x) - 1.2)
//#define dfn(x) (1 + log(x))

//#define fn(x) (3*x - cos(x) - 1)
//#define dfn(x) (3 + sin(x))

//#define fn(x) (4*sin(x) - exp(x))
//#define dfn(x) (4*cos(x) - exp(x))

//find the reciprocal of 3
#define fn(x) (1/x - 3)
#define dfn(x) (-1/(x*x))
