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
 * 
 *
 */
bool Complejo::inv() {
     /**
    * Comprobamos que no este fuera del rango el argumento
    */
    assert( (-M_PI <= new_arg <= M_PI)  && "Error, las coordenadas deben estar entre -PI y PI" );
    return mod >= CERO && arg >= -M_PI && arg <= M_PI;
}

/**
 * Constructor
 * @param[in] m Modulo
 * @param[in] arg Argumento
 * @return Objeto Complejo
 */
Complejo::Complejo(float m, float a) 
{
    assert( (m >= 0)  && "Error, el modulo debe ser igual o mayor que 0" );
    mod = m;

    /**
    *  Comprobar que las cordenadas polares
    *  estan entre -PI y PI+
    */
     assert( (-M_PI <= a <= M_PI)  && "Error, las coordenadas deben estar entre -PI y PI" );
     arg = a;
}



/**
 * Implementando metodo operador igual
 *
 */
bool Complejo::operator==( const Complejo c ) const {
    if (mod == 0 && c.mod == 0)
        return true;
    else
        return (fabs( mod - c.mod ) < CERO && fabs( arg - c.arg ) < CERO);
}

/**
 * Implementando operador suma
 *
 */

Complejo Complejo::operator+( const Complejo c ) const {
    Complejo result;
    result.setRec( getReal() + c.getReal(), getImag() + c.getImag() );

    return result;
}

/**
 * Implementando operador multiplicacion
 *
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
     * Comprobamos que no este fuera del rango el modulo
     */
    assert( (mod * c.mod  >= 0)  && "Error, el modulo debe ser igual o mayor que 0" );
    return { mod * c.mod, new_arg };
}

/**
 * Implementando metodo imprimir
 *
 */
void Complejo::print() const {
    cout << "Modulo: " << mod << "\n";
    cout << "Argumento: " << arg << "\n";
}


// Setters

/**
 * Implementando set de complejo
 *
 */
void Complejo::set(float m, float a) {

}

/**
 * Implementando metodo set complejo si usamos forma binomica
 *
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

float Complejo::getReal() const {
    return mod * cos( arg );
}


float Complejo::getImag() const {
    return mod * sin( arg );

}
