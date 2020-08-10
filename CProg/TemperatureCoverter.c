#include<stdio.h>

void main ()
{
    float T_C=0.0; 
    float T_F=0.0;
    printf("\n-----------\nEnter temperature in degC: ");
    scanf ("%f",&T_C);
    T_F +=T_C;
    printf("Enter temperature in degF: %.4f\n-----------\n", T_F);


}   