#include <iostream>
#include <sstream>
using namespace std;

#define BORRARPANTALLA for (int i = 0; i < 5; i++) cout << endl;  //Macro

void menu(void){

   BORRARPANTALLA //Llamada a la Macro
   //Menú
   cout << "        1 - Elegir Cuenta " << endl;
   cout << "        2 - Ingresar " << endl;
   cout << "        3 - Reintegrar " << endl;
   cout << "        4 - Ver saldo " << endl;
   cout << "        5 - Borrar cuenta" << endl;
   cout << "        6 - Salir a MSDOS " << endl;
   BORRARPANTALLA
}

class Cuenta {
public:
    string titular;
    string numCuenta;
    float saldo;

    Cuenta(string tit, string numC, float s) {
      titular = tit;
      numCuenta = numC;
      saldo = s;
    }

    Cuenta() {
    }

    void ingresar (float cantidad) {
      saldo += cantidad;
      cout << "\nSe han ingresado " << cantidad << " euros" << " en la cuenta " << numCuenta <<  ". Saldo: " << saldo << endl;
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

Cuenta * seleccionarCuenta(Cuenta * cuentas[10]) {
  string cuentaSeleccionada;
  cout << "\nIntroduzca el número de la cuenta que quiere seleccionar: " << endl;
  cin >> cuentaSeleccionada;
  for (int i = 0; i < 10; i++) {
    if (cuentas[i] != NULL && cuentas[i] -> numCuenta == cuentaSeleccionada) {
      cout << "\nHa seleccionado la cuenta " << cuentas[i] -> numCuenta;
      return cuentas[i];
    }
  }
  cout << "\nLa cuenta " << cuentaSeleccionada << " no existe." << endl;
  return NULL;
}

void ingresar(Cuenta * c) {
  float cantidad;
  cout << "Introduzca la cantidad que desea ingresar: " << endl;
  cin >> cantidad;
  (*c).ingresar(cantidad);
}

void reintegrar(Cuenta * c) {
  float cantidad;
  cout << "Introduzca la cantidad que desea reintegrar: " << endl;
  cin >> cantidad;
  if (c -> retirar(cantidad)) {
    cout << "Se han retirado " << cantidad << " euros de la cuenta " << (*c).numCuenta << ". Saldo: " << (*c).saldo << endl;
  } else {
    cout << "No se han podido retirar " << cantidad << " euros de la cuenta " << (*c).numCuenta << ".  Saldo: " << (*c).saldo << endl;
  }
}

void mostrarSaldo(Cuenta * c) {
    cout <<  "Número de la cuenta: " << (*c).numCuenta << " Titular: " << (*c).titular
    << " Saldo: " << (*c).saldo << " euros" << endl;
}

void borrarCuenta(Cuenta * cuentas[10]) {
  string cuentaSeleccionada;
  cout << "\nIntroduzca el número de la cuenta que quiere borrar: " << endl;
  cin >> cuentaSeleccionada;
  for (int i = 0; i < 10; i++) {
    if (cuentas[i] != NULL && cuentas[i] -> numCuenta == cuentaSeleccionada) {
      cout << "\nSe ha borrado la cuenta " << cuentas[i] -> numCuenta;
      delete cuentas[i];
      cuentas[i] = NULL;
    }
  }
  cout << "\nLa cuenta " << cuentaSeleccionada << " no existe." << endl;
}

void inicializarCuentas(Cuenta * cuentas[10]) {
  string nombres[10] = {"Nacho", "Esther", "Andres", "Javi", "Luis", "Martin", "Christian", "Jose", "Jorge", "Victor"};

  for (int i = 0; i < 5; i++) {
    stringstream ss;  //Clase para concatenar
    ss << 100+i;
    cuentas[i] = new Cuenta(nombres[i], ss.str(), i*1000);
  }
}

void mostrarCuentas(Cuenta * cuentas[10]) {
  cout << "Titular\t";
  for (int i=0 ; i < 5; i++) cout << "\t" << cuentas[i] -> titular;
  cout << endl << "NumCuenta";
  for (int i=0 ; i < 5; i++) cout << "\t" << cuentas[i] -> numCuenta;
  cout << endl << "Saldo\t";
  for (int i=0 ; i < 5; i++) cout << "\t" << cuentas[i] -> saldo;
}

int main(int argc, char *argv[]) {

  char option;
  //Declaración de punteros vectores
  Cuenta * cuentas[10];
  for (int i = 0; i < 10; i++) {
    cuentas[i] = NULL;
  }

  Cuenta * cuentaSeleccionada = NULL;

  inicializarCuentas(cuentas);
  mostrarCuentas(cuentas);

  while (true) {
    menu(); //Llamada al menú
    cin >> option;  //Entrada del teclado
    switch (option) {
      case '1': cout << "Ha elegido la opción de elegir cuenta." << endl;
                cuentaSeleccionada = seleccionarCuenta(cuentas);
        break;
      case '2': if (cuentaSeleccionada != NULL) {
                  ingresar(cuentaSeleccionada);
                }
        break;
      case '3': if (cuentaSeleccionada != NULL) {
                  reintegrar(cuentaSeleccionada);
                }
        break;
      case '4': if (cuentaSeleccionada != NULL) {
                  mostrarSaldo(cuentaSeleccionada);
                }
        break;
      case '5': cout << "Ha elegido la opción de elegir cuenta." << endl;
                borrarCuenta(cuentas);
                cuentaSeleccionada = NULL;
        break;
      case '6': exit(0);
    }

    cout << "\nPulse una letra o un número + Intro para seguir: " << endl;
    cin >> option;
  }

}
