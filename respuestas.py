# encoding: utf-8
import numpy as np
import matplotlib.pyplot as plt

print("\n\nPunto (a):")
print(
    "Se hizo un barrido con dt desde 1e-4 hasta 1e-3, y el maximo valor estable visto en las graficas es de dt es 8e-4\n\n"
)

print("Punto (b): error_dt.png")
data = np.genfromtxt("b.dat")
maximos = [max(data[i]) for i in range(len(data))]
maximos = np.array(maximos)
error = (maximos - min(maximos)) / min(
    maximos) * 100  # el error porcentual se saca con el valor para menor dt
plt.plot(np.arange(1e-4, 3e-3, 1e-5), error)
plt.ylim([0, 1])
plt.xlabel("dt")
plt.ylabel("Error porcentual")
plt.savefig("error_dt.png")

print("Punto (c): error_N.png")
n, maximos = np.genfromtxt("c.dat").T
plt.figure()
plt.plot(n,
         abs(maximos - max(maximos)) / max(maximos) *
         100)  #el error porcentual se saca con el valor para maximo N
plt.xlabel("N")
plt.ylabel("Error porcentual")
plt.savefig("error_N.png")
