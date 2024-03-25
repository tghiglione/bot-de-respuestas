#include "Herta.hpp"
#include <iostream>
#include <string>
#include <limits>


using namespace std;


int main() {
    const string INSTRUCCION_INGRESAR_MENSAJE = "Ingrese un mensaje para Hertha: ";
    const string INSTRUCCION_MENSAJE_SALIDA = "Ingrese 0 para finalizar chat con Herta, cualquier otro caracter/numero para continuar hablando: ";

    Herta herta;
    bool entrada = false;
    int numero_salida;
    string mensaje_ingresado;

    while(!entrada){
        cout << INSTRUCCION_INGRESAR_MENSAJE << endl;
        getline(cin, mensaje_ingresado);

        herta.responder(mensaje_ingresado);

        cout << INSTRUCCION_MENSAJE_SALIDA << endl;
        cin >> numero_salida;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');  //Para limpiar y evitar errores

        if(numero_salida == 0) {
            entrada = true;
        }
    }

    return 0;
}