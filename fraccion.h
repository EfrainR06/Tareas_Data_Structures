//Efrain Retana Segura UNA

#ifndef FRACCION_H
#define FRACCION_H

struct Fraccion {
    int numerador;
    int denominador;
};

Fraccion* crear_fraccion(int num, int den);
Fraccion* sumar_fraccion(const Fraccion* f1, const Fraccion* f2);
Fraccion* restar_fraccion(const Fraccion* f1, const Fraccion* f2);
Fraccion* multiplicar_fraccion(const Fraccion* f1, const Fraccion* f2);
Fraccion* dividir_fraccion(const Fraccion* f1, const Fraccion* f2);
void simplificar_fraccion(Fraccion* f);
void imprimir_fraccion(const Fraccion* f);
#endif //FRACCION_H
