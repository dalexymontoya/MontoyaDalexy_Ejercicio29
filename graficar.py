# encoding: utf-8
import numpy as np
import matplotlib.pyplot as plt
import sys  # para leer argumentos del comando. sys.argv es una lista con los comandos que se le pasan a python, en este caso el nombre del archivo a graficar.

nombre_archivo = sys.argv[1]
#Nombre del archivo de datos

plt.plot(np.genfromtxt(nombre_archivo))  # grafica de los datos

nombre_guardar = nombre_archivo[:-3] + "png"  # se le quita el "dat" o el "txt" al archivo de datos con el [:-3], y se le pega el png para que se guarde como imagen

plt.savefig(nombre_guardar)  # guarda el archivo
