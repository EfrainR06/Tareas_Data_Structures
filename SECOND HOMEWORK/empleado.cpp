//Efrain Retana Segura UNA

#include "empleado.h"

#include <iterator>
#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

Empleado *crear_empleado(const char *nombre, int id, float salario) {
    Empleado* e = (Empleado*)malloc(sizeof(Empleado));
    if (e) {
        strncpy(e->nombre, nombre, 49);
        e->nombre[49] = '\0';
        e->id = id;
        e->salario = salario;
    }
    return e;
}

void imprimir_empleado(const Empleado *e) {
    if (e)
        printf("Nombre: %s, ID: %d, Salario: %.2f\n", e->nombre, e->id, e->salario);
}
void aumentar_salario(Empleado *e, float incremento) {
    if (e)
        e->salario += incremento;
}

int comparar_empleado_salario(const Empleado *e1, const Empleado* e2) {
    if (!e1 || !e2) return 0;
    if (e1->salario == e2->salario) return 0;
    return(e1->salario > e2->salario) ? 1 : -1;
 }


