#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool esPar(int n){
    if((n % 2) == 0){ // Si el residuo al dividir por 2 es cero, es par
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

    // Si no se encontró ningún número par (el iterador apunta al final del vector)
    if (it == entrada.end()){
        return -1; // Se devuelve -1 como indicador de que no se encontró un número par
    }
    else{
        return *it; // Se devuelve el número par encontrado
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
    // Se recorre el string de entrada
    // Se usa un iterador para recorrer la linea
    for(string::iterator it = entrada.begin(); it != entrada.end(); it++){
        // Se verifica si el elemento actual es un dígito
        // Se usa la función isdigit para verificar si el elemento actual es un dígito
        if(isdigit(*it)){
            // Se almacena el dígito en la variable numero_temp
            numero_temp += *it;
        }
        else{
            // Si el carácter no es un dígito y numero_temp no está vacío,
            // se convierte en entero y se agrega al vector
            if(numero_temp != ""){
                v.push_back(stoi(numero_temp));
                numero_temp = ""; // Se limpia la variable temporal para el siguiente número
            }
        }
    }
    // Si al final del string queda un número pendiente, se agrega al vector
    if(numero_temp != ""){
        v.push_back(stoi(numero_temp));
        numero_temp = "";
    }
    // Se llama a la función primerPar para obtener el primer número par del vector
    int salida = primerPar(v); 

    // Se muestra el resultado según si se encontró o no un número par
    if (salida == -1){
        cout << "No hay números pares" << endl;
    }
    else{
        cout << "El primer número par del vector es: " << salida << endl;

    }
    return 0;
}