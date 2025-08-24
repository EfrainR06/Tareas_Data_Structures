//Efrain Retana Segura UNA

//En este documento vamos a hablar de como funciona el Stack(Pila) en las estructuras de datos en base
//al documento del profe

//Definiciones importantes:
/*
Parte	                                           Descripción
Tope	    Es la "parte superior" de la pila. El último elemento insertado. Se usa para agregar o quitar datos.
Base	    Es el primer elemento que se insertó. Permanece al fondo mientras no se vacíe la pila.
Elementos	Son los datos que están dentro de la pila, organizados de acuerdo al orden de inserción.
Capacidad	El tamaño máximo que puede tener la pila (en implementaciones estáticas).
 */

/*
Caracteristicas principales de una pila:
1.LIFO (LAST IN, FIRST OUT)
El ultimo que se inserta es el primero que se elimina

OPERACIONES BASICAS:
2.	Operaciones básicas:
•	push(elemento): Agrega un elemento a la cima (top) de la pila. Meter
•	pop(): Elimina y devuelve el elemento en la cima de la pila.           Sacar
•	peek() o top(): Devuelve el elemento en la cima de la pila sin eliminarlo.
•	isEmpty(): Verifica si la pila está vacía.                                            -1
•	size(): Devuelve el número de elementos en la pila.

 */
#ifndef PILA_H
#define PILA_H
#include <iostream>
using namespace std; //Capacidad
// #define MAX 10

//Primer ejemplo
// class Pila {
//  int datos[MAX]; int tope; //Estructura de datos
//
// public:
//   Pila() {
//    tope = -1; //Inicializa pila vacia
//   }
//
//  bool estaVacia() { //-1; vacia, 0: base
//    return tope == -1;
//   }
//  bool estaLlena() {
//    return tope == MAX -1;
//   }
//
//  void meter (int valor) {
//    if (estaLlena()) {
//     cout << "Error: la pila está llena";
//     return;
//    } datos[++tope] = valor; //++tope: aumenta el indice, datos[tope]
//   }
//
//  int sacar() {
//    if (estaVacia()) {
//     cout << "Error: la pila está vacía.";
//     return -1;
//    } return datos[tope--]; //tope--; disminuye el índice, datos [tope]
//   }
//
//  int verTope() {
//    if (estaVacia()) {
//     cout << "La pila está vacia.";
//     return -1;
//    } return datos[tope];
//   }
//
//  int size() {
//    return tope + 1; //Por que empieza en -1 cuando está vacía
//   }
// };

//Ejemplo 2
//Utilización de la clase pila. Generación de una pila de 10 números aleatorios
// #define MAX 100
// class Pila {
// private:
//  int datos[MAX];
//  int tope;
// public:
//  Pila(): tope(-1) {
//
//  }
//
//  bool estaVacia() const {
//   return tope == -1;
//  }
//
//  bool estaLlena() const {
//   return tope == MAX - 1;
//  }
//
//  void meter(int valor) {
//   if (estaLlena()) {
//    std::cout << "Error: la pila está llena." << std::endl;
//    return;
//   }datos[++tope] == valor;
//  }
//  int sacar() {
//   if (estaVacia()) {
//    std::cout << "Error: la pila está vacía." << std::endl;
//    return -1;
//   }return datos[tope--];
//  }
//  int verTope() const {
//   if (estaVacia()) {
//    std::cout << "La pila esta vacía." << std::endl;
//    return -1;
//   }
//   return datos[tope];
//  }
//  int size() const {
//   return tope + 1;
//  }
//
//  void mostrar() const {
//   if (estaVacia()) {
//    std::cout << "La pila está vacía." << std::endl;
//    return;
//   }
//   std::cout << "Contenido de la pila (de arriba hacia abajo):" << std::endl;
//   for (int i = tope; i >= 0; i--) {
//    std::cout << datos[i] << std::endl;
//   }
//  }
//
//};

//Ejemplo 3: Pila de paquetes de correo

 #include <iostream>
 #include <cstring>

//  #define MAX 100
//
//  struct Paquete {
//      char remitente[50];
//      char localidad[50];
//      char destinatario[50];
//      float peso;
//  };
//
// class PilaPaquetes {
// private:
//     Paquete datos[MAX];
//     int tope;
// public:
//     PilaPaquetes() : tope (-1){}
//
//     bool estaVacia() const {
//         return tope == -1;
//     }
//
//     bool estaLlena() const {
//         return tope == MAX - 1;
//     }
//     void meter(const Paquete& p) {
//         if (estaLlena()) {
//             std::cout << "Pila llena. No se puede agregar más\n";
//             return;
//         }
//         datos[++tope] = p;
//     }
//
//     Paquete sacar() {
//         if (estaVacia()) {
//             std::cout << "Píla vacía.\n";
//             return Paquete{"","", "", 0.0f};
//         }
//         return datos[tope--];
//     }
//     void mostrar() const {
//         if (estaVacia()) {
//             std::cout << "Pila vacía.\n";
//             return;
//         }
//         std::cout << "Contenido de la pila:\n";
//         for (int i = tope; i >= 0; --i) {
//             std::cout << "Remitente: " << datos[i].remitente
//                  << "destinatario: " << datos[i].destinatario
//                  << ", Localidad: " << datos[i].localidad
//                  << ", Peso: " << datos[i].peso << "kg\n";
//         }
//     }
// };
//
// Ejemplo Lista enlazada de enteros

#include <iostream>

struct Nodo {
 int valor;
 Nodo* siguiente;
};

class Lista {
private:
 Nodo * cabeza;

public:
 Lista() : cabeza(nullptr){}

 ~Lista() {
  while (cabeza) {
   Nodo * temp = cabeza;
   cabeza = cabeza ->siguiente;
   delete temp;
  }
 }

 void insertarAlFinal(int v) {
  Nodo * nuevo = new Nodo{v, nullptr};
  if (!cabeza) {
   cabeza = nuevo;
  } else {
   Nodo * actual = cabeza;
   while (actual->siguiente) {
    actual = actual->siguiente;
   }
   actual->siguiente = nuevo;
  }
 }

 void mostrar() const {
  Nodo * actual = cabeza;
  std::cout << "Contenido de la lista: ";
  while (actual) {
   std::cout << actual->valor << " ";
   actual = actual->siguiente;
  }
  std::cout << "\n";
 }
};
#endif //PILA_H
