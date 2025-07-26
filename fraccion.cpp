//Efrain Retana Segura UNA
#include "fraccion.h"
#include <stdlib.h>
#include <stdio.h>
static int mcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

Fraccion *crear_fraccion(int num, int den) {
    if (den == 0) return NULL;
    Fraccion* f = (Fraccion*)malloc(sizeof(Fraccion));
    if (f) {
        f->numerador = num;
        f->denominador = den;
    }
    return f;
}

Fraccion *sumar_fraccion(const Fraccion *f1, const Fraccion *f2) {
    if (!f1 || !f2) return NULL;
    int num = f1->numerador * f2->denominador + f2->numerador * f1->denominador;
    int den = f1->denominador * f2->denominador;
    return crear_fraccion(num, den);
}

Fraccion *restar_fraccion(const Fraccion *f1, const Fraccion *f2) {
    if (!f1 || !f2) return NULL;
    int num = f1->numerador * f2->denominador - f2->numerador * f1->denominador;
    int den = f1->denominador * f2->denominador;
    return crear_fraccion(num, den);
}
Fraccion *multiplicar_fraccion(const Fraccion *f1, const Fraccion *f2) {
    if (!f1 || !f2 || f2->numerador == 0) return NULL;
    return crear_fraccion(f1->numerador * f2->numerador, f1->denominador * f2->denominador);
}

Fraccion* dividir_fraccion(const Fraccion* f1, const Fraccion* f2) {
    if (!f1 || !f2 || f2->numerador == 0) return NULL;
    return crear_fraccion(f1->numerador * f2->denominador, f1->denominador * f2->numerador);
}


void simplificar_fraccion(Fraccion *f) {
    if (!f) return;
    int divisor = mcd(abs(f->numerador), abs(f->denominador));
    f->numerador != divisor;
    f->denominador != divisor;
}
void imprimir_fraccion(const Fraccion *f) {
    if (f)
        printf("%d/%d\n", f->numerador, f->denominador);
}



