//Efrain Retana Segura UNA

#include <stdio.h>
#include <stdlib.h>
#include "punto.h"
#include "rectangulo.h"
#include "Circulo.h"
#include "fecha.h"
#include "fraccion.h"
#include "tiempo.h"
#include "vector3d.h"
#include "recta.h"
#include "empleado.h"

//Ejercicio documento 0.1
// int main() {
//     Punto* a = crear_punto(1.0, 2.0);
//     Punto* b = crear_punto(4.0, 6.0);
//     printf("Punto A: (%.2f, %.2f)\n", obtener_x(a), obtener_y(a));
//     printf("Punto B: (%.2f, %.2f)\n", obtener_x(b), obtener_y(b));
//     printf("Distancia entre A y B: %.2f\n", distancia(a, b));
//     destruir_punto(a);
//     destruir_punto(b);
//     return 0;
// }

//Ejercicio 1
// int main() {
//     //Crear puntos para el rectangulo
//     Punto * p1 = crear_punto(1.0,5.0); //Esquina superior izquierda
//     Punto * p2 = crear_punto(6.0, 2.0); // Esquina inferior derecha
//
//     //Crear rectangulo
//     Rectangulo* r = crear_rectangulo(p1, p2);
//
//     printf("Area del rectángulo: %.2f\n", area_rectangulo(r));
//     printf("Perimetro del rectángulo: %2f\n", perimetro_rectangulo(r));
//
//     //Comprobar si un punto esta dentro
//     Punto* p3 = crear_punto(3.0, 3.5);
//     if (punto_en_rectangulo(r, p3))
//         printf("El punto (%.2f, %.2f) está dentro del rectángulo.\n", obtener_x(p3), obtener_y(p3));
//     else
//         printf("El punto (%.2f, %.2f) NO está dentro del rectángulo.\n", obtener_x(p3), obtener_y(p3));
//
//     destruir_punto(p1);
//     destruir_punto(p2);
//     destruir_punto(p3);
//     destruir_rectangulo(r);
//
//     return 0;
// }

//Ejercicio 2

// int main() {
//     // Crear centro del círculo
//     Punto* centro = crear_punto(0.0, 0.0);
//     Circulo* c = crear_circulo(centro, 5.0);
//
//     printf("Area del circulo: %.2f\n", area_circulo(c));
//     printf("Perimetro del circulo: %.2f\n", perimetro_circulo(c));
//
//     // Verificar si un punto está dentro del círculo
//     Punto* p = crear_punto(3.0, 4.0);
//     if (punto_en_circulo(c, p))
//         printf("El punto (%.2f, %.2f) esta dentro del circulo.\n", obtener_x(p), obtener_y(p));
//     else
//         printf("El punto (%.2f, %.2f) NO esta dentro del circulo.\n", obtener_x(p), obtener_y(p));
//
//     // Liberar memoria
//     destruir_punto(p);
//     destruir_punto(centro);
//     destruir_circulo(c);
//
//     return 0;
// }

//Ejercicio 3 Fecha

// int main() {
//     Fecha* f1 = crear_fecha(15, 6, 2024);
//     Fecha* f2 = crear_fecha(10,7, 2023);
//
//     printf("Fecha 1: ");
//     imprimir_fecha(f1);
//
//     printf("Fecha 2: ");
//     imprimir_fecha(f2);
//
//     int cmp = comparar_fecha(f1, f2);
//     if(cmp == 0)
//         printf("Las fechas son iguales.\n");
//     else if (cmp > 0)
//         printf("Fecha 1 es mayor que Fecha 2.\n");
//     else
//         printf("Fecha 1 es menor que Fecha 2.\n");
//
//     free(f1);
//     free(f2);
//     return 0;
// }

// Ejercicio 4 Tiempo
// int main() {
//     Tiempo* t1 = crear_tiempo(10,45, 30);
//     Tiempo* t2 = crear_tiempo(2,20, 50);
//
//     printf("Tiempo 1: ");
//     imprimir_tiempo(t1);
//
//     printf("Tiempo 2: ");
//     imprimir_tiempo(t2);
//
//     Tiempo* suma = sumar_tiempo(t1, t2);
//     printf("Suma: ");
//     imprimir_tiempo(suma);
//
//     Tiempo* resta = restar_tiempo(t1, t2);
//     printf("Resta: ");
//     imprimir_tiempo(resta);
//
//     int cmp = comparar_tiempo(t1, t2);
//     if (cmp == 0)
//         printf("Los tiempos son iguales.\n");
//     else  if (cmp > 0)
//         printf("Tiempo 1 es mayor que Tiempo 2.\n");
//     else
//         printf("Tiempo 1 es menor que Tiempo 2.\n");
//
//     free(t1);
//     free(t2);
//     free(suma);
//     free(resta);
//
//     return 0;
// }

//Ejercicio 5 Fraccion
// int main() {
//     Fraccion* f1 = crear_fraccion(2,3);
//     Fraccion* f2 = crear_fraccion(4,5);
//
//     printf("Fraccion 1: ");
//     imprimir_fraccion(f1);
//
//     printf("Fraccion 2: ");
//     imprimir_fraccion(f2);
//
//     Fraccion* suma = sumar_fraccion(f1, f2);
//     simplificar_fraccion(suma);
//     printf("Suma: ");
//     imprimir_fraccion(suma);
//
//     Fraccion* resta = restar_fraccion(f1, f2);
//     simplificar_fraccion(resta);
//     printf("Resta: ");
//     imprimir_fraccion(resta);
//
//     Fraccion* mult = multiplicar_fraccion(f1, f2);
//     simplificar_fraccion(mult);
//     printf("Multiplicacion: ");
//     imprimir_fraccion(mult);
//
//     Fraccion* div = dividir_fraccion(f1, f2);
//     simplificar_fraccion(div);
//     printf("Division: ");
//     imprimir_fraccion(div);
//
//     free(f1);
//     free(f2);
//     free(suma);
//     free(resta);
//     free(mult);
//     free(div);
// }

//Ejercicio 6 Vector3D
// int main() {
//     Vector3D* v1 = crear_vector3d(1.0f, 2.0f, 3.0f);
//     Vector3D* v2 = crear_vector3d(4.0f,5.0f,6.0f);
//
//     printf("Vector 1: ");
//     imprimir_vector3d(v1);
//
//     printf("Vector 2: ");
//     imprimir_vector3d(v2);
//
//     printf("Magnitud Vector 1: %.2f\n", magnitud_vector3d(v1));
//     printf("Magnitud Vector 2: %.2f\n", magnitud_vector3d(v2));
//
//     Vector3D* suma = sumar_vector3d(v1, v2);
//     printf("Suma: ");
//     imprimir_vector3d(suma);
//
//     float escalar = producto_escalar(v1,v2);
//     printf("Producto escalar: %.2f\n", escalar);
//
//     free(v1);
//     free(v2);
//     free(suma);
//
// }

// Ejercicio 7 Recta

// int main() {
//     Recta* r = crear_recta(2.0f, -3.0f, 6.0f);
//
//     printf("Recta: 2x - 3y + 6 = 0\n");
//     printf("Pendiente: %.2f\n", pendiente_recta(r));
//
//     float x = 0.0f, y = 2.0f;
//     if (punto_en_recta(r,x,y))
//         printf("El punto (%.2f, %.2f) está en la recta.\n", x, y);
//     else
//         printf("El punto (%.2f, %.2f) No está en la recta.\n", x,y);
//
//     free(r);
//     return 0;
// }

//Ultimo Ejercicio 8 Empleado


int main() {
    Empleado* e1 = crear_empleado("Alice", 101, 2500.0f);
    Empleado* e2 = crear_empleado("Bob", 102, 3000.0f);

    printf("Empleado 1: ");
    imprimir_empleado(e1);

    printf("Empleado 2: ");
    imprimir_empleado(e2);

    aumentar_salario(e1, 500.0f);
    printf("Empleado 1 tras aumento: ");
    imprimir_empleado(e1);

    int cmp = comparar_empleado_salario(e1, e2);
    if (cmp == 0)
        printf("Ambos empleados tienen el mismo salario.\n");
    else if (cmp > 0)
        printf("Empleado 1 tiene mayor salario que Empleado 2.\n");
    else
        printf("Empleado 1 tiene menor salario que Empleado 2.\n");

    free(e1);
    free(e2);

    return 0;
}