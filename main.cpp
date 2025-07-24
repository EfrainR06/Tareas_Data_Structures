//Primera tarea de Estructura de Datos

// Construya un programa C++ que permite utilizar un estructura de datos
// llamada estudiantes de la cual se genera un arreglo de memoria fija
// de 30 campos de tipo estructura estudiante, una vez cargada la estructura
// se almacena en un archivo binario.

//El estilo de programacion es estructurado

//Para realizar este problema debe utilizar las funciones fopen, fwrite y fclose
//asi como la definicion de tipo de datos estructura, asignacion de memoria fija
//arreglo unidimensional.

//Parte 2
// definir un tipo de dato asbstracto llamado punto, y los operadores necesarios
// para la funciones 1.Distancia entre puntos.

#include <iostream>
#include <fstream>
using namespace std;

//declaracion de variables y estructuras
//declaracion de funciones

struct Estudiante{
char carnet[10];
int edad;
char escuela[30];
};

Estudiante clase[5];

//Esta función carga los datos de 30 estudiantes usando un for.
//Para cada estudiante, pide el carnet, la edad y la escuela, y los guarda en el arreglo 'clase'.
// Uitliza un ciclo for como ya mencione, para recorrer cada posición del arreglo y solicita los datos por la consola.
void cargar_clase(){
    for(int i = 0; i < 5; i++){
        cout << "Estudiante #" << i + 1 << endl;
        cout << "Carnet: ";
        cin >> clase[i].carnet;
        cout << "Edad: ";
        cin >> clase[i].edad;
        cout << "Escuela: ";
        cin.ignore();
        cin.getline(clase[i].escuela, 30);
    }
}

//Esta función recorre el array de los 30 estudiantes y muestra en plantilla la información de cada uno, incluyendo
// el número de estudiantes, carnet, edad y escuela.
//Es útil para verificar que los datos se hayan ingresado correctamente y para visualizar el contenido antes de guardarlo..

void presentar_clase(){
    for (int i = 0; i < 5; i++){
        cout << "Estudiante #" << i + 1 << ": ";
        cout << clase[i].carnet << ", ";
        cout << clase[i].edad << ", ";
        cout << clase[i].escuela << endl;
    }
}

//Esta funcíón guarda todos los datos del arreglo de estudiantes en un archivo binario llamado "clase.bin" Utiliza las funciones de la libreria fstream,
//fopen, fwrite y fclose para crear el archivo y escribir la información de manera eficiente. Es importante para almacenar los datos de forma permanente
// y poder recuperarlos posteriormente. Además, informa si las operaciones fueron exitosas o si ocurrio un error al abrir el archivo.
void grabar_clase(){
    FILE *archivo = fopen("../clase.bin", "wb");
    if (archivo != nullptr) {
        fwrite(clase, sizeof(Estudiante), 30, archivo);
        fclose(archivo);
        cout << "Datos guardados en clase.bin" << endl;
    }else{
        cout << "No se pudo abrir el archivo." << endl;
    }
}
//Esta funcion va a intentar abrir el bin y cargar los datos de los estudiantes en el arreglo. Si el archivo existe, lee la información, si no,
//pide los datos manualmente y los guarda en el archivo para usarlo después...
void cargar_desde_binario() {
    FILE* archivo = fopen("../clase.bin", "rb");
    if (archivo != nullptr) {
        fread(clase, sizeof(Estudiante), 5, archivo);
        fclose(archivo);
        cout << "Datos cargados desde clase.bin" << endl;
    }else{
        cout << "No se encontró clase.bin, ingrese los datos manualmente." << endl;
        cargar_clase();
        grabar_clase();
    }
}
//main con las funciones ya hechas...
int main() {
    //cargar_clase();
    //presentar_clase();
    //grabar_clase();
    cargar_desde_binario();
    presentar_clase();
    return 0;
}
