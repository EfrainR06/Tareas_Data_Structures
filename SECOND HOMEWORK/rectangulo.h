//Efrain Retana Segura UNA

#ifndef RECTANGULO_H
#define RECTANGULO_H
#include "punto.h"

typedef struct Rectangulo Rectangulo; //

//Funciones del ADT
Rectangulo* crear_rectangulo(Punto* supIzq, Punto* infDer);
void destruir_rectangulo(Rectangulo* r);
float area_rectangulo(Rectangulo* r);
float perimetro_rectangulo(Rectangulo* r);
int punto_en_rectangulo(Rectangulo* r, Punto* p); // 1 si está dentro, 0 si no

#endif //RECTANGULO_H
