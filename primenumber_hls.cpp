void primeNumber(const int position, int *prime) {
	int counter = 2;
	int number = 3;
	bool isprime;
	int primes[100000];
	int root;
	int i;
	int j;

    int rnumber;
    int s;


	primes[0] = 2;
	primes[1] = 3;
	if (counter >= position) {
		*prime = primes[position-1];
	}
	for(j=0; j < 1000000; j++){
		number += 2;
		if(counter >= position){
			break;
		}
		isprime = true;

		rnumber = number;
		s = rnumber;

		for(i=0; i < 4; i++) {
			s = (s + rnumber / s) / 2;
		}

		root = s;

		for(i=0; i < 100000; i++) {
			if(i > counter) {
				break;
			}
			if(i >= root) {
				break;
			}
			if(number%primes[i] == 0) {
				isprime = false;
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
