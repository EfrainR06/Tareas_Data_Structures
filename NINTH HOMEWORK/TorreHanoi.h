//Efrain Retana Segura UNA

#ifndef TORREHANOI_H
#define TORREHANOI_H
#include <iostream>
#define MAX 20

class Pila {
private:
    int datos[MAX];
    int tope;
public:
    Pila() : tope(-1){}

    bool estaVacia() const {
        return tope == -1;
    }

    bool estaLlena() const {
        return tope == MAX - 1;
    }

    void meter(int valor) {
        if (estaLlena()) {
            std::cout << "Error: la pila está llena." << std::endl;
            return;
        }
        datos[++tope] = valor;
    }

    int sacar() {
        if (estaVacia()) {
            std::cout << "Error: la pila está vacía." << std::endl;
            return -1;
        }
        return datos[tope--];
    }

    int verTope() const {
        if (estaVacia()) {
            std::cout << "La pila está vacía." << std::endl;
            return -1;
        }
        return datos[tope];
    }

    int size() const {
        return tope + 1;
    }

    //Para visualizar los discos en FLTK
    int get(int idx) const {
        if (idx < 0 || idx > tope) return -1;
        return datos[idx];
    }
};
#endif //TORREHANOI_H
