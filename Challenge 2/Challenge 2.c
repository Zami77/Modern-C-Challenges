#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Numerical Differentiation

double derivative(double (*f)(double),double input)
{
    double h = 0.0001;
    double fx = (*f) (input);
    printf("f(x):%f\n",fx);

    //Central difference formula
    return (((fx + h) - (fx - h)) / (2.0)*h);
}
int main(void)
{
    printf("Numerical Differentiation\n");
    printf("dx of cos(0):%f\n",derivative(cos, 0.0));
    printf("dx of sin(45):%f",derivative(sin, 45.0));
}
