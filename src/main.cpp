/**
 * Practica 1.
 *
 * Practicas Estructuras de Datos y Algoritmos
 * Curso 2022 - 2023
 *
 * (c) Departament d'Informatica.
 *     Universitat de Valencia
 *
 * @file main.cpp
 * @autor Eric Navarro Mattick
 * @autor Oscar Adam Valent
 * @date 10/10/2022
 * @version 1.0
 */


#include <iostream>
#include <vector>
#include "complejo.cpp"
#include <algorithm>

/**
 * Constructor
 * @param[in] complejo1 Objeto de Complejo
 * @param[in] n Numero de elementos
 * @return Vector que contiene numeros complejos
 */
vector<Complejo> genVector(Complejo complejo1, int n){

    vector<Complejo> vector1;

    /**
     * Primer elemento
     */

    vector1.emplace_back(1,0);


    /**
     * Añadimos los otros numeros complejos
     */

    for (int i = 1; i < n; i++) {
        vector1.push_back(vector1.at(i-1) * complejo1 );
    }

    /**
     * Recordenamos de forma inversa los vectores
     */
    reverse(vector1.begin(), vector1.end());

    return vector1;
}

/**
* Main
*/
int main() {

    /**
    * Creamos objeto complejo
    */
    Complejo complejo1 = Complejo(2, M_PI/4);

    /**
    * Generamos el vector de numeros complejos
    */
    vector<Complejo> vectores = genVector(complejo1, 10);

    /**
    * Probamos la suma
    */

    vectores[0].print();
    vectores[1].print();

    complejo1 = vectores[0] + vectores[1];

    std::cout << "La suma de los dos vectores es \n";
    complejo1.print();

    /**
   * Probamos la multiplicacion
   */

    vectores[2].print();
    vectores[3].print();

    complejo1 = vectores[2] + vectores[3];

    std::cout << "La suma de los dos vectores es:\n";
    complejo1.print();



    /**
    * Imprimimos el contenido del generador vectores
    */

    std::cout << "Imprimimos el contenido de generar vectores:\n";
    for(auto complejo: vectores){
        complejo.print();
    }
    
    return 0;
}
