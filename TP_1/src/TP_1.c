/*
 ============================================================================
 Name        : TP_1.c
 Author      : Bianca
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Casetta.h"

int main(void)
{
	setbuf(stdout,NULL);

	char seguir='s';
	    char salir;
	    int a;
	    int b;
	    int opcion1=0;
	    int opcion2=0;
	    int opcion3=0;
	    int suma;
	    int resta;
	    int resultadoDivision;
	    int resultadoFactorial1;
	    int resultadoFactorial2;
	    float cociente;
	    int producto;
	    int factorial1;
	    int factorial2;

	    do
	    {
	        system("cls");

	        switch(menu(a, b, opcion1, opcion2))
	        {
	        	case 1:
	        		printf("Ingresar 1er operando (A): ");
	                scanf("%d", &a);
	                opcion1=1;
	                break;
	            case 2:
	                if(opcion1)
	                {
	                    printf("Ingresar 2do operando (B): ");
	                    scanf("%d", &b);
	                    opcion2=1;
	                }
	                else
	                {
	                    printf("Debe ingresar el 1er operando antes de ingresar el 2do.\n");
	                }
	                break;
	            case 3:
	                if(opcion2)
	                {
	                    printf("3. Se calcularon todas las operaciones:\n");
	                    printf("	a) Calcular la suma (%d+%d)\n", a, b);
	                    printf("	b) Calcular la resta (%d-%d)\n", a, b);
	                    printf("	c) Calcular la división (%d/%d)\n", a, b);
	                    printf("	d) Calcular la multiplicación (%d*%d)\n", a, b);
	                    printf("	e) Calcular el factorial (%d! y %d!)\n", a, b);

	                    suma=sumar(a, b);
	                    resta=restar(a, b);
	                    resultadoDivision=dividir(a, b, &cociente);
	                    producto=multiplicar(a, b);
	                    resultadoFactorial1=factorial(a, &factorial1);
	                    resultadoFactorial2=factorial(b, &factorial2);

	                    opcion3=1;
	                }
	                else
	                {
	                    printf("Debe ingresar ambos operandos antes de calcular las operaciones.\n");
	                }
	                break;
	            case 4:
	                if(opcion3)
	                {
	                    printf("4. Informe de resultados\n");
	                    printf("	a) El resultado de %d+%d es: %d\n", a, b, suma);
	                    printf("	b) El resultado de %d-%d es: %d\n", a, b, resta);
	                    if(resultadoDivision)
	                    {
	                        printf("	c) El resultado de %d/%d es: %.2f\n", a, b, cociente);
	                    }
	                    else
	                    {
	                        printf("        c) No es posible dividir por cero.\n");
	                    }
	                    printf("	d) El resultado de %d*%d es: %d\n", a, b, producto);

	                    if(resultadoFactorial1)
	                    {
	                        printf("	e1) El factorial de %d es: %d.\n", a, factorial1);
	                    }
	                    else
	                    {
	                        printf("    e1) No se puede calcular el factorial de %d.\n", a);
	                    }

	                    if(resultadoFactorial2)
	                    {
	                        printf("        e2) El factorial de %d es: %d.\n", b, factorial2);
	                    }
	                    else
	                    {
	                        printf("        e2) No se puede calcular el factorial de %d.\n", b);
	                    }

	                    printf("Puede salir o comenzar de nuevo.\n");

	                    opcion1=0;
	                    opcion2=0;
	                    opcion3=0;
	                }
	                else
	                {
	                    printf("Debe calcular las operaciones antes de informar los resultados.\n");
	                }
	                break;
	            case 5:
	                printf("¿Desea salir? s/n: ");
	                fflush(stdin);
	                scanf("%c", &salir);

	                if(salir=='s')
	                {
	                    seguir='n';
	                }
	                break;
	            default:
	                printf("Ingrese una opción válida del 1 al 5.\n");
	                break;
	        }

	        system("pause");
	    }
	    while(seguir=='s');

	return EXIT_SUCCESS;

}
