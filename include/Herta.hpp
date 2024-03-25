#ifndef TP1_1C2024_HERTA_HPP
#define TP1_1C2024_HERTA_HPP

#include <string>

using namespace std;

class Herta {
private:
    string respuesta_automatica;
    string respuesta_hola;
    string respuesta_problema;
    string respuesta_preocupado;
    string respuesta_simulado;
    string respuesta_eres_herta;
    string respuesta_marioneta;
    string respuesta_kuru_1;
    string respuesta_kuru_2;
    string respuesta_kuru_3;
    string respuesta_ninguna_anterior_1;
    string respuesta_ninguna_anterior_2;
    int numero_de_pregunta;

    string respuesta_mensaje_kuru(int numero_random);

    string respuesta_mensaje_ninguna_opcion(int numero_random);

public:
    Herta();

    void responder(string mensaje);
};

#endif