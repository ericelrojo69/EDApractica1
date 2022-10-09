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
 */

#include <cstdlib>
#include <iostream>
#include <cassert>
#include <assert.h>
#include <cmath>

#include "complejo.h"

using namespace std;

/** 
 * Diferencia maxima que se considera cero al comparar dos reales
 */
const float CERO = 0.0001;

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

bool Complejo::inv() {
    return mod >= 0 && arg >= -M_PI && arg <= M_PI;
}

bool Complejo::operator==(const Complejo c) const 
{
    if(mod == 0 && c.mod == 0)
        return true;
    else
        return (fabs(mod - c.mod) < CERO && fabs(arg - c.arg) < CERO);
}

void Complejo::setRec(float re, float im) 
{
    mod = sqrt(re*re + im*im);
    if(re == 0 && im == 0)
        arg = 0;
    else
        arg = atan2(im, re);

    assert(inv() );
}

float Complejo::getReal() const 
{
    return mod * cos(arg);
}

float Complejo::getImag() const 
{
    return mod * sin(arg);
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


    return { mod * c.mod, new_arg };
}