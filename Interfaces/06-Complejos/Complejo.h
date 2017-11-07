#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Complejo {
public:
    float real;
    float imag;
    string imprimir();
    Complejo operator+ (Complejo c);
    Complejo operator- (Complejo c);
    Complejo operator- ();
    Complejo operator++ (int);

    Complejo();
    Complejo(float,float);
    Complejo(float);
};
