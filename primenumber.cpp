#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <ctime>

void primeNumber(int position, int *prime) {
	int counter = 2;
	int number = 3;
	bool isprime;
	int *primes = new int[position];
	int root;
	int i;

    	double error = 0.1; //define the precision of your result
    	double rnumber;
    	double s;


	primes[0] = 2;
	primes[1] = 3;
	if (counter >= position) {
		*prime = primes[position-1];
	}
	while (counter < position){
		number += 2;
		isprime = true;
		
		rnumber = (double) number;
		s = rnumber;

		while ((s - rnumber / s) > error) //loop until precision satisfied 
	    	{
	        	s = (s + rnumber / s) / 2;
	    	}

	    	root = (int) s;

		for(i=0; i < counter; i++) {
			if(number%primes[i] == 0) {
				isprime = false;
				break;
			}
			if(i >= root) {
				break;
			}
		}
		if(isprime){
			primes[counter] = number;
			*prime = number;
			counter += 1;
		}
	}  
}

int main(int argc, char *argv[])
{
    	int position = atoi(argv[1]);
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
