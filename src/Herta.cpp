#include "Herta.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

Herta::Herta(){
    this->respuesta_automatica = "[Respuesta automatica] Hola. En este momento no estoy disponible, y no me pondre en contacto contigo mas tarde.";
    this->respuesta_hola = "Hola.";
    this->respuesta_problema = "No te preocupes. Ya esta solucionado.";
    this->respuesta_preocupado = "De que te preocupas si yo estoy aqui?";
    this->respuesta_simulado = "La actualizacion del Universo Simulado ya esta lista, ven a probarla.";
    this->respuesta_eres_herta = "Quieres una selfie para demostrartelo o que?";
    this->respuesta_marioneta = "Vaya, parece que la perdi. No me extrania que no la encuentre.";
    this->respuesta_kuru_1 = "KURU";
    this->respuesta_kuru_2 = "KURU KURU";
    this->respuesta_kuru_3 = "KURURIN";
    this->respuesta_ninguna_anterior_1 = "Oh.";
    this->respuesta_ninguna_anterior_2 = "...";
    this->numero_de_pregunta = 0;

}

int numero_random(int cantidad_de_numeros_posibles){

    /* Ingresa un entero que sera el intervalo de numeros random y devuelve un numero random en ese intervalo */

    static bool semilla_inicializada = false;

    if (!semilla_inicializada) {
        srand(static_cast<unsigned int>(time(nullptr)));
        semilla_inicializada = true;
    }

    int numero_random = rand() % cantidad_de_numeros_posibles + 1;
    return numero_random;
}

void cadena_a_minusculas(string &cadena){ 

    /* Ingresa una cadena de texto y la pasa a minuscula  */

    for (char &c: cadena) {
        c = static_cast<char>(std::tolower(c));
    }
};

void imprimir_mensaje(string mensaje_para_imprimir){

    /* Ingresa un mensaje y lo imprime por pantalla */

    cout << mensaje_para_imprimir << endl;
};

void Herta::responder(std::string mensaje) {

    if(numero_de_pregunta == 0 || numero_de_pregunta > 5){
        imprimir_mensaje(respuesta_automatica);
    }else{
        string respuesta_manual_herta = gestor_de_mensajes_manuales(mensaje);
        imprimir_mensaje(respuesta_manual_herta);
    }
    numero_de_pregunta++;
};

string Herta::gestor_de_mensajes_manuales(std::string mensaje) {

    /* Se ingresa por parametro el mensaje y devuelve por pantalla la respuesta manual*/

    string contiene_kuru = "kuru";
    string contiene_kururin = "kururin";
    string contiene_hola = "hola";
    string contiene_problema = "problema";
    string contiene_preocupado = "preocupado";
    string contiene_preocupada = "preocupada";
    string contiene_simulado = "simulado";
    string cadena_eres_herta = "eres herta?";
    string cadena_y_tu_marioneta = "y tu marioneta?";

    string mensaje_de_respuesta;

    cadena_a_minusculas(mensaje);

    if(mensaje.contains(contiene_kuru) || mensaje.contains(contiene_kururin)){
        int numero_random_para_respuesta = numero_random(3);
        mensaje_de_respuesta = respuesta_mensaje_kuru(numero_random_para_respuesta);
    }else if(mensaje.contains(contiene_hola)){
        mensaje_de_respuesta = respuesta_hola;
    }else if(mensaje.contains(contiene_problema)){
        mensaje_de_respuesta = respuesta_problema;
    }else if(mensaje.contains(contiene_preocupado) || mensaje.contains(contiene_preocupada)){
        mensaje_de_respuesta = respuesta_preocupado;
    }else if(mensaje.contains(contiene_simulado)){
        mensaje_de_respuesta = respuesta_simulado;
    }else if(mensaje == cadena_eres_herta){
        mensaje_de_respuesta = respuesta_eres_herta;
    }else if(mensaje == cadena_y_tu_marioneta){
        mensaje_de_respuesta = respuesta_marioneta;
    }else{
        int numero_random_para_respuesta = numero_random(2);
        mensaje_de_respuesta = respuesta_mensaje_ninguna_opcion(numero_random_para_respuesta);
    };

    return mensaje_de_respuesta;
};

string Herta::respuesta_mensaje_kuru(int numero_random){
    string mensaje_random_kuru;
    switch (numero_random) {
        case 1:
            mensaje_random_kuru = respuesta_kuru_1;
            break;
        case 2:
            mensaje_random_kuru = respuesta_kuru_2;
            break;
        case 3:
            mensaje_random_kuru = respuesta_kuru_3;
            break;
        default:
            mensaje_random_kuru = "Error";
    }
    return mensaje_random_kuru;
}

string Herta::respuesta_mensaje_ninguna_opcion(int numero_random) {
    string mensaje_ninguna_opcion;

    switch (numero_random) {
        case 1:
            mensaje_ninguna_opcion = respuesta_ninguna_anterior_1;
            break;
        case 2:
            mensaje_ninguna_opcion = respuesta_ninguna_anterior_2;
            break;
        default:
            mensaje_ninguna_opcion = "Error";
    }
    return mensaje_ninguna_opcion;
};


