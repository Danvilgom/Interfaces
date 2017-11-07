#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#include "Cuenta.h"

#define BORRARPANTALLA    for (int i=0; i<10 ; i++) cout << endl;


void menu(void){


   BORRARPANTALLA
   cout << "        1 - Elegir Cuenta " << endl;
   cout << "        2 - Ingresar " << endl;
   cout << "        3 - Reintegrar " << endl;
   cout << "        4 - Ver saldo " << endl;
   cout << "        b - Borrar Cuenta " << endl;
   cout << "        g - Agregar Cuentas " << endl;
   cout << "        5 - Salir a MSDOS " << endl;
   BORRARPANTALLA
}

void ingresar(Cuenta *c) {

	cout << "Has elegido ingresar. Escribe la cantidad" << endl;
	int cantidad;
	cin >> cantidad;
	(*c).ingresar(cantidad);

}

void reintegrar(Cuenta *c) {
	cout << "Has elegido reintegrar. Escribe la cantidad" << endl;
	int cantidad;
	cin >> cantidad;
	if (c->retirar(cantidad) )
		cout << "Todo Ok, dinero retirado"<< endl;
	else
		cout << "No hay bastante dinero" << endl;
}

void mostrarSaldo(Cuenta c) {
	cout << "Has elegido ver el Saldo" << endl;
	cout << "El saldo de la cuenta " << c.numCuenta << " es " << c.saldo <<endl;
}



void inicializarCuentas(vector<Cuenta> * cuentas) {

	for (int i=0 ; i < 6; i++) {
		// nombre
	    stringstream sss ;
	    sss << i;
	    string str = sss.str();
	    string nombre = "pepe" + str;

		//numCuenta
	    stringstream ss ;
	     ss << 100+i ;
	    string numCuenta = ss.str();

	      // el saldo. es siempre 0
	    if (i % 2 == 0)
	            cuentas->push_back(  Cuenta(nombre,numCuenta,0)) ;
	    else
		    cuentas->push_back(  Cuenta("juan",numCuenta,200)) ;
	 }

}
void mostrarCuentas(vector<Cuenta> cuentas) {

	cout << "Titular  ";
	for (int i=0 ; i < cuentas.size(); i++) cout <<"\t"<< cuentas[i].titular ;
	cout <<endl<< "numCuenta" ;
	for (int i=0 ; i < cuentas.size(); i++) cout <<"\t"<< cuentas[i].numCuenta ;
	cout <<endl<< "Saldo    " ;
	for (int i=0 ; i < cuentas.size(); i++) cout <<"\t"<< cuentas[i].saldo ;

   cout <<endl<< "Pulsa pa empezar"<< endl;

}

Cuenta * seleccionarCuenta(vector<Cuenta> & cuentas) {
	string cuentaSolicitada;
	cout <<"Escribe el número d ecuenta a seleccionar"<<endl;
	cin >> cuentaSolicitada;

	for (int i = 0 ; i < cuentas.size(); i++)
		if (cuentas[i].numCuenta == cuentaSolicitada )
			return & cuentas[i];

	return NULL;

}

void borrarCuenta(vector<Cuenta> & cuentas) {
	string cuentaSolicitada;
	cout <<"Escribe el número d ecuenta a borrar"<<endl;
	cin >> cuentaSolicitada;

	vector<Cuenta>::iterator it;

	it = cuentas.begin();

	while ( it != cuentas.end() ) {
		if (it->numCuenta == cuentaSolicitada )
			cuentas.erase(it);
		it++;
	}
	return;



}

/*Opción 1 borrar cuentas duplicadas*/
vector<Cuenta> operator<< (vector<Cuenta> cuentas, Cuenta c) {
  bool primeraVez = false;
  int primeraCuenta = -1;

  for (int i = 0; i < cuentas.size(); i++) {
    if (cuentas[i].titular == c.titular && primeraVez == true) {
      if (i == -1) {
        cerr << "Error" << endl;
        cuentas[primeraCuenta].ingresar(cuentas[i].saldo);
      }
    }

    if (cuentas[i].titular == c.titular && primeraVez == false) {
      primeraVez = true;
      primeraCuenta = 1;
    }
  }

  bool cuentaBorrada = true;
  while (cuentaBorrada) {
    cuentaBorrada = false;
    primeraVez = false;
    vector<Cuenta>::iterator it = cuentas.begin();

    while (it != cuentas.end()) {
      if (primeraVez == false && it -> titular == c.titular) {
        primeraVez = true;
      } else if (it -> titular == c.titular) {
          cuentas.erase(it);
          break;
      }
      it++;
    }
    return cuentas;
  }
}

/*Opción 2 borrar cuentas duplicadas
vector<Cuenta> operator<< (vector<Cuenta> cuentas, Cuenta c) {
  bool cuentaBorrada = false;
  vector<Cuenta>::iterator it;
  it = cuentas.begin();

  while (cuentaBorrada) {
    cuentaBorrada = false;
    while (it != cuentas.end()) {
      if (it -> titular == c.titular) {
        c.ingresar(it -> saldo);
        cuentas.erase(it);
        cuentaBorrada = true;
        break;
      }
      it++;
    }
  }
  return cuentas;
}
*/

int main(int argc, char *argv[]) {

	//int cuentaSeleccionada = -1;  // soy pesimista
	Cuenta * cuentaSeleccionada = NULL ; // null es pesimista

	char opcion;
	string nombres[10]= {"juan","perico","andres","fulano","sotano","vegano","juan","juan","juan","juan"};
	//Cuenta * cuentas[10];

	vector<Cuenta> cuentas;

	//  cuentas[5].ingresar(100); <- esto es correcto (no en esta línea)



	inicializarCuentas(&cuentas);

	mostrarCuentas(cuentas);
     cin >>opcion;

  while (true) {
	menu();
	cin >> opcion;

	switch (opcion) {
		case '1': cout << "Has elegido la opción de elegir una cuenta" << endl;
			  cuentaSeleccionada = seleccionarCuenta(cuentas);
			  break;

		case '2': if (cuentaSeleccionada != NULL )
				ingresar(cuentaSeleccionada );
			  break;

	        case '3': if (cuentaSeleccionada)
				reintegrar(cuentaSeleccionada);
			  break;

		case '4': if (cuentaSeleccionada )
				mostrarSaldo(*cuentaSeleccionada);
			  break;
		case 'g':
			// reune todas las cuentas del titular de la cuenta seleccionada
			// en la primera cuenta del titular dentro del vector, eliminando el resto de sus cuentas
			  cuentas = cuentas << *cuentaSeleccionada;  //*cuentaSeleccionada es lo apuntado

			  break;
		case 'b': borrarCuenta(cuentas);
			  break;
		case '5':
			  exit(0);
        mostrarCuentas(cuentas);
	} ;
	cout<< "pulsa una tecla pa seguir"<< endl ;
	cin >> opcion;
  }
}

Cuenta cuentas[10];
