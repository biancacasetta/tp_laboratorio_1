/*
 * BibliotecaCasetta.h
 *
 *  Created on: Sep 6, 2021
 *      Author: Bianca
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef BIBLIOTECACASETTA_H_
#define BIBLIOTECACASETTA_H_

/**
 * @fn int menu(int, int, int, int)
 * @brief Muestra un men� con 5 opciones para realizar operaciones matem�ticas, simulando una calculadora.
 *
 * @param operando1 es el primer operando.
 * @param operando2 es el segundo operando.
 * @param bandera1 indica si ya se ha ingresado el primer operando o no (para poder continuar con el segundo).
 * @param bandera2 indica si ya se ha ingresado el segundo operando o no (para poder continuar con el c�lculo de las operaciones).
 * @return El n�mero de opci�n seleccionado (del 1 al 5).
 */
int menu(int operando1, int operando2, int bandera1, int bandera2);

/**
 * @fn int sumar(int, int)
 * @brief Se realiza la suma de dos n�meros.
 *
 * @param a es el primer sumando.
 * @param b es el segundo sumando.
 * @return La suma de los dos n�meros.
 */
int sumar(int a, int b);

/**
 * @fn int restar(int, int)
 * @brief Se realiza la resta de dos n�meros.
 *
 * @param a es el minuendo.
 * @param b es el sustraendo.
 * @return La resta de los dos n�meros.
 */
int restar(int a, int b);

/**
 * @fn int dividir(int, int, float*)
 * @brief Se realiza la divisi�n de un n�mero por otro.
 *
 * @param a es el dividendo.
 * @param b es el divisor.
 * @param resultado almacena el cociente de la divisi�n en la direcci�n de memoria de un puntero float.
 * @return 1 en caso de haber realizado la divisi�n con �xito, 0 si hubo error (divisi�n por 0).
 */
int dividir(int a, int b, float* resultado);

/**
 * @fn int multiplicar(int, int)
 * @brief Se realiza la multiplicaci�n de dos n�meros.
 *
 * @param a es el primer factor.
 * @param b es el segundo factor.
 * @return El producto de la operaci�n.
 */
int multiplicar(int a, int b);

/**
 * @fn int factorial(int, int*)
 * @brief Se calcula el factorial de un n�mero entero y positivo.
 *
 * @param a es el n�mero entero y positivo del que se calcular� el factorial.
 * @param resultado almacena el valor final de la operaci�n en la direcci�n de memoria de un puntero entero.
 * @return 1 en caso de haber calculado el factorial con �xito, 0 en caso de recibir un n�mero negativo.
 */
int factorial(int a, int* resultado);


#endif /* BIBLIOTECACASETTA_H_ */


