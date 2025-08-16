//Efrain Retana Segura UNA
#ifndef ARREGLO_INT_H
#define ARREGLO_INT_H
#include <algorithm>
#include <iostream>

class Arreglo {
private:
    int libre;
    int capacidad;
    int cantidad;
    int * Datos;
public:
    Arreglo() {
        capacidad = 10; // or any default size
        libre = 0;
        cantidad = 0;
        Datos = new int[capacidad];
    }
    Arreglo(int l,int c,int ca) {
        libre = l;
        capacidad = c;
        cantidad = ca;
        Datos = new int(0);
    }
    //Allocate the gray
    void crearArreglo() {
        Datos = new int[capacidad];
        libre = 0;
        cantidad = 0;
    }
    //Insert a value into the array
    void meter(int v) {
        if (libre < capacidad) {
            Datos[libre++] = v;
            cantidad++;
        }
    }
    int sacar(int p) {
        for (int i = 0; i < cantidad; i++) {
            if (Datos[i] == p) {
                //Shift elements left
                for (int j = i; j < cantidad -1; j++) {
                    Datos[j] = Datos[j + i];
                }
                cantidad--;
                libre--;
                return p;
            }
        }
        return -1; // no encontrado
    }
    int buscar(int v) {
        for (int i = 0; i < cantidad;i++) {
            if (Datos[i] == v) {
                return Datos[i];
            }
        }
        return -1;
    }

    void aumentarArreglo() {
        int nuevaCapacidad = capacidad * 2;
        int * nuevoDatos = new int[nuevaCapacidad];
        for (int i = 0; i < cantidad; i++) {
            nuevoDatos[i] = Datos[i];
        }
        delete[] Datos;
        Datos = nuevoDatos;
        capacidad = nuevaCapacidad;
    }
    //Sort the array based on t: 1 =bubble, 2=selection, 3=descneding bubble
    //Bubble last case O(n**2), best case O(n)
    void ordenarArreglo(int t) {
        if (cantidad < 2) return;
        switch (t) {
            case 1: { // Optimized bubble sort (ascending)
                int limite = cantidad - 1;
                while (limite > 0) {
                    int nuevo_limite = 0;
                    for (int j = 0; j < limite; j++) {
                        if (Datos[j] > Datos[j + 1]) {
                            int temp = Datos[j];
                            Datos[j] = Datos[j + 1];
                            Datos[j + 1] = temp;
                            nuevo_limite = j;
                        }
                    }
                    limite = nuevo_limite;
                }
                break;
            }
            case 2: // Selection sort (ascending)
                for (int i = 0; i < cantidad - 1; i++) {
                    int minIdx = i;
                    for (int j = i + 1; j < cantidad; j++) {
                        if (Datos[j] < Datos[minIdx]) minIdx = j;
                    }
                    int temp = Datos[i];
                    Datos[i] = Datos[minIdx];
                    Datos[minIdx] = temp;
                }
                break;
            case 3: // Bubble sort (descending)
                for (int i = 0; i < cantidad - 1; i++) {
                    for (int j = 0; j < cantidad - i - 1; j++) {
                        if (Datos[j] < Datos[j + 1]) {
                            int temp = Datos[j];
                            Datos[j] = Datos[j + 1];
                            Datos[j + 1] = temp;
                        }
                    }
                }
                break;
        }
    }
    //Free the memory allocated for the array
    void liberarMemoria() {
        delete[] Datos;
        Datos = nullptr;
    }
    //Print the array elements
    void mostrarArreglo() {
        for (int i = 0; i < cantidad; i++) {
            std::cout << Datos[i] << " ";
        }
        std::cout << std::endl;
    }

};

#endif //ARREGLO_INT_H
