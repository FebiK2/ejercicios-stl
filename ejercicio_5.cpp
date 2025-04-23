#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Para sort

using namespace std;
// Función que ordena un vector de pares (int, string) en orden ascendente por el entero
vector<pair<int,string>> ordenamiento(vector<pair<int,string>> entrada){
    /*Se puede utilizar el algoritmo de ordenamiento sort de la librería algorithm, debido a
    que este algoritmo por defecto va a ordenar en orden ascendente por el primer elemento de cada vector interno (los enteros)*/
    sort(entrada.begin(),entrada.end());
    return entrada;



}
int main(){
    // Se define un vector de pares (int, string), donde cada par representa un número y una fruta
    vector<pair<int,string>> datos = {{5, "manzana"},{2, "banana"},{8, "naranja"},{1, "uva"},{7, "pera"}};
     // Se llama a la función ordenamiento para ordenar el vector
    datos = ordenamiento(datos);
    // Se imprime el vector ordenado
    // Aquí hay una lógica para manejar el primer elemento de forma diferente a los demás
    for(int i = 0; i < datos.size(); i++){
        // Se imprime cada par en el formato {número, fruta}
        if (datos[i] != datos[0]){
            cout << "," << "{" << datos[i].first << "," << datos[i].second << "}"; 
        }
        else {
             // Si es el primer elemento, imprime con doble llave de apertura
            cout << "{" << "{" << datos[i].first << "," << datos[i].second << "}"; 
        }
    }
    // Se imprime la llave de cierre al final
    cout << "}" << endl;
    return 0;
}