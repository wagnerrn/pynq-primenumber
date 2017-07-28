import time
from pynq import Overlay
from pynq import MMIO
ol = Overlay("numeroprimo.bit")
ol.download()
numeroprimo_ip = MMIO(0X43C00000, 0X10000)
numeroprimo_ip.write(0x10,100000)
numeroprimo_ip.write(0x00,1)
count=0
inicio = time.time()
while(numeroprimo_ip.read(0x00)!=4):
    # Esperando Conclusao do calculo
    if(count==0):
        count+=1
        print("Calculando...")
    # count+=1
fim = time.time()
print("Pronto! Status: %i, Loops: %i, Tempo: %.3fs"%(numeroprimo_ip.read(0x00),count,fim-inicio))
print("Numero primo na posicao %i eh %i"%(numeroprimo_ip.read(0x10),numeroprimo_ip.read(0x18)))
