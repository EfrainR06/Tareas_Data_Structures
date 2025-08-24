//Efrain Retana UNA
//Main

// #include "PILA.h"

//PRIMER EJEMPLO
// int main() {
//     Pila miPila;
//     miPila.meter(10); //Insertar algunos números
//     miPila.meter(20);
//     miPila.meter(30);
//     int valor = miPila.sacar(); // Sacar un número
//     if (valor != -11) {
//         cout << "se sacó el valor: " << valor;
//         cout << endl;
//     }
//     int tope = miPila.verTope(); //Ver el elemento tope
//     if (tope != -1) {
//         cout << "El elemento en el tope es: " << tope;
//         cout << endl;
//     }
//     return 0; //Exito
// }

//Ejemplo 2:Utilización de la clase pila.Generación de una pila de 10 números aleatorios

// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include "PILA.h"
//
// int main() {
//     Pila miPila;
//     srand(time(NULL)); //Inicializa la semilla para números aleatorios
//     for (int i = 0; i < 10; i++) { //Insertar 10 números aleatorios entre 10 y 100
//          int numero = rand() % 100 + 1;
//         miPila.meter(numero);
//     }
//     miPila.mostrar(); //Mostrar la pila
//     return 0;
// }

//Ejemplo 3:Pila paquetes
//
// #include <cstdio>
// #include "PILA.h"
//
// int main() {
//     FILE * archivo = fopen("paquetes.bin", "rb");
//     if (!archivo) {
//         std::perror("Error al abrir el archivo binario");
//         return 1;
//     }
//
//     PilaPaquetes pila;
//     Paquete p;
//
//     while (fread(&p, sizeof(Paquete),1,archivo) == 1) {
//         pila.meter(p);
//     }
//     fclose(archivo);
//
//     std::cout << "\nPaquetes cargados desde archivo binario:\n";
//     pila.mostrar();
//
// }
//Ejemplo 4:
//Programa para crear el archivo de paquetes;

#include <cstdio>
#include <cstring>
#include "PILA.h"

//Creacion del archivo paquets.bin
// int main() {
//     FILE * archivo = fopen("../STACK NOTES/paquetes.bin", "wb");
//     if (!archivo) {
//         std::perror("No se pudo crear el archivo");
//         return 1;
//     }
//     Paquete p;
//
//
//     strcpy(p.remitente, "Juan Perez");
//     strcpy(p.destinatario, "Ana Rojas");
//     strcpy(p.localidad, "Alajuela");
//     p.peso = 2.5f;
//     fwrite(&p, sizeof(Paquete), 1, archivo);
//
//     strcpy(p.remitente, "Maria Lopez");
//     strcpy(p.destinatario, "Luis Campos");
//     strcpy(p.localidad, "Heredia");
//     p.peso = 1.7f;
//     fwrite(&p, sizeof(Paquete), 1, archivo);
//
//     strcpy(p.remitente, "Carlos Ruiz");
//     strcpy(p.destinatario, "Mario Ruiz");
//     strcpy(p.localidad, "San Jose");
//     p.peso = 3.3f;
//     fwrite(&p, sizeof(Paquete), 1, archivo);
//
//     fclose(archivo);
//
//     std::cout << "Archivo binario creado correctamente.\n";
//     return 0;
//    }

//Ejemplo 5: usando lista paquete con structs
// #include "Lista_paquetes.h"
//
// int main() {
//     FILE * archivo = fopen("../STACK NOTES/paquetes.bin", "rb");
//     if (!archivo) {
//         std::perror("Error al abrir el archivo binario");
//         return 1;
//     }
//
//     ListaPaquetes lista;
//     Paquete p;
//
//     while (fread(&p, sizeof(Paquete), 1, archivo) == 1) {
//         lista.insertarAlFinal(p);
//     }
//     fclose(archivo);
//
//     std::cout << "Contenido de la lista enlazada:\n";
//     lista.mostrar();
//
//     return 0;
// }

//Ejemplo 6: Lista con números aleatorios
// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include "PILA.h"
//
// int main() {
//     Lista lista;
//     std::srand(std::time(nullptr)); //Semilla para números aleatorios
//
//     //Insertar 10 números aleatorios del 1 al 100
//     for (int i = 0; i < 10; ++i) {
//         int num = rand() % 100 + 1;
//         lista.insertarAlFinal(num);
//     }
//
//     lista.mostrar();
//
//     return 0;
// }

//Ejemplo 7: Generador de un arreglo dínamico

#include <iostream>

// int main() {
//     int tamannio;
//
//     std::cout << "Ingrese el tamannio del arreglo: ";
//     std::cin >> tamannio;
//
//     //Crear arreglo dínamico
//     int * arreglo = new int[tamannio];
//
//     //Llenar el arreglo con valores
//     for (int i = 0; i < tamannio; ++i) {
//         arreglo[i] = i * 10;
//     }
//     for (int i = 0; i < tamannio; ++i) {
//         std::cout << arreglo[i] << " ";
//     }
//     std::cout << "\n";
//
//     //Liberar memoria
//     delete [] arreglo;
//
//     return 0;
// }

//Ejemplo 8: usando malloc estilo c puro


#include <iostream> //Para entrada / salida
#include <cstdlib> //Para malloc y free


int main() {
    int tamanio;

    std::cout << "Ingrese el tamannio del arreglo: ";
    std::cin >> tamanio;

    //Reservar memoria dinamicamente para 'tamanio' enteros
    int * arreglo = (int*)malloc(tamanio * sizeof(int));

    //Verificar que lamemoria fue reservada con éxito

    if (arreglo == nullptr) {
        std::cerr << "Error: no se pudo asignar memoria.\n";
        return 1;
    }

    //Llenar el arreglo con valores (por ejemplo, múltiplos de 2)
    for (int i = 0; i < tamanio; ++i) {
        arreglo[i] = i * 2;
    }

    //Mostrar el contenido del arreglo
    std::cout << "Contenido del arreglo:\n";
    for (int i = 0; i < tamanio; ++i) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << "\n";

    //Liberar la memoria al final
    free(arreglo);

    return 0;
}