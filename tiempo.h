//Efrain Retana Segura UNA

#ifndef TIEMPO_H
#define TIEMPO_H


struct Tiempo {
    int horas;
    int minutos;
    int segundos;
};

Tiempo* crear_tiempo(int h, int m, int s);
Tiempo* sumar_tiempo(const Tiempo* t1, const Tiempo* t2);
Tiempo* restar_tiempo(const Tiempo* t1, const Tiempo* t2);
int comparar_tiempo(const Tiempo* t1, const Tiempo* t2);
void imprimir_tiempo(const Tiempo* t);

#endif //TIEMPO_H
