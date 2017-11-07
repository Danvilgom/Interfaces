#include <string>
using namespace std;

class Cuenta {
public:
    string titular;
    string numCuenta;
    float saldo;

    Cuenta();

    Cuenta(string tit, string numC, float s);

    void ingresar (float cantidad);

    bool retirar(float cantidad);

};
