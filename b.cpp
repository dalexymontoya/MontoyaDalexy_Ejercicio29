#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

/*
Programa para simular la ecuacion de difusion Dt(T)=a D2x(T) + s. Se varia dt,
manteniendo fijo N. Se simulara en t=0:1 y x=-1:1
*/

#define a 1.0
#define s 1.0
#define tmax 1.0

int main() {
  int N = 30;
  float h = 2.0 / N;

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

  float dt = 1e-4;

  while (dt < 3e-3) {
    for (int i = 0; i < N; i++)  // inicializa todo en ceros por si acaso.
    {
      t = 0.0;
      T[i] = 0.0;
      Tfut[i] = 0.0;
      for (int j = 0; j < N; j++) {
        G[i][j] = 0.0;
      }
    }
    for (int i = 1; i < N - 1; i++) {
      G[i][i] = 1 - 2 * a * dt / (h * h);
      G[i][i - 1] = a * dt / (h * h);
      G[i][i + 1] = a * dt / (h * h);
    }
    while (t < tmax) {
      for (int i = 0; i < N; i++) {
        float suma = 0.0;
        for (int j = 0; j < N; j++) {
          suma += G[i][j] * T[j];
        }
        Tfut[i] = suma + dt * s;
      }

      for (int i = 0; i < N; i++) {
        T[i] = Tfut[i];
      }
      t += dt;
    }
    for (int i = 0; i < N; i++) {
      cout << T[i] << "\t";
    }
    cout << endl;
    dt += 1e-5;
  }

  return 0;
}
