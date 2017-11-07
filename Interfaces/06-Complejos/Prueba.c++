#include <iostream>
#include <string>
#include "Complejo.h"
using namespace std;
/*
Complejo operator+ (Complejo c1, Complejo c2) {
  Complejo resultado;

  resultado.real = c1.real + c2.real;
  resultado.imag = c1.imag + c2.imag;

  return resultado;
}

Complejo operator- (Complejo c1, Complejo c2) {
  Complejo resultado;

  resultado.real = c1.real - c2.real;
  resultado.imag = c1.imag - c2.imag;

  return resultado;
}

Complejo operator- (Complejo c) {
  Complejo resultado;

  resultado.real = -c.real;
  resultado.real = -c.imag;

  return resultado;
}

Complejo operator++ (Complejo &c, int i) {
  Complejo temp = c;
  c.real++;
  c.imag++;
  return temp;
}
*/
int main (int argc, char * argv[]) {
  Complejo a(5,-8);
  Complejo b;
  Complejo c(4,0);
  Complejo d;
/*
  c.real = 5;
  c.imag = -8;

  a.real = 4;
  a.imag = 9;
*/
  b = a + c;

  cout << "El número c es " << c.imprimir() << endl;
  cout << "El número a es " << a.imprimir() << endl;
  cout << "La suma es " << (a - c).imprimir() << endl;
  cout << "El suma es " << b.imprimir() << endl;

  d = -a;
  cout << "El número d es " << d.imprimir() << endl;
  b = a++;
  cout << "El número a abans de l'increment es " << b.imprimir() << endl;
  cout << "El número a després de l'increment es " << a.imprimir() << endl;

  b = c + 5;
  cout << "El número es " << b.imprimir() << endl;
}
