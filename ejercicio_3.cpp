#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

// Se crea una función que lee el archivo y ordena las tareas segun la prioridad, usando una cola de prioridad invertida
priority_queue<string, vector<string>, greater<string>> lecturaArchivo(string& nombreArchivo){
        // Se debe abrir el archivo en modo lectura
        ifstream file(nombreArchivo);
        if(!file.is_open()){
            cerr << "Error de apertura del archivo" << endl;
            return {};  // Retorna una cola de prioridad vacía si no se puede abrir el archivo
        }
        // Se debe leer el archivo línea por linea usando getline en un ciclo while
        string linea;
        // Se crea una priority_queue para almacenar cada palabra del archivo
        priority_queue<string, vector<string>, greater<string>> almacen;
        string palabra_temp;
        // Se usa un iterador para recorrer la linea
        string::iterator recorrido = linea.begin();
        while (getline(file, linea)) {
            almacen.push(linea);
        }
        // Se cierra el archivo
        file.close();
        // Se retorna la cola de prioridad con las palabras
        return almacen;
}


int main(){
    // Se define una variable para almacenar el nombre del archivo con las tareas
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo con las tareas: ";
    cin >> nombreArchivo;
    // Apertura del archivo, y se almacenan las tareas del archivo directamente en una cola de prioridad
    priority_queue<string, vector<string>, greater<string>> tareas = lecturaArchivo(nombreArchivo);

    // Se imprime la cola de prioridad en la terminal usando una copia para no borrar la cola original
    priority_queue<string, vector<string>, greater<string>> copia = tareas;
    while (!copia.empty()){
        cout << copia.top() << endl;
        copia.pop();
    }
    return 0;
}