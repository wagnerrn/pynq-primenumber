#include <math.h>
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <ctime>

void numeroPrimo(int posicao, int *primo) {
	int contador = 2;
	int numero = 3;
	bool ehprimo;
	int primos[100000];
	int raiznumero;
	int i;
	primos[0] = 2;
	primos[1] = 3;
	while (contador < posicao){
		numero += 2;
		ehprimo = true;
		raiznumero = sqrt(numero);
		for(i=0; i < contador; i++) {
			if(numero%primos[i] == 0) {
				ehprimo = false;
				break;
			}
			if(i >= raiznumero) {
				break;
			}
		}
		if(ehprimo){
			primos[contador] = numero;
			*primo = numero;
			contador += 1;
		}
	}  
}

int main() {
	int posicao = 100000;
	int primo;
	
	double duration;
	std::clock_t start;
	start = std::clock();

	numeroPrimo(posicao, &primo);

	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

	std::cout<<"Time: "<< duration  << "s" <<'\n';

	printf("Numero Primo: %d, na posicao %d\n",primo,posicao);
}
