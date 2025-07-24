//Efrain Retana Segura UNA

#ifndef CIRCULO_H
#define CIRCULO_H

#include "punto.h"

typedef struct Circulo Circulo; //Declaración opaca

//Funciones del ADT Círculo

Circulo* crear_circulo(Punto* centro, float radio);
void destruir_circulo(Circulo* c);

float area_circulo(Circulo* c);
float perimetro_circulo(Circulo* c);
int punto_en_circulo(Circulo* c, Punto* p); // 1 si el punto está dentro, 0 si no

#endif //CIRCULO_H
