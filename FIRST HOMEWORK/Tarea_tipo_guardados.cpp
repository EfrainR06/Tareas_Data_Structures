//Efrain Retana Segura UNA

//1.Guardado Binario Directo (Secuencial o Lineal)
//Prompt (Retanaefrain42@gmail.com):
// Generame definiciones de los 3 tipos de guardados siguientes
//Binario(Directo), secundarios y a acceso directo, los 3 tienen que ser referentes a c++.

//Binario directo(Secuencial o Lineal):
//Este tipo de almacenamiento guarda los datos de un archivo binario uno tras otro, en el orden en que se escriben
// Se accede de forma secuencial, si quieres el tercer dato, tienes que leer el primero y el segundo antes de poder llegar al tercero.

//Ejemplo

#include <iostream>
#include <fstream>
using namespace std;
/*
struct Persona {
    char nombre[20];
    int edad;
};

int main() {
    Persona p = {"Carlos",30};

    ofstream archivo("../persona.dat", ios::binary);
    archivo.write(reinterpret_cast<char*>(&p), sizeof(p));
    archivo.close();

    cout << "Persona guardada de forma binaria directa. \n";
    return 0;
}
*/

// 2. Guardado Secundario (o Almacenamiento Secundario)
// Este termino se refiere al uso de medios externos como discos duros, USB o archivos para guardar
// información. En C++, esto implica leer/escribir datos en discos, típicamente en archivos .txt o .bin.
// Puede ser secuencial o aleatorio, pero siempre se almacena en dispositivos secundarios.

//Ejemplo

/*
int main() {
    ofstream archivo("../datos.txt");
    archivo << "Hola Mundo \n";
    archivo << "Este es un archivo en almacenamiento secundario.";
    archivo.close();

    cout << "Datos guardados en almacenamiento secundario.\n";
    return 0;

    //NOTA: Aunque es más conceptual, puede usar el término "almacenamiento secundario" para referirse al medio
    // donde se guarda (disco duro, etc.).
}
*/

//3. Guardado con acceso directo (aleatorio)
//Este tipo de almacenamiento permite acceder directamente a una posición específica del archivo, sin tener que leer todo
// lo anterior. Se usa mucho en archivos binarios para buscar rápidamente un registro.

//Ejemplo

// struct Persona {
//     char nombre[20];
//     int edad;
// };
//
// int main() {
//     Persona personas[3] ={
//         {"Ana", 25},
//         {"Luis", 32},
//         {"Marta", 28}
//     };
//
//     //Guardar personas en archivo
//     ofstream archivo("personas_directo.dat", ios::binary);
//     for (int i = 0; i < 3; i++) {
//         archivo.write(reinterpret_cast<char*>(&personas[i]), sizeof(Persona));
//     }
//     archivo.close();
//
//     //Leer directamente la segunda persona (Luis)
//
//     Persona buscada;
//     ifstream lectura("personas_directo.dat", ios::binary);
//     lectura.seekg(sizeof(Persona) * 1); // Ir al segundo registro
//     lectura.read(reinterpret_cast<char*> (&buscada), sizeof(Persona));
//     lectura.close();
//
//     cout << "Acceso directo: " << buscada.nombre << "- Edad: " << buscada.edad << endl;
//     return 0;
// }