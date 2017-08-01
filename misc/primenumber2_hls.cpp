#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>

#include <math.h>

int rootNumber(int rnumber) {
	int s;
	int i;
	s = rnumber;
	for(i=0; i < 4; i++) {
		s = (s + rnumber / s) / 2;
	}
	return s;
}

int IS_prime(int num)
{
	int isprime = 1;
	for(int i = 2; i <= rootNumber(num); i += 2)
	{
		if(i % 2 == 0)
			i++;

		if((num % i) == 0)
		{
			isprime = 0;
			break;
		}
	}

	return isprime;
}

void primeNumber(int position, int *prime) {
	int i = 2;
	int count = 1;
	if(position == 1) {
		*prime = i;
	}
	i++;
	while( count < position) {
		if(IS_prime(i)==1) {
			count++;
			*prime = i;
		}
		if(count == position)
			break;
		i+=2;
	}
}

int main(int argc, char *argv[])
{
    std::string s = argv[1];
	int position = stoi(s);
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