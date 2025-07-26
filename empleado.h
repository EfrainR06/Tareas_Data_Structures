//Efrain Retana Segura UNA

#ifndef EMPLEADO_H
#define EMPLEADO_H


struct Empleado {
    char nombre[50];
    int id;
    float salario;
};

Empleado* crear_empleado(const char* nombre, int id, float salario);
void imprimir_empleado(const Empleado* e);
void aumentar_salario(Empleado* e, float incremento);
int comparar_empleado_salario(const Empleado* e1, const Empleado* e2); // returns -1, 0, 1


#endif //EMPLEADO_H
