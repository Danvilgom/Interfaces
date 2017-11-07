#include <iostream>
using namespace std;

class Cuenta {
public:
    string titular;
    string numCuenta;
    float saldo;
/*
  void ingresar(float cantidad) {
    saldo += cantidad;
  }
*/

  bool retirar(float cantidad) {  //bool es boolean
    if (saldo >= cantidad) {  //Quan sols hi ha una instrucció dins del bucle no es necessari posar claus
      saldo -= cantidad;
      return true;
    } else {
      return false;
    }
  }

private:
    float interes;
};

/*PUNTEROS*/
//Función reintegrar con puntero
void reintegrar(Cuenta * cuen) {

  float cantidad;
  cout << "Introduce una cantidad a retirar: ";
  cin >> cantidad;

  //Extraer dinero
  if (cuen-> retirar(cantidad)) {
    cout << "Se han retirado " << cantidad << " euros. Saldo: " << (*cuen).saldo <<endl;
  } else {
    cout << "No se han podido retirar " << cantidad << " euros. Saldo: " << (*cuen).saldo <<endl;
  }
}

int main(int argc, char *argv[]) {

cout << "bienvenido al banco" <<endl;
/*
    Cuenta c;
    c.titular = "pepe";
    c.numCuenta ="001";
    c.saldo = 0 ;

    cout << "La cuenta " << c.numCuenta << " de " << c.titular
        << " tiene " << c.saldo << " euros " <<endl;
*/
  Cuenta c2;
	Cuenta * p;  //Crear puntero Cuenta
	//c2 = c;

  p = & c2;  //Se guarda el contenido de la dirección de memoria de c2 en p
	c2.saldo = 500;

	//cout << " c.saldo " << c.saldo <<endl;
	cout << " c2.saldo " << c2.saldo <<endl;

	//Ingresar dinero
  /*
  c.ingresar(1000);
  cout << "Se han ingresado 1000 euros. Saldo " << c.saldo <<endl;
  */

  //c = retirar(c);
  reintegrar(&c2);  //Se llama a la función reintegrar y se le pasa la dirección de memoria de c2
  /*
  cout << "La cuenta " << c.numCuenta << " de " << c.titular
      << " tiene " << c.saldo << " euros " <<endl;
  */
}
