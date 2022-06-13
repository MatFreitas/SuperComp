# -*- coding: utf-8 -*-

import subprocess
import time
import os
import sys
import matplotlib.pyplot as plt



def roda_com_entrada(executavel, arquivo_in):
    with open(arquivo_in) as f:
        start = time.perf_counter()
        proc = subprocess.run([sys.executable, executavel], input=f.read(), text=True, capture_output=True)
        end = time.perf_counter()

        # print('Saída:', proc.stdout)
        # print('Stderr:', proc.stderr)
        print('Tempo total(s):', end - start)

        return (proc.stdout, end - start)

tempos = []
tamanhos = []
for i in range(0, 10):
    with open(f'./entradas-busca-local/in-{i}.txt') as f:
        tamanhos.append(f.readline().strip())
    tempos.append(roda_com_entrada('./busca-local-1', f'./entradas-busca-local/in-{i}.txt')[1])

plt.plot(tempos, tamanhos)
plt.show()
