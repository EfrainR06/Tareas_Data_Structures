//Efrain Retana Segura UNA

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h> //Para getch que pide el profe


//Clase que implementa una cola circular de 10 elementos
class ColaCircular {
private:
    int datos[10]; //Arreglo para almacenar los elementos
    int frente; //Enlace del frente de la cola
    int final; //Indice del final de la cola
    int cantidad; //Cantidad de elementos de la cola
public:
    //Constructor: inicializada la cola vacia
    ColaCircular() : frente(0), final(-1), cantidad(0){}

    //Verificar si la cola está vacía
    bool estaVacia() const {
        return cantidad == 0;
    }
    //Verificar si la cola está llena
    bool estaLlena() const {
        return cantidad == 10;
    }

    //Insertar un valor al final de la cola
    void meter(int valor) {
        if (estaLlena()) {
            std::cout << "Error: la cola esta llena.\n";
            return;
        }
        final = (final + 1 ) % 10;
        datos[final]  = valor;
        cantidad++;
    }

    //Elimina y retorna el valor en el frente de la cola
    int sacar() {
        if (estaVacia()) {
            std::cout << "Error: la cola esta vacía.\n";
            return -1;
        }
        int valor = datos[frente];
        frente = (frente + 1) % 10;
        cantidad--;
        return valor;
    }

    //Muestra el contenido actual de la cola
    void mostrar() const {
        std::cout << "Contenido de la cola: ";
        if (estaVacia()) {
            std::cout << "(vacia)\n";
            return;
        }
        for (int i = 0; i < cantidad; ++i) {
            int idx = (frente + i) % 10;
            std::cout << datos[idx] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    std::srand(std::time(nullptr));

    ColaCircular cola;

    for (int i = 0; i < 4; ++i) {
        int num = rand() % 100 + 1;
        cola.meter(num);
        std::cout << "Se insertó: " << num << "\n";
        cola.mostrar();
    }

    while (true) {
        int accion = rand() % 2;
        if (accion == 0) {
            int num = rand() % 100 + 1;
            std::cout << "Acción: meter " << num << "\n";
            cola.meter(num);
        } else {
            std::cout << "Acción: sacar\n";
            int valor = cola.sacar();
            if (valor != -1)
                std::cout << "Se sacó: " << valor << "\n";
        }
        cola.mostrar();

        std::cout << "Press a key (ESC to exit)...\n";
        int tecla = _getch();
        if (tecla == 27) break;
    }

    std::cout << "Programa terminado.\n";
    return 0;
}