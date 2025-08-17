//Efrain Retana Segura UNA

//Este es un ejemplo de una de las primeras tareas de la clase de data structures
//Hay que tener en cuenta, aspectos de O(n) y de espacio del ram, con esto
//veamos como se puede abrir un archivo

//Tarea 1:promedio ponderado de Listas de estudiantes

//TIP 1:
//Programar en C++ para crear un archivo binario con entrada de usuario.

//Vamos a utilizar fopen, fwrite y fclose para crear un archivo binario con una estrctura que contiene un
// int para el carnet y un char para el nombre, y solicita la entrada de usuario utilizado el cin y cout;

//Vamos a usar 2 bibliotecas y namespace std

#include <iostream>
#include <cstdio>

using namespace std;

//Definiremos la estructura
struct Registro {
    int carnet;
    char nombre[10];
};

//Función para ordenar el arreglo de registros
void ordenarRegistros(Registro * registros, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (registros[i].carnet > registros[j].carnet){
            //Intercambiar registros
                Registro temp = registros[i];
                registros[i] = registros[j];
                registros[j] = temp;
            }
        }
    }
}
void mostrarArchivo(const char* ruta) {
    FILE* archivo = fopen(ruta, "rb");
    if (archivo == NULL) {
        cout << "Error al abrir el archivo para mostrar" << endl;
        return;
    }
    Registro registro;
    int i = 1;
    while (fread(&registro, sizeof(Registro), 1, archivo) == 1) {
        cout << "Estudiante " << i++ << ": ";
        cout << "Carnet: " << registro.carnet << ", Nombre: " << registro.nombre << endl;
    }
    fclose(archivo);
}

int main() {
    // //Abrir el archivo en modo lectura
    // FILE * archivo = fopen("../IMPORTANT NOTES/registros3.bin", "wb");
    // if (archivo == NULL) {
    //     cout << "Error al abrir el archivo" << endl;
    //     return 1; //NO EXITO
    // }
    // Registro registro;
    // for (int i = 0; i < 3; i++) {
    //     cout << "Ingrese el carnet del estudiante " << i + 1 << ": ";
    //     cin >> registro.carnet;
    //     cin.ignore();
    //     cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
    //     cin.getline(registro.nombre, 10);
    //     fwrite(&registro, sizeof(Registro), 1, archivo);
    // }
    // fclose(archivo);
    //
    // //Paso 2: Leer, ordenar y sobreescribir el archivo
    // archivo = fopen("../IMPORTANT NOTES/registros3.bin", "rb");
    // if (archivo ==  NULL) {
    //     cout << "Error al abrir el archivo" << endl;
    //     return 1;
    // }
    // //Calcular el tamaño del archivo y el número de registros
    // fseek(archivo, 0, SEEK_END);
    // long tamanio = ftell(archivo);
    // int n = tamanio / sizeof(Registro);
    // rewind(archivo);
    //
    // //Leer los registros del archivo de un arreglo
    // Registro * registros = new Registro[n];
    // fread(registros, sizeof(Registro), n, archivo);
    // fclose(archivo);
    //
    // //Ordenar los registros
    // ordenarRegistros(registros, n);
    //
    // //Guardar los registros ordenados en el archivo
    // archivo= fopen("../IMPORTANT NOTES/registros3.bin","wb");
    // fwrite(registros, sizeof(Registro), n, archivo);
    // fclose(archivo);
    //
    // delete[] registros;
    //
    // cout << "Archivo ordenado con exito" << endl;
    // cout << "Tamanio del archivo: " << tamanio << "bytes" << endl;

    mostrarArchivo("../IMPORTANT NOTES/registros3.bin");

    return 0; //EXITO
}

