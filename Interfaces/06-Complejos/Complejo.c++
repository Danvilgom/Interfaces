#include <iostream>
#include <sstream>
#include "Complejo.h"
using namespace std;

Complejo::Complejo() : Complejo(0,0) {}

Complejo::Complejo(float r, float i) {
  real = r;
  imag = i;
}

Complejo::Complejo(float r) : Complejo(r,0) {}

string Complejo::imprimir() {

  stringstream sss;
  sss << "(" << real << " + " << imag << "i" << ")";
  return sss.str();

}

Complejo Complejo::operator+ (Complejo c) {
  Complejo resultado;

  resultado.real = real + c.real;
  resultado.imag = imag + c.imag;

  return resultado;
}

Complejo Complejo::operator- (Complejo c) {
  Complejo resultado;

  resultado.real = real - c.real;
  resultado.imag = imag - c.imag;

  return resultado;
}

Complejo Complejo::operator- () {
  Complejo resultado;

  resultado.real = -real;
  resultado.imag = -imag;

  return resultado;
}

Complejo Complejo::operator++ (int) {
  Complejo temp = *this;

  real++;
  imag++;

  return temp;
}
