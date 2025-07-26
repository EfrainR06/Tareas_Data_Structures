//Efrain Retana Segura UNA
#include <stdlib.h>
#include <math.h>
#include "Circulo.h"

struct Circulo {
    Punto* centro;
    float radio;
};

Circulo *crear_circulo(Punto *centro, float radio) {
    Circulo* nuevo = (Circulo*)malloc(sizeof(Circulo));
    if (nuevo != NULL) {
        nuevo->centro = centro;
        nuevo->radio = radio;
    }
    return nuevo;
}

void destruir_circulo(Circulo *c) {
    free(c); // El centro se destruye desde fuera si fue creado aparte
}

float area_circulo(Circulo *c) {
    return M_PI * c->radio * c->radio;
}
float perimetro_circulo(Circulo *c) {
    return 2 * M_PI * c->radio;
}

int punto_en_circulo(Circulo *c, Punto *p) {
    float d = distancia(c->centro, p);
    return(d <= c->radio);
}


