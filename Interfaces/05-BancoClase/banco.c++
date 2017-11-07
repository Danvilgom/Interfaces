#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
//#include "Cuenta.cpp"
#include "Cuenta.h"

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

Cuenta * seleccionarCuenta(vector<Cuenta> & cuentas) {
  string cuentaSeleccionada;
  cout << "\nIntroduzca el número de la cuenta que quiere seleccionar: " << endl;
  cin >> cuentaSeleccionada;

  for (int i = 0; i < cuentas.size(); i++) {
    if (cuentas[i].numCuenta == cuentaSeleccionada) {
      cout << "\nHa seleccionado la cuenta " << cuentas[i].numCuenta;
      return &cuentas[i];
    }
  }
  //cout << "\nLa cuenta " << cuentaSeleccionada << " no existe." << endl;
  return NULL;
}

void ingresar(Cuenta * c) {
  float cantidad;
  cout << "Introduzca la cantidad que desea ingresar: " << endl;
  cin >> cantidad;
  (*c).ingresar(cantidad);
}

// Este método se deja como está después de pasarlo todo a Objeto Cuenta que se comporta como un vector
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

bool borrarCuenta(vector<Cuenta> & cuentas) {
  string cuentaSeleccionada;
  cout << "\nIntroduzca el número de la cuenta que quiere borrar: " << endl;
  cin >> cuentaSeleccionada;

  vector<Cuenta>::iterator it;  //iterator es una especie de puntero que apunta a un objeto

  it = cuentas.begin();

  while (it != cuentas.end()) {
    if (it->numCuenta == cuentaSeleccionada) {
      cuentas.erase(it);
      return true;
    }
    it++;
  }
  return false;


  //cout << "\nLa cuenta " << cuentaSeleccionada << " no existe." << endl;
}


void inicializarCuentas(vector<Cuenta> * cuentas) {


  for (int i = 0; i < 5; i++) {
    stringstream sss;  //Clase para concatenar
    sss << 100+i;
    string srt = sss.str();
    string nombre = sss.str();

    stringstream ss;
    ss << 100 + i;
    string numCuenta = ss.str();

    cuentas->push_back(Cuenta(nombre, numCuenta, i*1000));
  }
}

void mostrarCuentas(vector<Cuenta> cuentas) {
  cout << "Titular\t";
  for (int i=0 ; i < cuentas.size(); i++) cout << "\t" << cuentas[i].titular;
  cout << endl << "NumCuenta";
  for (int i=0 ; i < cuentas.size(); i++) cout << "\t" << cuentas[i].numCuenta;
  cout << endl << "Saldo\t";
  for (int i=0 ; i < cuentas.size(); i++) cout << "\t" << cuentas[i].saldo;
}

int main(int argc, char *argv[]) {

  char option;

  vector<Cuenta> cuentas;

  Cuenta * cuentaSeleccionada = NULL;

  string nombres[10] = {"Nacho", "Esther", "Andres", "Javi", "Luis", "Martin", "Christian", "Jose", "Jorge", "Victor"};

  inicializarCuentas(&cuentas);
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
                if(borrarCuenta(cuentas)) {
                  cuentaSeleccionada = NULL;
                } else {
                  cout << "No se ha podido borrar la cuenta" << endl;
                }
        break;
      case '6': exit(0);
    }

    cout << "\nPulse una letra o un número + Intro para seguir: " << endl;
    cin >> option;
  }

}
