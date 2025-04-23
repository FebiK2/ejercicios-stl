#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool esPar(int n){
    if((n % 2) == 0){
        return true;
    }
    else{
        return false;
    }
}
// Se define una función que recibe un vector de enteros y devuelve el primer número par
int primerPar(vector<int> entrada){
    /*Se usa directamente la función find_if de la biblioteca "algorithm", los argumentos son: un punto inicial del rango, 
    un punto final del rango y un predicado, este último es una condición o función booleana que se va evaluando para cada elemento
    del rango definido del find_if*/

    // como find_if devuelve el primer elemento que cumple la condición, se usa un lambda para definir la condición
    vector<int>::iterator it = find_if(entrada.begin(), entrada.end(), esPar);
    if (it == entrada.end()){
        return -1;
    }
    else{
        return *it;
    }
}

int main(){
    // Se le pide al usuario que ingrese el vector, para ello se trabaja inicialmente como un string
    string entrada;
    cout << "Ingrese un vector de números enteros: ";
    cin >> entrada;
    cout << endl;

    // Luego, los números o elementos del string de entrada se consignan en un vector de enteros

    // Se usa un ciclo for y un iterador para la variable entrada de tipo string
    vector<int> v;
    string numero_temp;

    for(string::iterator it = entrada.begin(); it != entrada.end(); it++){
        if(isdigit(*it)){
            numero_temp += *it;
        }
        else{
            if(numero_temp != ""){
                v.push_back(stoi(numero_temp));
                numero_temp = "";
            }
        }
    }
    if(numero_temp != ""){
        v.push_back(stoi(numero_temp));
        numero_temp = "";
    }

    int salida = primerPar(v); 
    if (salida == -1){
        cout << "No hay números pares" << endl;
    }
    else{
        cout << "El primer número par del vector es: " << salida << endl;

    }
    return 0;
}