#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <cctype>
using namespace std;

set<string> LecturaAlmacenamiento(string nombreArchivo){
    set<string> almacen;
    string linea;
    ifstream file(nombreArchivo);
    if (!file.is_open()){
        cerr << "Error al abrir el archivo." << endl;
        return almacen;
    }
    // Se debe leer el archivo línea por linea usando getline en un ciclo while
    while(getline(file, linea)){
        // Se debe separar la linea en palabras
        string palabra_temp;
        // Se recorre caracter por caracter la linea leida usando un iterador
        string::iterator it = linea.begin();
        while(it != linea.end()){
            /* Se verifica que el elemento actual no sea un espacio o un signo de puntuación*/
            if(!isspace(*it) && !ispunct(*it) && *it != ','){
                palabra_temp += *it;
            }
            else{
                // En caso de no ser alfanúmerico se verifica si palabra_temp no está vacia
                if(palabra_temp != ""){
                    //Se almacena la palabra en el set
                    almacen.insert(palabra_temp);
                    // Luego se reinicia la palabra temporal
                    palabra_temp = "";
                }
            }
            it++;
        }

        if (palabra_temp != ""){
            almacen.insert(palabra_temp);
        }
        
    }

    file.close();

    return almacen;
}

int main(){
    string filename;
    cout << "Ingrese el nombre del archivo a leer: ";
    cin >> filename;
    cout << endl;
    set<string> set_palabras = LecturaAlmacenamiento(filename);
    cout << "Contenido del set" << endl;
    // Se imprime el contenido del set
    bool primer_elemento = true;
    for (const auto& palabra : set_palabras) {
        
        if (primer_elemento){
            cout << "{" << palabra;
            primer_elemento = false;
        }
        else{
            cout << ", " << palabra;
        }
    }
    cout << "}" << endl;
    return 0;

}
// Este programa lee un archivo de texto y almacena las palabras en un conjunto (set) para evitar duplicados y ordena automaticamente las palabras.
