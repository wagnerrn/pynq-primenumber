#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <ctime>

void primeNumber(int position, int *prime);

int main()
{
    int position = 100000;
	int prime;
	double duration;
	std::clock_t start;
	start = std::clock();
	
	primeNumber(position, &prime);
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout<<"Time: "<< duration  << "s" <<'\n';

	printf("The %d prime number is %d\n",position,prime);

	return 0;
}
