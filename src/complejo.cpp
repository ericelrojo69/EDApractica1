/**
 * Practica 1.
 *
 * Practicas Estructuras de Datos y Algoritmos
 * Curso 2022 - 2023
 *
 * (c) Departament d'Informatica.
 *     Universitat de Valencia
 *
 * @file complejo.cpp
 * @autor Eric Navarro Mattick
 * @autor Oscar Adam Valent
 * @date 10/10/2022
 * @version 1.0
 */

#include <iostream>
#include <assert.h>
#include <cmath>
#include "complejo.h"

using namespace std;

/** 
 * Diferencia maxima que se considera cero al comparar dos reales
 */
const float CERO = 0.0001;

/**
 * Implementando metodo inv
 * @return booleano Si el modulo y el argumento estan dentro del rango
 */
bool Complejo::inv() {
     
      /**
      *  Comprobar que el modulo este dentro del rango adecuado
      */
     assert( (mod >= O)  && "Error, el modulo debe ser igual o mayor que 0" );
     
     /**
      * Comprobamos que no este fuera del rango el argumento
      */
     assert( (-M_PI <= arg <= M_PI)  && "Error, las coordenadas deben estar entre -PI y PI" );
     
    return (mod >= 0) && (arg >= -M_PI) && (arg <= M_PI);
}

/**
 * Constructor
 * @param[in] m Modulo
 * @param[in] a Argumento
 * @return Objeto Complejo
 */
Complejo::Complejo(float m, float a) 
{
    mod = m;
    arg = a;
     
     /**
     * Comprobamos el modulo y el argumento 
     */
    inv();
}



/**
 * Implementando metodo operador igual
 * @param[in] c Objeto complejo
 * @return Booleano Si equivalete un numero complejo a otro
 */
bool Complejo::operator==( const Complejo c ) const {
    if (mod == 0 && c.mod == 0)
        return true;
    else
        return (fabs( mod - c.mod ) < CERO && fabs( arg - c.arg ) < CERO);
}

/**
 * Implementando operador suma
 * @param[in] c Objeto complejo
 * @return Booleano Si equivalete un numero complejo a otro
 */

Complejo Complejo::operator+( const Complejo c ) const {
    Complejo result;
    result.setRec( getReal() + c.getReal(), getImag() + c.getImag() );
    
     /**
     * Comprobamos el argumento enten dentro del rango
     */
    (-M_PI <= result.arg <= M_PI)  && "Error, las coordenadas deben estar entre -PI y PI" );
    
    /**
     * Comprobamos que no este fuera del rango el modulo
     */
    assert( (result.mod  >= 0)  && "Error, el modulo debe ser igual o mayor que 0" );
    
    return result;
}

/**
 * Implementando operador multiplicacion
 * @param[in] c Objeto complejo
 * @return Objeto Complejo
 */
Complejo Complejo::operator*(const Complejo c) const {

    float new_arg = c.arg + arg;

    /**
     * Simplificamos los gradianes si se salen de rango
     */

    if ( not(-M_PI <= new_arg <= M_PI)  ){
        for (int i = 0; i < new_arg / 2*M_PI;  ) {
            new_arg =- 2*M_PI;
        }

    }
    
     /**
     * Comprobamos el argumento enten dentro del rango
     */
    (-M_PI <= new_arg <= M_PI)  && "Error, las coordenadas deben estar entre -PI y PI" );
    
    /**
     * Comprobamos que no este fuera del rango el modulo
     */
    assert( (mod * c.mod  >= 0)  && "Error, el modulo debe ser igual o mayor que 0" );
    return { mod * c.mod, new_arg };
}

/**
 * Implementando metodo imprimir
 *  @return Imprime mensaje texto del modulo y el argumento
 */
void Complejo::print() const {
    cout << "Modulo: " << mod << "\n";
    cout << "Argumento: " << arg << "\n";
}

// Setters

/**
 * Implementando set de complejo
 *  @param[in] m Modulo
 *  @param[in] a Argumento
 */
void Complejo::set(float m, float a) {
    
    if(-M_PI <= m <= M_PI) {
        arg = a;
    }
    
    /**
     * Comprobamos el argumento enten dentro del rango
     */
    assert(-M_PI <= m <= M_PI)  && "Error, las coordenadas deben estar entre -PI y PI" );
    
     if(a  >= 0) {
        mod = m;
    }
    
    /**
     * Comprobamos que no este fuera del rango el modulo
     */
    assert( a  >= 0)  && "Error, el modulo debe ser igual o mayor que 0" );
    
    
}

/**
 * Implementando metodo set complejo si usamos forma binomica
 *  @param[in] re Coordenada real
 *  @param[in] im Coordenada imaginaria
 */
void Complejo::setRec( float re, float im ) {
    mod = sqrt( re * re + im * im );
    if (re == 0 && im == 0)
        arg = 0;
    else
        arg = atan2( im, re );

    assert(inv());
}

// Getters
/**
 * Implementando devolver parte real
 *  @return Devuelve la parte real
 */

float Complejo::getReal() const {
    return mod * cos( arg );
}

/**
 * Implementando devolver parte imaginaria
 *  @return Devuelve la parte imaginaria
 */
float Complejo::getImag() const {
    return mod * sin( arg );

}
