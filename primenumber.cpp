#include <math.h>
#include <stdio.h>

void primeNumber(int position, int *prime) {
	int counter = 2;
	int number = 3;
	bool isprime;
	int primes[100000];
	int root;
	int i;
	primes[0] = 2;
	primes[1] = 3;
	if (counter >= position) {
		*prime = primes[position-1];
	}
	while (counter < position){
		number += 2;
		isprime = true;
		root = sqrt(number);
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

int main() {
	int position = 70000;
	int prime;
	primeNumber(position, &prime);
	printf("The %d prime number is %d\n",position,prime);
}
