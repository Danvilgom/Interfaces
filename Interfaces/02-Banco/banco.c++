#include <iostream>
#include <sstream>
using namespace std;

#define BORRARPANTALLA for (int i = 0; i < 40; i++) cout << endl;  //Macro

void menu(void){

   BORRARPANTALLA //Llamada a la Macro
   //Menú
   cout << "        1 - Elegir Cuenta " << endl;
   cout << "        2 - Ingresar " << endl;
   cout << "        3 - Reintegrar " << endl;
   cout << "        4 - Ver saldo " << endl;
   cout << "        5 - Salir a MSDOS " << endl;
   BORRARPANTALLA
}

class Cuenta {
public:
    string titular;
    string numCuenta;
    float saldo;

    void ingresar (float cantidad) {
      saldo += cantidad;
      cout << "\nSe han ingresado " << saldo << " euros" << " en la cuenta " << numCuenta << endl;
    }

    bool retirar(float cantidad) {
      if (cantidad > saldo) {
        return false;
      } else {
        saldo -= cantidad;
        return true;
      }
    }

};

int seleccionarCuenta(Cuenta cuentas[10]) {
  string cuentaSeleccionada;
  cout << "\nIntroduzca la posición de la cuenta que quiere seleccionar: " << endl;
  cin >> cuentaSeleccionada;
  for (int i = 0; i < 10; i++) {
    if (cuentas[i].numCuenta == cuentaSeleccionada) {
      cout << "Ha seleccionado la cuenta " << cuentas[i].numCuenta;
      return i;
    }
  }
  return -1;
}

void ingresar(Cuenta * c) {
  float cantidad;
  cout << "\nIntroduzca la cantidad que desea ingresar: " << endl;
  cin >> cantidad;
  (*c).ingresar(cantidad);
}

void reintegrar(Cuenta * c) {
  float cantidad;
  cout << "\nIntroduzca la cantidad que desea reintegrar: " << endl;
  cin >> cantidad;
  if (c -> retirar(cantidad)) {
    cout << "Se han retirado " << cantidad << " euros. Saldo: " << (*c).saldo << endl;
  } else {
    cout << "No se han podido retirar " << cantidad << " euros. Saldo: " << (*c).saldo << endl;
  }
}

void mostrarSaldo(Cuenta c) {
    cout <<  "Número de la cuenta: " << c.numCuenta << " Titular: " << c.titular
    << " Saldo: " << c.saldo << " euros" << endl;
}

void inicializarCuentas(Cuenta cuentas[10]) {
  for (int i=0 ; i < 5; i++) {
    stringstream ss;  //Clase para concatenar
    ss << 100+i;
    cuentas[i].numCuenta = ss.str();
    cuentas[i].saldo  = 0;

    stringstream sss;
    sss << i;
    string str = sss.str();
    cuentas[i].titular = "pepe" + str;
  }
}

void mostrarCuentas(Cuenta cuentas[10]) {
  cout << "Titular\t";
  for (int i=0 ; i < 5; i++) cout << "\t" << cuentas[i].titular;
  cout << endl << "NumCuenta";
  for (int i=0 ; i < 5; i++) cout << "\t" << cuentas[i].numCuenta;
  cout << endl << "Saldo\t";
  for (int i=0 ; i < 5; i++) cout << "\t" << cuentas[i].saldo;
}

int main(int argc, char *argv[]) {

  char option;
  int cuentaSeleccionada = -1;

  //Declaración de punteros vectores
  string nombres[10] = {"Alejandro", "Esther", "Andres", "Javi", "Luis", "Martin", "Christian", "Jose", "Jorge", "Victor"};
  Cuenta cuentas[10];

  inicializarCuentas(cuentas);
  mostrarCuentas(cuentas);

  while (true) {
    menu(); //Llamada al menú
    cin >> option;  //Entrada del teclado
    switch (option) {
      case '1': cout << "Has elegido la opción de elegir cuenta." << endl;
                cuentaSeleccionada = seleccionarCuenta(cuentas);
        break;
      case '2': if (cuentaSeleccionada != -1) {
                  ingresar(& cuentas[cuentaSeleccionada]);
                }
        break;
      case '3': if (cuentaSeleccionada != -1) {
                  reintegrar(& cuentas[cuentaSeleccionada]);
                }
        break;
      case '4': mostrarSaldo(cuentas[cuentaSeleccionada]);
        break;
      case '5': exit(0);
    }

    cout << "\nPulse una letra o un número + Intro para seguir: " << endl;
    cin >> option;
  }

}
