#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

int menu()
{
    int opcion;

    printf("                             SISTEMA DE EMPLEADOS                            \n");
    printf("-----------------------------------------------------------------------------\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
    printf("10. Salir\n\n");
    printf("Ingrese una opción: ");
    scanf("%d", &opcion);
    fflush(stdin);

    return opcion;
}

int subMenuModificar()
{
    int opcion;

    printf("\n            MODIFICAR EMPLEADO        \n");
    printf("--------------------------------------\n\n");
    printf("1. Nombre\n");
    printf("2. Horas trabajadas\n");
    printf("3. Sueldo\n");
    printf("4. Cancelar modificación\n\n");
    printf("Ingrese una opción: ");
    scanf("%d", &opcion);
    fflush(stdin);
    printf("\n");

    return opcion;
}

int subMenuOrdenar()
{
    int opcion;

    printf("1. Por ID\n");
    printf("2. Por nombre\n");
    printf("3. Por horas trabajadas\n");
    printf("4. Por sueldo\n");
    printf("5. Cancelar ordenamiento\n\n");
    printf("Seleccione el orden que desea mostrar: ");
    scanf("%d", &opcion);
    fflush(stdin);
    printf("\n");

    return opcion;
}

int subMenuCriterio()
{
    int opcion;

    printf("1. Ascendente (A-Z)/(0-9)\n");
    printf("2. Descendente (Z-A)/(9-0)\n\n");
    printf("Seleccione el criterio de ordenamiento: ");
    scanf("%d", &opcion);
    fflush(stdin);

    return opcion;
}

int soloLetras(char cadena[])
{
    int error=0;
    int i=0;

    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(!isalpha(cadena[i]) && cadena[i]!=' ')
            {
                error=-1;

                while(error<0)
                {
                    printf("Solo puede ingresar letras. Inténtelo de nuevo: ");
                    fflush(stdin);
                    gets(cadena);
                    error=0;
                    i=0;
                }
            }
            else
            {
            	i++;
            }
        }
    }
    return error;
}

int inicialMayuscula(char cadena[])
{
    int error=-1;
    int i=0;

    strlwr(cadena);
    cadena[0]=toupper(cadena[0]);

    while(cadena[i]!='\0')
    {
        if(cadena[i]==' ')
        {
            cadena[i+1]=toupper(cadena[i+1]);
            error=0;
        }
        i++;
    }
    return error;
}

int validarCadena(char cadena[], char mensaje[], char mensajeError[], int min, int max)
{
    int error=-1;
	char aux[100];

	if(cadena!=NULL && mensaje!=NULL && mensajeError!=NULL && min>0 && max>min)
	{
		printf("%s", mensaje);
		fflush(stdin);
		gets(aux);
		soloLetras(aux);

		while(strlen(aux)<=min|| strlen(aux)>=max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			gets(aux);
			soloLetras(aux);
		}
		inicialMayuscula(aux);

		strcpy(cadena, aux);
		error=0;
	}

	return error;
}

int validarCaracter(char* caracter, char mensaje[], char mensajeError[], char caracterValido1, char caracterValido2)
{
    int error=-1;
    char caracterIngresado;

	if(caracter!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &caracterIngresado);
		caracterIngresado=toupper(caracterIngresado);

		while(caracterIngresado!=caracterValido1 && caracterIngresado!=caracterValido2)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%c", &caracterIngresado);
			caracterIngresado=toupper(caracterIngresado);
		}

        *caracter=caracterIngresado;
		error=0;
	}

	return error;
}

int soloNumeros(char* numeros)
{
	int error=0;

	if(strlen(numeros)>0)
    {
        for(int i=0; i<strlen(numeros); i++)
        {
            if(!isdigit(numeros[i]))
            {
                if(!i && numeros[0]=='-')
                {
                    error=0;
                }
                else
                {
                    error=1;
                }
            }
        }
    }
    else
    {
        error=1;
    }

	return error;
}

int validarEntero(int* numero, char mensaje[], char mensajeError[], int min, int max)
{
    int error=-1;
    char numeroIngresado[20];

	if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL && min<max)
	{
		printf("%s", mensaje);
		gets(numeroIngresado);
		fflush(stdin);

        while(soloNumeros(numeroIngresado) || atoi(numeroIngresado)<=min || atoi(numeroIngresado)>=max)
		{
			printf("%s", mensajeError);
			gets(numeroIngresado);
			fflush(stdin);
		}

        *numero=atoi(numeroIngresado);
		error=0;
	}

	return error;
}
