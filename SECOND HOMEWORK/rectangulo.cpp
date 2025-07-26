#include <stdlib.h>
#include "rectangulo.h"

struct Rectangulo {
    Punto* supIzq;
    Punto* infDer;
};

Rectangulo* crear_rectangulo(Punto* supIzq, Punto* infDer) {
    Rectangulo* nuevo = (Rectangulo*)malloc(sizeof(Rectangulo));
    if (nuevo != NULL) {
        nuevo->supIzq = supIzq;
        nuevo->infDer = infDer;
    }
    return nuevo;
}

void destruir_rectangulo(Rectangulo* r) {
    // No destruimos los puntos aquí si los crea el main (opcional)
    free(r);
}

float area_rectangulo(Rectangulo* r) {
    float base = obtener_x(r->infDer) - obtener_x(r->supIzq);
    float altura = obtener_y(r->supIzq) - obtener_y(r->infDer);
    if (base < 0) base = -base;
    if (altura < 0) altura = -altura;
    return base * altura;
}

float perimetro_rectangulo(Rectangulo* r) {
    float base = obtener_x(r->infDer) - obtener_x(r->supIzq);
    float altura = obtener_y(r->supIzq) - obtener_y(r->infDer);
    if (base < 0) base = -base;
    if (altura < 0) altura = -altura;
    return 2 * (base + altura);
}

int punto_en_rectangulo(Rectangulo* r, Punto* p) {
    float x = obtener_x(p);
    float y = obtener_y(p);
    return (x >= obtener_x(r->supIzq) && x <= obtener_x(r->infDer) &&
            y <= obtener_y(r->supIzq) && y >= obtener_y(r->infDer));
}
