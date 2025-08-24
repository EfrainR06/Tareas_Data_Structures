//Efrain Retana Segura UNA

#ifndef LISTA_PAQUETES_H
#define LISTA_PAQUETES_H

#include <iostream>
#include <cstring>

struct Paquete {
    char remitente[50];
    char localidad[50];
    float peso;
};

struct Nodo {
    Paquete paquete;
    Nodo * siguiente;
};

class ListaPaquetes {
private:
    Nodo* cabeza;
public:
    ListaPaquetes() : cabeza(nullptr){}
    ~ListaPaquetes() {
        while (cabeza != nullptr) {
            Nodo * temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
    void insertarAlFinal(const Paquete& p) {
        Nodo* nuevo = new Nodo{p, nullptr};

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
        if (!cabeza) {
            std::cout << "Lista vacía.\n";
            return;
        }
        Nodo * actual = cabeza;
        while (actual) {
            std::cout << "Remitente: " << actual->paquete.remitente
                    << ",Localidad: " << actual->paquete.localidad
                    << ",Peso: "<< actual->paquete.peso << "kg\n";
            actual = actual->siguiente;
        }
    }
    //Se pueden agregar funciones como buscar, eliminar,etc
};
#endif //LISTA_PAQUETES_H
