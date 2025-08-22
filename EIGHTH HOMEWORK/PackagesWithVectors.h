//Efrain Retana Segura UNA
//Segunda parte de la tarea de paquetes con vectores y memoria dinámica

#ifndef PACKAGESWITHVECTORS_H
#define PACKAGESWITHVECTORS_H
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct Paquete {
    char remitente[256];
    char destinatario[256];
    int localidad;
    char direccion[256];
    double peso;
    int prioridad;
};
//NOTA, no se usa en los parametros de los metodos el vector<Paquete> por que ya lo tenemos agregados
// en el private como un vector<Paquete> llamado datos
class Paquetes {
private:
    vector<Paquete> datos; // Almacena todos los paquetes
public:

    // Muestra todos los paquetes en el vector
    void mostrar() const {
        cout << "\n---- Lista de paquetes ----\n";
        for (size_t i = 0; i < datos.size(); i++) {
            cout << i << ". Remitente: " << datos[i].remitente
                 << ", Destinatario: " << datos[i].destinatario
                 << ", Localidad: " << datos[i].localidad
                 << ", Direccion: " << datos[i].direccion
                 << ", Peso: " << datos[i].peso
                 << ", Prioridad: " << datos[i].prioridad << endl;
        }
    }

    // Agrega un nuevo paquete al vector
    void agregar(const Paquete& p) {
        datos.push_back(p);
        cout << "Paquete agregado.\n";
    }

    // Modifica el paquete en la posición dada
    void modificar(int pos, const Paquete& nuevo) {
        if (pos >= 0 && pos < datos.size()) {
            datos[pos] = nuevo;
            cout << "Paquete modificado.\n";
        }else {
            cout << "Posición inválida.\n";
        }
    }

    // Elimina el paquete en la posición dada
    void eliminar(int pos) {
        if (pos >= 0 && pos < datos.size()) {
            datos.erase(datos.begin() + pos);
            cout << "Paquete eliminado.\n";
        } else {
            cout << "Posición inválida.\n";
        }
    }

    // Add this method inside your Paquetes class
    void ordenarPorPrioridad() {
        if (datos.size() < 2) return;
        for (size_t i = 0; i < datos.size() - 1; ++i) {
            for (size_t j = 0; j < datos.size() - i - 1; ++j) {
                if (datos[j].prioridad > datos[j + 1].prioridad) {
                    Paquete temp = datos[j];
                    datos[j] = datos[j + 1];
                    datos[j + 1] = temp;
                }
            }
        }
        cout << "Paquetes ordenados por prioridad.\n";
    }
    // Amplía el vector a un nuevo tamaño, rellenando con paquetes por defecto
    void ampliar (int nuevo_tamano) {
        if (nuevo_tamano > datos.size()) {
            datos.resize(nuevo_tamano);
            cout << "Vector ampliado a: " << nuevo_tamano << " paquetes.\n";
        } else {
            cout << "El nuevo tamaño debe ser mayor al actual.\n";
        }
    }
    void AbrirArchivo() {
        FILE * archivo = fopen("../EIGHTH HOMEWORK/paquetes.dat", "wb");
        if (archivo == NULL) {
            cout << "Error al abrir archivo" << endl;
        }
        //Solicitar 3
        Paquete registro;
        for (int i = 0; i < 3; i++) {
            cout << "\n----- Paquete " << i + 1 << " -----\n";
            cout << "Ingrese el remitente " << i + 1 << ": ";
            cin.getline(registro.remitente, 256); // Ignorar el salto de linea;
            cout << "Ingrese el destinario " << i + 1 << ": ";
            cin.getline(registro.destinatario, 256);
            cout << "Ingrese la localidad (1,2,3,4,5,6,7) según primer número de provincia " << i + 1 << ": ";
            cin>> registro.localidad;
            cin.ignore(); //Ignorar el salto de linea
            cout << "Ingrese la direccion del envio " << i + 1 << ": ";
            cin.getline(registro.direccion, 256);
            cout << "Ingrese el peso del envio en KG " << i + 1 << ": ";
            cin>> registro.peso;
            cin.ignore();
            cout << "Ingrese la prioridad del envio (1: Importante, 2: Regular, 3: Falta de importancia ) " << i + 1 << ": ";
            cin >> registro.prioridad;
            cin.ignore();
            fwrite(&registro, sizeof(Paquete), 1, archivo);
            agregar(registro);
        }
        fclose(archivo);
    }
    void mostrarDesdeArchivo(const char* nombreArchivo) {
        FILE * archivo = fopen(nombreArchivo, "rb");
        if (!archivo) {
            cout << "Error al abrir el archivo" << endl;
            return;
        }
        fseek(archivo, 0, SEEK_END);
        long tam = ftell(archivo);
        int n = tam / sizeof(Paquete);
        rewind(archivo);

        Paquete* registros = new Paquete[n];
        fread(registros, sizeof(Paquete),n,archivo);
        fclose(archivo);

        for (int i = 0; i < n; i++) {
            cout << "Remitente: " << registros[i].remitente << endl;
            cout << "Destinatario: " << registros[i].destinatario << endl;
            cout << "Localidad: " << registros[i].localidad << endl;
            cout << "Direccion: " << registros[i].direccion << endl;
            cout << "Peso: " << registros[i].peso << endl;
            cout << "Prioridad: " << registros[i].prioridad << endl;
            cout << "------------------------" << endl;
        }
        delete[] registros;
    }
    //Metodo para guardar los paquetes ordenados
    void guardarOrdenados(const char* nombreArchivo) {
        FILE * archivo = fopen(nombreArchivo, "wb");
        if (!archivo) return;
        for (size_t i = 0; i < datos.size(); i++) {
            fwrite(&datos[i], sizeof(Paquete), 1, archivo);
        }
        fclose(archivo);
    }

    //Metodo para liberar memoria
    void liberarMemoria() {
        datos.clear();
    }
};

/*
mostrar(): O(n) — Recorre todos los paquetes.
agregar(const Paquete&): O(1) — Agrega un paquete al final del vector.
modificar(int, const Paquete&): O(1) — Modifica un paquete en una posición dada.
eliminar(int): O(n) — Elimina un elemento, desplazando el resto.
ordenarPorPrioridad(): O(n²) — Ordenamiento burbuja, dos ciclos anidados.
ampliar(int): O(m) — Redimensiona el vector, donde m es el nuevo tamaño (si es mayor).
AbrirArchivo(): O(1) al abrir el archivo, O(3) en el ciclo de entrada (fijo 3 veces).
mostrarDesdeArchivo(const char*): O(n) — Lee y muestra todos los paquetes del archivo.
guardarOrdenados(const char*): O(n) — Escribe todos los paquetes en el archivo.
liberarMemoria(): O(n) — Limpia el vector.

La función con mayor complejidad es:
ordenarPorPrioridad() con complejidad O(n²).
*/

#endif //PACKAGESWITHVECTORS_H