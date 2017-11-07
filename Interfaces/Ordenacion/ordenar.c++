#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

void inicializar (vector<int> & numeros, int cant){
  for (int i = 0 ; i< cant; i++)
      numeros.push_back(rand()%100);
}

void mostrar(vector<int> numeros) { // just for efficiency
  for (int i = 0 ; i< numeros.size(); i++)
      cout << numeros.at(i) <<"  ";
  cout  << endl;
}

int minimo(vector<int> numeros, int n) {
  int p = n;  //SIEMPRE SE INICIALIZAN LAS VARIABLES

  for (int i = n; i < numeros.size(); i++) {
/* Se compara el valor de cada posición del vector con
   el valor de la posición que contiene el valor mínimo */
    if (numeros[i] < numeros[p]) {
      p = i;
    }
  }
  return p;
}

//Método para intercambiar dos números por sus posiciones
void intercambiar(vector<int> & numeros, int p1, int p2) {
  int aux = numeros[p1];
  numeros[p1] = numeros[p2];
  numeros[p2] = aux;
}

//Método para ordenar el vector por numeros consecutivos en el vector
void burbuja(vector<int> & numeros){
  for(int i = 0; i < numeros.size(); i++) {
    for(int j = 0; j < numeros.size() - 1; j++) {
      if (numeros[j] > numeros[j+1]) {
        intercambiar(numeros, j, j+1);
      }
    }
  }
}

//Método para ordenar el vector guardando el mínimo de posición en posición
void seleccion(vector<int> & numeros) {
  for (int i = 0; i < numeros.size(); i++) {
    intercambiar(numeros, i, minimo(numeros,i));
  }
}

vector<int> merge(vector<int> & vectorUno, vector<int> & vectorDos) {
  vector<int> resultado;
  int indiceUno = 0;
  int indiceDos = 0;

  while ((indiceUno < vectorUno.size()) && (indiceDos < vectorDos.size())) {
    if (vectorUno[indiceUno] < vectorDos[indiceDos]) {
      resultado.push_back(vectorUno[indiceUno]);
      indiceUno++;
    } else {
      resultado.push_back(vectorDos[indiceDos]);
      indiceDos++;
    }
  }

  while (indiceUno < vectorUno.size()) {
    resultado.push_back(vectorUno[indiceUno]);
    indiceUno++;
  }

  while (indiceDos < vectorDos.size()) {
    resultado.push_back(vectorDos[indiceDos]);
    indiceDos++;
  }

  return resultado;
}

void mergeSort(vector<int> & numeros) {
  vector<int> mitadIzq, mitadDer;

  if (numeros.size() <= 1) return;
  //Solución 1
/*
  int mitadI = numeros.size()/2;

  for (int i = 0; i < mitadI; i++) {
    mitadIzq.push_back(numeros[i]);
  }

  for (int i = mitadI; i < numeros.size(); i++) {
    mitadDer.push_back(numeros[i]);
  }
*/

  //Solución 2
  int i = 0;
  while (i < numeros.size()) {
    if (i < numeros.size()/2) {
      mitadIzq.push_back(numeros[i]);
    } else {
      mitadDer.push_back(numeros[i]);
    }
    i++;
  }

  //Común para las dos soluciones
  mergeSort(mitadIzq);
  mergeSort(mitadDer);

  numeros = merge(mitadIzq, mitadDer);
}

void quickSort(vector<int> & numeros, int posIni, int posFin) {
  int izq = posIni;
  int der = posFin;

  if (posIni == posFin) return;

  int pivote = numeros[(posIni+posFin)/2];

  cout << "Valor de pivote: " << pivote << endl;

  while (izq < der) {

    while (numeros[izq] < pivote) {
      cout << "Valor de izq: " << numeros[izq] << endl;
      izq++;
    }

    while (numeros[der] > pivote) {
      cout << "Valor de der: " << numeros[der] << endl;
      der--;
    }

    if (izq <= der) {
      intercambiar(numeros, izq, der);
      mostrar(numeros);
      izq++;
      der--;
    }
  }
  cout << "Izq es " << izq << ", Der es " << der << endl;

  if (izq < posFin) {
    quickSort(numeros, izq, posFin);   //Ordenar la parte izquierda
  }
  if (der > posIni) {
    quickSort(numeros, posIni, der);   //Ordenar la parte derecha
  }
}

void heapSort (vector<int> & numeros) {
  int parent;
  int child;

  for (int nuevoNodo = 0; nuevoNodo < numeros.size(); nuevoNodo++) {
    child = nuevoNodo;

    if (child%2==0) {
      parent = (child-2)/2;
    } else {
      parent = (child-1)/2;
    }

    while (child != 0) {
      if (numeros[child] > numeros[parent]) {
        intercambiar(numeros, parent, child);
        child = parent;

        if (child%2==0) {
          parent = (child-2)/2;
        } else {
          parent = (child-1)/2;
        }
      } else break;
    }
    mostrar(numeros);
  }
}

int main(int argc, char *argv[]){
  //Declaración del primer vector
  vector<int> numeros;
  //Para hacer el merge se le pasan dos vectores, en este caso numeros y numeros2
  /*
  vector<int> numeros2;
  vector<int> resultadoMerge;
  */

  //Llenar el vector con 15 números
  inicializar(numeros,15);
  //inicializar(numeros2,2500);

  //Mostrar el primer vector
  cout << "Vector 1:" << endl;
  mostrar(numeros);

  //Mostrar el segundo vector
  /*
  cout << "Vector 2:" << endl;
  mostrar(numeros2);
  */

  //cout << "\nResultado:" << endl;

  //cout << "El valor mínimo es: " << numeros[minimo(numeros)] << endl;

  //Llamadas a los métodos de ordenación
  /*
  //intercambiar(numeros,2,4);
  burbuja(numeros);
  //seleccion(numeros);
  mostrar(numeros);
  */

  //Ordenación merge
  /*
  //Primero se ordenan los dos vectores por separado
  burbuja(numeros);
  burbuja(numeros2);

  //Después se unen ordenados en la función merge
  resultadoMerge = merge(numeros, numeros2);
  mostrar(resultadoMerge);
  */

  //Ordenación mergeSort
  /*
  mergeSort(numeros);
  mostrar(numeros);
  */

  //Oredanación quickSort
  /*
  quickSort(numeros, 0, numeros.size()-1);
  cout << "\nResultado:" << endl;
  mostrar(numeros);
  */

  //Ordenación heapSort
  heapSort(numeros);
  cout << "\nResultado:" << endl;
  mostrar(numeros);

  //Para medir el tiempo de ejecución
  /*
  clock_t t = clock();
  t = clock() -t ;
  float tiempo = (float) t/CLOCKS_PER_SEC;
  cout << "Ordenación por merge:" << endl;
  printf ("ID It took me %d clicks (%f seconds).\n",(int) t,tiempo);
  */
}
