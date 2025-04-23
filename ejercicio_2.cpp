#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cctype>

using namespace std;

map<string,int> frecuenciaPalabras(string& nombreArchivo){
    // Se debe abrir el archivo en modo lectura
    ifstream file(nombreArchivo);
    if(!file.is_open()){
        cerr << "Error de apertura del archivo" << endl;
        return {};  // Retorna un map vacío si no se puede abrir el archivo
    }

    // Se debe leer el archivo línea por linea usando getline en un ciclo while
    string linea;
    // Se crea un vector para almacenar cada palabra del archivo
    vector<string> almacen;
    string palabra_temp;
    // Se usa un iterador para recorrer la linea
    string::iterator recorrido = linea.begin();
    while (getline(file, linea)) {
        string palabra_temp;
        for (string::iterator it = linea.begin(); it != linea.end(); ++it) {
            if (!isspace(*it) && !ispunct(*it)) {
                palabra_temp += *it;
            } else {
                if (!palabra_temp.empty()) {
                    almacen.push_back(palabra_temp);
                    palabra_temp.clear();
                }
            }
        }
        if (!palabra_temp.empty()) {
            almacen.push_back(palabra_temp);
        }
    }
    // Se cierra el archivo
    file.close();

    // Se consignan los elementos del vector a un set para evitar palabras repetidas en el map, ademas 
    set<string> set_almacen;
    for(const auto& c: almacen){
        set_almacen.insert(c);
    }
    // Se debe crear un contenedor map para almacenar las palabras y su frecuencia
    map<string,int> pal_frec;
    // Se cuentan las frecuencias de cada elemento de set_almacen en almacen
    vector<string>::iterator it = almacen.begin();
    int frecuencia;
    // Se recorre el set_almacen
    // Se usa un iterador para recorrer el vector almacen
    for(const string& s: set_almacen){
        frecuencia = 0;
        while(it != almacen.end()){
            // Se verifica si el elemento actual del vector almacen es igual al elemento actual del set_almacen
            if(*it == s){
                frecuencia++;
            }
            it++;
        }
        // Se almacena la palabra y su frecuencia en el map
        pal_frec[s] = frecuencia;
        it = almacen.begin();
    }
    // Se retorna el map con las palabras y su frecuencia
    return pal_frec;
    
}

int main(){
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo: ";
    cin >> nombreArchivo;
    // Se recurre a la función frecuenciaPalabras
    map<string,int> resultado = frecuenciaPalabras(nombreArchivo);
    // Se imprime el resultado
    cout << "Frecuencia de palabras en el archivo: " << endl;
    for(const auto& par : resultado){
        cout << par.first << ": " << par.second << endl;
    }
    return 0;
}