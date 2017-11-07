#include <iostream>
#include <string>
#include "Cuenta.h"
using namespace std;

Cuenta::Cuenta() {}

Cuenta::Cuenta(string tit, string numC, float s) {
  titular = tit;
  numCuenta = numC;
  saldo = s;
}

void Cuenta::ingresar (float cantidad) {
  saldo += cantidad;
  cout << "\nSe han ingresado " << cantidad << " euros" << " en la cuenta " << numCuenta <<  ". Saldo: " << saldo << endl;
}

bool Cuenta::retirar(float cantidad) {
  if (cantidad > saldo) {
    return false;
  } else {
    saldo -= cantidad;
    return true;
  }
}
