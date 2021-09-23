/*
 * BibliotecaCasetta.c
 *
 *  Created on: Sep 6, 2021
 *      Author: Bianca
 */
#include <stdio.h>
#include <stdlib.h>
#include "Casetta.h"

int menu(int operando1, int operando2, int bandera1, int bandera2)
    {
        int opcion;

        printf("Menú de opciones:\n\n");

        if(bandera1)
        {
            printf("1. Ingresar 1er operando (A=%d)\n", operando1);
        }
        else
        {
            printf("1. Ingresar 1er operando (A)\n");
        }

        if(bandera2)
        {
            printf("2. Ingresar 2do operando (B=%d)\n", operando2);
        }
        else
        {
            printf("2. Ingresar 2do operando (B)\n");
        }
        printf("3. Calcular todas las operaciones\n");
        printf("	a) Calcular la suma (A+B)\n");
        printf("	b) Calcular la resta (A-B)\n");
        printf("	c) Calcular la division (A/B)\n");
        printf("	d) Calcular la multiplicacion (A*B)\n");
        printf("	e) Calcular el factorial (A! y B!)\n");
        printf("4. Informar resultados\n");
        printf("	a) \"El resultado de A+B es: r\"\n");
        printf("	b) \"El resultado de A-B es: r\"\n");
        printf("	c) \"El resultado de A/B es: r\" o \"No es posible dividir por cero.\"\n");
        printf("	d) \"El resultado de A*B es: r\"\n");
        printf("	e) \"El factorial de A es: r1 y el factorial de B es: r2\"\n");
        printf("5. Salir\n\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        return opcion;
    }

int sumar(int a, int b)
{
	return a+b;
}

int restar(int a, int b)
{
	return a-b;
}

int dividir(int a, int b, float* resultado)
{
    int todoOk=0;

	if(b!=0 && resultado!=NULL)
	{
		*resultado=(float)a/b;
		todoOk=1;
	}

	return todoOk;
}

int multiplicar(int a, int b)
{
	return a*b;
}

int factorial(int a, int* resultado)
{
	int i;
    *resultado=1;
	int todoOk=0;

	if(a>=0 && resultado!=NULL)
    {
        for(i=a; i>0; i--)
        {
            *resultado*=i;
        }
        todoOk=1;
    }

	return todoOk;
}


