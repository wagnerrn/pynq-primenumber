//double sqrt(double number)
#include <stdio.h>
#include <iostream>


int main(int argc, char *argv[])
{
    double error = 0.00001; //define the precision of your result
    double number = atoi(argv[1]);
    double s = number;

    while ((s - number / s) > error) //loop until precision satisfied 
    {
        s = (s + number / s) / 2;
    }
    printf("The aproximated root is %.2f\n",s);

    return 0;
}