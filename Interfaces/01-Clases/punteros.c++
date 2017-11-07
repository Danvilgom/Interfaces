#include <iostream>
using namespace std;

/*PUNTEROS*/
//Función para recoger un puntero
/*
void incrementar (int * p) {
  (*p)++;
}
*/

//Función que devuelve el máximo de dos números con punteros
/*
int * max (int * uno, int * dos) {
  if ((*uno) > (*dos)) {
    return uno;
  } else {
    return dos;
  }
}
*/

/*PUNTEROS Y REFERENCIA*/
//Función que devuelve el máximo de dos números con un puntero y una referencia
/*
int * max (int & uno, int * dos) {
  if (uno > (*dos)) {
    return &uno;
  } else {
    return dos;
  }
}
*/

/*REFERENCIA*/
//Función donde se le pasa la variable original (i) pero se recoge como una referencia (&n)
/*
void incrementar (int & n) {
  n++;
}
*/

//Función que devuelve el máximo de dos números con referencias
/*
int & max (int & uno, int & dos) {
  if (uno > dos) {
    return uno;
  } else {
    return dos;
  }
}
*/

int main(int argc, char *argv[]) {

  int i = 7;
  int j = 8;

  /*REFERENCIA*/
  //int &j = i; //&j es una referencia, es decir, otro nombre para una variable que ya existe
              /*Cuando se utiliza la referencia como argumento de una función, no se recibe
                una copia de la variable original, ya que la referencia es la misma variable
                pero con otro nombre distinto
               */

  //incrementar(i);   //Se pasa la variable original

  /*PUNTEROS*/
  //int * p;  //Declaración de una variable de tipo puntero que apuntará a un entero
            //p guarda la dirección de memoria de la variable i además de el tipo de variable, en este caso int

  //Queremos que p contenga la direccion de memoria de i
  //p = & i; //Se guarda el contenido de la dirección de memoria de la variable i en p

  //incrementar(&i);  //Se pasa la dirección de memoria de la variable i

  //Función max con dos punteros
  /*
  int * p;
  p = max (&j, &i);
  *p = 0;
  */

  //Función max con una referencia y un puntero
  /*
  int * p;
  p = max (j, &i);
  *p = 0;
  */

  //Función max con dos referencias
  /*
  int & m = max (j, i);
  m = 0;
  */

  cout << "Valor de i:  " << i << ". Valor de j: " << j << endl;

}
