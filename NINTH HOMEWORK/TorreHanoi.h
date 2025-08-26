// Efrain Retana Segura UNA

#ifndef TORREHANOI_H
#define TORREHANOI_H
#include <iostream>
#define MAX 20

class Pila {
private:
    int datos[MAX]; // Arreglo para almacenar los elementos de la pila
    int tope;       // Índice del elemento en la cima de la pila
public:
    // Constructor: Inicializa la pila vacía
    Pila() : tope(-1){}

    // Verifica si la pila está vacía
    bool estaVacia() const {
        return tope == -1;
    }

    // Verifica si la pila está llena
    bool estaLlena() const {
        return tope == MAX - 1;
    }

    // Inserta un valor en la cima de la pila
    void meter(int valor) {
        if (estaLlena()) {
            std::cout << "Error: la pila está llena." << std::endl;
            return;
        }
        datos[++tope] = valor;
    }

    // Elimina y retorna el valor en la cima de la pila
    int sacar() {
        if (estaVacia()) {
            std::cout << "Error: la pila está vacía." << std::endl;
            return -1;
        }
        return datos[tope--];
    }

    // Retorna el valor actual en la cima de la pila sin eliminarlo
    int verTope() const {
        if (estaVacia()) {
            std::cout << "La pila está vacía." << std::endl;
            return -1;
        }
        return datos[tope];
    }

    // Retorna la cantidad de elementos en la pila
    int size() const {
        return tope + 1;
    }

    // Retorna el valor en la posición indicada (útil para visualización en FLTK)
    int get(int idx) const {
        if (idx < 0 || idx > tope) return -1;
        return datos[idx];
    }
};
#endif //TORREHANOI_H