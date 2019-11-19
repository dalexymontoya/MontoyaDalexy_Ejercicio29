#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

/*
Programa para simular la ecuacion de difusion Dt(T)=a D2x(T) + s. Se varia N,
dejando dt fijo. Se simulara en t=0:1 y x=-1:1
*/

#define a 1.0   //constantes //
#define s 1.0
#define tmax 1.0

int main() {
  float dt = 0.0001;

  int N = 10;

  while (N < 200) {
    float h = 2.0 / N;  // porque si hay N bloques en la region (-1,1), cada
                        // bloque tiene 2/N de largo.

    float T[N];
    float Tfut[N];
    float G[N][N];
    float t = 0.0;

    for (int i = 0; i < N; i++)  // inicializa toda la matriz y vect en ceros por si acaso.
    {
      T[i] = 0.0;
      Tfut[i] = 0.0;
      for (int j = 0; j < N; j++) {
        G[i][j] = 0.0;
      }
    }

    // Definir los valores de la matriz G para que Tfut=G.T+dt*s.
    for (int i = 1; i < N - 1; i++) {
      G[i][i] = 1 - 2 * a * dt / (h * h);  //esta es la diagonal
      G[i][i - 1] = a * dt / (h * h);    //atras
      G[i][i + 1] = a * dt / (h * h);    //adelante
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

    cout << N << "\t" << *max_element(T,T+sizeof(T)/sizeof(T[0])) << endl;
    N+=5;
  }
  
  return 0;
}
