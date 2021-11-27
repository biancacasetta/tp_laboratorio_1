#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

int menu()
{
    int option;

    printf("          SISTEMA DE EMPLEADOS           \n");
    printf("-----------------------------------------\n\n");
    printf("1. Dar de alta\n");
    printf("2. Modificar\n");
    printf("3. Dar de baja\n");
    printf("4. Informes\n");
    printf("5. Salir\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &option);

    return option;
}

int editSubMenu()
{
    int option;

    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Salario\n");
    printf("4. Sector\n");
    printf("5. Cancelar\n\n");
    printf("Seleccione el dato que desea modificar: ");
    scanf("%d", &option);
    printf("\n");

    return option;
}

int sortSubMenu()
{
    int option;

    system("cls");
    printf("                  INFORMES                    \n");
    printf("----------------------------------------------\n\n");
    printf("1. Informar empleados por apellido y sector\n");
    printf("2. Informar total y promedio de salarios\n");
    printf("3. Cancelar\n\n");
    printf("Ingrese la opcion de informe: ");
    scanf("%d", &option);

    return option;
}

int justLetters(char string[])
{
    int error=0;
    int i=0;

    if(string!=NULL)
    {
        while(string[i]!='\0')
        {
            if((!isalpha(string[i]) && string[i]!=' ') || string[0]==' ')
            {
                error=-1;

                while(error<0)
                {
                    printf("Solo puede ingresar letras. Intentelo de nuevo (hasta 20 caracteres): ");
                    gets(string);
                    error=0;
                    i=0;
                }
            }
            i++;
        }
    }
    return error;
}

int capitalisation(char string[])
{
    int error=-1;
    int i=0;

    strlwr(string);
    string[0]=toupper(string[0]);

    while(string[i]!='\0')
    {
        if(string[i]==' ')
        {
            string[i+1]=toupper(string[i+1]);
            error=0;
        }
        i++;
    }
    return error;
}

int checkString(char string[], char message[], char errorMessage[], int min, int max)
{
    int error=-1;
	char aux[100];

	if(string!=NULL && message!=NULL && errorMessage!=NULL && max>0)
	{
		printf("%s", message);
		fflush(stdin);
		gets(aux);
		justLetters(aux);

		while(strlen(aux)<min|| strlen(aux)>max)
		{
			printf("%s", errorMessage);
			fflush(stdin);
			gets(aux);
			justLetters(aux);
		}
		capitalisation(aux);

		strcpy(string, aux);
		error=0;
	}

	return error;
}

int checkCharacter(char* character, char message[], char errorMessage[], char validCharacter1, char validCharacter2)
{
    int error=-1;
    char inputCharacter;

	if(character!=NULL && message!=NULL && errorMessage!=NULL)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%c", &inputCharacter);
		inputCharacter=toupper(inputCharacter);

		while(inputCharacter!=validCharacter1 && inputCharacter!=validCharacter2)
		{
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%c", &inputCharacter);
			inputCharacter=toupper(inputCharacter);
		}

        *character=inputCharacter;
		error=0;
	}

	return error;
}

int justNumbers(char* numbers)
{
	int error=0;

	if(strlen(numbers)>0)
    {
        for(int i=0; i<strlen(numbers); i++)
        {
            if(!isdigit(numbers[i]))
            {
                if(!i && numbers[0]=='-')
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

int checkFloat(float* number, char message[], char errorMessage[], float min, float max)
{
    int error=-1;
    char inputNumber[20];

	if(number!=NULL && message!= NULL && errorMessage!=NULL && min<max)
	{
		printf("%s", message);
		gets(inputNumber);
		fflush(stdin);

		while(justNumbers(inputNumber) || atoi(inputNumber)<min || atoi(inputNumber)>max)
		{
			printf("%s", errorMessage);
			gets(inputNumber);
			fflush(stdin);
		}

        *number=atoi(inputNumber);
		error=0;
	}

	return error;
}

int checkInteger(int* number, char message[], char errorMessage[], int min, int max)
{
    int error=-1;
    char inputNumber[20];

	if(number!=NULL && message!= NULL && errorMessage!=NULL && min<max)
	{
		printf("%s", message);
		gets(inputNumber);
		fflush(stdin);

		while(justNumbers(inputNumber) || atoi(inputNumber)<min || atoi(inputNumber)>max)
		{
			printf("%s", errorMessage);
			gets(inputNumber);
			fflush(stdin);
		}

        *number=atoi(inputNumber);
		error=0;
	}

	return error;
}
