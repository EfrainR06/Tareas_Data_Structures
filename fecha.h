//Efrain Retana Segura UNA
#ifndef FECHA_H
#define FECHA_H

struct Fecha {
    int dia;
    int mes;
    int anio;
};

Fecha* crear_fecha(int dia, int mes, int anio);
void imprimir_fecha(const Fecha* f);
int comparar_fecha(const Fecha* f1, const Fecha* f2);

#endif //FECHA_H
