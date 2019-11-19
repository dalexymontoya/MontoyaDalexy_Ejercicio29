#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

/*
Programa para simular la ecuacion de difusion Dt(T)=a D2x(T) + s. Entran como
parametros dt (float) y N (int). Se simulara en t=0:1 y x=-1:1
*/

#define a 1.0
#define s 1.0
#define tmax 1.0

int main(int argc, char *argv[]) {
  float dt = stof(argv[1]);  // lee el primer argumento y lo define como dt.
                             // "stof" significa "string to float", y onvierte
                             // el string que recibe el programa a float.

  int N = stoi(argv[2]);  // stoi significa "string to int".

  float h = 2.0 / N;  // porque si hay N bloques en la region (-1,1), cada  bloque tiene 2/N de largo.

  float T[N];
  float Tfut[N];
  float G[N][N];
  float t = 0.0;

  for (int i = 0; i < N; i++)  // inicializa todo en ceros por si acaso.
  {
    T[i] = 0.0;
    Tfut[i] = 0.0;
    for (int j = 0; j < N; j++) {
      G[i][j] = 0.0;
    }
  }

  // Definir los valores de la matriz G para que Tfut=G.T+dt*s.
  for (int i = 1; i < N - 1; i++) {
    G[i][i] = 1 - 2 * a * dt / (h * h);
    G[i][i - 1] = a * dt / (h * h);
    G[i][i + 1] = a * dt / (h * h);
  }

  while (t < tmax) {  // Simulacion
    for (int i = 0; i < N; i++) {
      float suma = 0.0;
      for (int j = 0; j < N; j++) {
        suma += G[i][j] * T[j];
      }
      Tfut[i] = suma + dt * s;
    }

    for (int i = 0; i < N; i++) {  // actualizar los arreglos
      T[i] = Tfut[i];
    }
    t += dt;
  }

  for (int i = 0; i < N; i++) {
    cout << T[i] << "\t";
  }
  cout << endl;

  return 0;
}
