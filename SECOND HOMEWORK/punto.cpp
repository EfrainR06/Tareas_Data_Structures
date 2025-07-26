//Efrain Retana Segura
#include <stdlib.h>
#include <math.h>
#include "punto.h"
struct Punto {
    float x;
    float y;
};
Punto *crear_punto(float x, float y) {
    Punto* nuevo = (Punto*)malloc(sizeof(Punto));
    if (nuevo != NULL) {
        nuevo -> x = x;
        nuevo -> y = y;
    }
    return nuevo;
}

void destruir_punto(Punto *p) {
    free(p);
}
float obtener_x(Punto* p) {
    return p->x;
}
float obtener_y(Punto* p) {
    return p->y;
}
void establecer_x(Punto *p, float x) {
    p->x = x;
}
void establecer_y(Punto *p, float y) {
    p->y = y;
}
float distancia(Punto* p1, Punto* p2) {
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}



