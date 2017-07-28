import math
import time

count = 2
prime = [2,3]
number = 3
position = 100000
inicio = time.time()
while count < position:
    number+= 2
    isprime = True
    rootnumber = math.sqrt(number)
    for i in prime:
    	if(number%i==0):
    		isprime = False
    		break
    	if(rootnumber<=i):
    		break
    if(isprime):
    	prime.append(number)
    	count+= 1

fim = time.time()
print("Numero primo: %i na posicao: %i, com tempo: %.2f"%(position,prime[position-1],fim-inicio))
