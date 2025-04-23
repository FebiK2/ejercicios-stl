#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<pair<int,string>> ordenamiento(vector<pair<int,string>> entrada){
    /*Se puede utilizar el algoritmo de ordenamiento sort de la librería algorithm, debido a
    que este algoritmo por defecto va a ordenar en orden ascendente por el primer elemento de cada vector interno (los enteros)*/
    sort(entrada.begin(),entrada.end());
    return entrada;



}
int main(){
    // Se define unn vector de vectores con dos elementos (un entero y un string)
    vector<pair<int,string>> datos = {{5, "manzana"},{2, "banana"},{8, "naranja"},{1, "uva"},{7, "pera"}};
    datos = ordenamiento(datos);
    // Se utiliza un ciclo for para imprimir el vector de datos ordenado 
    for(int i = 0; i < datos.size(); i++){
        if (datos[i] != datos[0]){
            cout << "{" << datos[i].first << "," << datos[i].second << "}"; 
        }
        else {
            cout << "{" << "{" << datos[i].first << "," << datos[i].second << "}"; 
        }
    }
    cout << "}" << endl;
    return 0;
}