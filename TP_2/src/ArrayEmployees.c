#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

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
    printf("Ingrese una opción: ");
    scanf("%d", &option);

    return option;
}

int initEmployees(Employee list[], int len)
{
    int error=-1;

    if(list!=NULL && len>0)
    {
        for(int i=0;i<len;i++)
        {
            list[i].isEmpty=1;
        }
        error=0;
    }
    return error;
}

int availability(Employee list[], int len)
{
    int availableIndex=-1;

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty)
            {
                availableIndex=i;
                break;
            }
        }
    }
    return availableIndex;
}

void printEmployee(Employee anEmployee, int len)
{
    printf("%-5d%-21s%-21s%-14.2f%-11d\n",
           anEmployee.id,
           anEmployee.name,
           anEmployee.lastName,
           anEmployee.salary,
           anEmployee.sector);
}

int printEmployees(Employee list[], int len)
{
    int error=1;
    int i;
    int flag=0;

    if(list!=NULL && len>0)
    {
        printf(" ID |       NOMBRE       |      APELLIDO      |   SALARIO   |  SECTOR  \n");
        printf("-----------------------------------------------------------------------\n");

        for(i=0; i<len; i++)
        {
            if(!list[i].isEmpty)
            {
                printEmployee(list[i], len);
                flag=1;
            }
        }

        printf("\n");

        if(!flag)
        {
            printf("No hay empleados para mostrar.\n\n");
        }
        error=0;
    }

    return error;
}

int justLetters(char string[])
{
    int error=0;
    int i=0;

    if(string!=NULL)
    {
        while(string[i]!='\0')
        {
            if(!isalpha(string[i]) && string[i]!=' ')
            {
                error=-1;

                while(error<0)
                {
                    printf("Solo puede ingresar letras. Inténtelo de nuevo (hasta 20 caracteres): ");
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

int checkFloat(float* number, char message[], char errorMessage[], float min, float max)
{
    int error=-1;
    float inputNumber;

	if(number!=NULL && message!= NULL && errorMessage!=NULL && min<max)
	{
		printf("%s", message);
		scanf("%f", &inputNumber);

		while(inputNumber<min || inputNumber>max)
		{
			printf("%s", errorMessage);
			scanf("%f", &inputNumber);
		}

        *number=inputNumber;
		error=0;
	}

	return error;
}

int checkInteger(int* number, char message[], char errorMessage[], int min, int max)
{
    int error=-1;
    int inputNumber;

	if(number!=NULL && message!= NULL && errorMessage!=NULL && min<max)
	{
		printf("%s", message);
		scanf("%d", &inputNumber);

		while(inputNumber<min || inputNumber>max)
		{
			printf("%s", errorMessage);
			scanf("%d", &inputNumber);
		}

        *number=inputNumber;
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

int addEmployee(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector)
{
    int error=-1;
    int availableIndex;

    if(list!=NULL && len>0 && name!=NULL && lastName!=NULL)
    {
        availableIndex=availability(list, len);

        if(availableIndex>=0)
        {
            list[availableIndex].id=id;

            system("cls");
            printf("                         ALTA DE EMPLEADO                         \n");
            printf("------------------------------------------------------------------\n\n");

            checkString(name,
                        "Ingrese el/los nombre(s) del empleado (1 a 20 caracteres): ",
                        "Nombre demasiado largo. Ingrese el/los nombre(s) del empleado (1 a 20 caracteres): ",
                        1,
                        20);
            strcpy(list[availableIndex].name, name);

            checkString(lastName,
                        "Ingrese el/los apellido(s) del empleado (1 a  20 caracteres): ",
                        "Apellido demasiado largo. Ingrese el/los apellido(s) del empleado (1 a 20 caracteres): ",
                        1,
                        20);
            strcpy(list[availableIndex].lastName, lastName);

            checkFloat(&salary,
                       "Ingrese el salario del empleado (mayor a 0): ",
                       "Salario inválido. Ingrese el salario del empleado (mayor a 0): ",
                       0.00,
                       1000000.00);
            list[availableIndex].salary=salary;

            checkInteger(&sector,
                         "Ingrese el sector del empleado: ",
                         "Sector inválido. Ingrese el sector del empleado: ",
                         0,
                         100);
            list[availableIndex].sector=sector;

            list[availableIndex].isEmpty=0;

            printf("\nAlta exitosa.\n");
            printf("Se ha dado de alta al siguiente empleado: \n\n");

            printf(" ID |       NOMBRE       |      APELLIDO      |   SALARIO   |  SECTOR  \n");
            printf("-----------------------------------------------------------------------\n");
            printEmployee(list[availableIndex], len);
            printf("\n");

            error=0;
        }
        else
        {
            printf("\nNo hay más lugar disponible para nuevas altas.\n\n");
        }
    }

    return error;
}

int findEmployeeById(Employee list[], int len, int id)
{
    int idIndex=-1;
    int i;

    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(!list[i].isEmpty && list[i].id==id)
            {
                idIndex=i;
            }
        }
    }
    return idIndex;
}

int removeEmployee(Employee list[], int len, int id)
{
    int error=-1;
    int idIndex;
    char confirmation;

    if(list!=NULL && len>0)
    {
        system("cls");
        printf("                          BAJA DE EMPLEADO                       \n");
        printf("-----------------------------------------------------------------\n");
        printEmployees(list, len);
        printf("\nIngrese el ID del empleado a dar de baja: ");
        scanf("%d", &id);
        printf("\n");

        idIndex=findEmployeeById(list, len, id);

        if(idIndex>=0)
        {
            printf(" ID |       NOMBRE       |      APELLIDO      |   SALARIO   |  SECTOR  \n");
            printf("-----------------------------------------------------------------------\n");
            printEmployee(list[idIndex], len);

            checkCharacter(&confirmation,
                           "\nConfirmar baja (S/N): ",
                           "Respuesta inválida. Confirmar baja (S/N): ",
                           'S',
                           'N');

            if(confirmation=='S')
            {
                list[idIndex].isEmpty=1;
                error=0;

                system("cls");
                printf("\nBaja exitosa.\n");
                printf("Se ha dado de baja al siguiente empleado: \n\n");
                printf(" ID |       NOMBRE       |      APELLIDO      |   SALARIO   |  SECTOR  \n");
                printf("-----------------------------------------------------------------------\n");
                printEmployee(list[idIndex], len);
                printf("\n");
            }
        }
        else
        {
            printf("No existe el ID ingresado.\n\n");
        }
    }
    return error;
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

int editEmployee(Employee list[], int len, int id)
{
    int error=-1;
    int idIndex;
    int option;
    Employee auxEmployee;

    if(list!=NULL && len>0)
    {
        system("cls");
        printf("                          MODIFICAR EMPLEADO                       \n");
        printf("-------------------------------------------------------------------\n");
        //Hago un burbujeo antes de mostrar la lista de empleados para ordenarlos por apellido
        //y no por ID ascendente que es el default, ya que el usuario puede no saber el ID
        //y no tiene sentido ordenar el listado por un dato que el usuario desconoce.

        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].lastName, list[j].lastName)>0 ||
                  (list[i].lastName==list[j].lastName && strcmp(list[i].name, list[j].name)>0))
                {
                    auxEmployee=list[i];
                    list[i]=list[j];
                    list[j]=auxEmployee;
                }
            }
        }
        printEmployees(list, len);

        printf("\nIngrese el ID del empleado a modificar: ");
        scanf("%d", &id);
        printf("\n");

        idIndex=findEmployeeById(list, len, id);

        if(idIndex>=0)
        {
            system("cls");
            printf(" ID |       NOMBRE       |      APELLIDO      |   SALARIO   |  SECTOR  \n");
            printf("-----------------------------------------------------------------------\n");
            printEmployee(list[idIndex], len);
            printf("\n");

            option=editSubMenu();

            switch(option)
            {
                case 1:
                    checkString(auxEmployee.name,
                                "Ingrese el/los nombre(s) del empleado (1 a 20 caracteres): ",
                                "Nombre demasiado corto/largo. Ingrese el/los nombre(s) del empleado (1 a 20 caracteres): ",
                                1,
                                20);
                    strcpy(list[idIndex].name, auxEmployee.name);
                    break;
                case 2:
                    checkString(auxEmployee.lastName,
                                "Ingrese el/los apellido(s) del empleado (1 a 20 caracteres): ",
                                "Apellido demasiado corto/largo. Ingrese el/los apellido(s) del empleado (1 a 20 caracteres): ",
                                1,
                                20);
                    strcpy(list[idIndex].lastName, auxEmployee.lastName);
                    break;
                case 3:
                    checkFloat(&auxEmployee.salary,
                               "Ingrese el salario del empleado (mayor a 0): ",
                               "Salario inválido. Ingrese el salario del empleado (mayor a 0): ",
                               0.00,
                               1000000.00);

                               list[idIndex].salary=auxEmployee.salary;
                    break;
                case 4:
                    checkInteger(&auxEmployee.sector,
                                 "Ingrese el sector del empleado: ",
                                 "Sector inválido. Ingrese el sector del empleado: ",
                                 0,
                                 100);

                                 list[idIndex].sector=auxEmployee.sector;
                    break;
                case 5:
                    printf("\n");
                    break;
                default:
                    printf("Opción inválida. Ingrese una opción del 1 al 5.\n");
                    break;
            }

            if(option<5)
            {
                system("cls");
                printf("Modificación exitosa.\n");
                printf("Se ha modificado al siguiente empleado: \n\n");
                printf(" ID |       NOMBRE       |      APELLIDO      |   SALARIO   |  SECTOR  \n");
                printf("-----------------------------------------------------------------------\n");
                printEmployee(list[idIndex], len);
                printf("\n");
            }

            error=0;
        }
        else
        {
            printf("No existe el ID ingresado.\n\n");
        }
    }
    return error;
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
    printf("Ingrese la opción de informe: ");
    scanf("%d", &option);

    return option;
}

int calculateSalary(Employee list[], int len)
{
    int error=-1;

    int salarySum=0;
    int salaryQuantity=0;
    int aboveAverageSalary=0;
    float average;

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(!list[i].isEmpty)
            {
                salarySum+=list[i].salary;
                salaryQuantity++;
            }
        }

        average=salarySum/salaryQuantity;

        printf("El total de salarios es %d.\n", salarySum);
        printf("El promedio de salarios es %.2f.\n\n", average);

        printf(" ID |       NOMBRE       |      APELLIDO      |   SALARIO   |  SECTOR  \n");
        printf("-----------------------------------------------------------------------\n");

        for(int i=0; i<len; i++)
        {
            if(!list[i].isEmpty && list[i].salary>average)
            {
                aboveAverageSalary++;
                printEmployee(list[i], len);
            }
        }

        printf("\nLos empleados con salario mayor al promedio son %d.\n\n", aboveAverageSalary);

        error=0;
    }
    return error;
}

int sortEmployees(Employee list[], int len, int order)
{
    int error=-1;
    Employee auxEmployee;
    int option;

    if(list!=NULL && len>0)
    {
        switch(sortSubMenu())
        {
            case 1:
                system("cls");
                printf("         LISTADO POR APELLIDO Y SECTOR        \n");
                printf("----------------------------------------------\n\n");
                printf("1. Orden ascendente (A-Z)\n");
                printf("2. Orden descendente (Z-A)\n\n");
                printf("Ingrese el orden: ");
                scanf("%d", &option);

                switch(option)
                {
                    case 1:
                        order=1;

                        for(int i=0; i<len-1; i++)
                        {
                            for(int j=i+1; j<len; j++)
                            {
                                if(strcmp(list[i].lastName, list[j].lastName)>0 ||
                                  (!strcmp(list[i].lastName, list[j].lastName) && list[i].sector>list[j].sector))
                                {
                                    auxEmployee=list[i];
                                    list[i]=list[j];
                                    list[j]=auxEmployee;
                                }
                            }
                        }

                        system("cls");
                        printf("                        LISTADO ASCENDENTE                       \n");
                        printf("-----------------------------------------------------------------\n");
                        printEmployees(list, len);
                        break;
                    case 2:
                        order=0;

                        for(int i=0; i<len-1; i++)
                        {
                            for(int j=i+1; j<len; j++)
                            {
                                if(strcmp(list[i].lastName, list[j].lastName)<0 ||
                                  (!strcmp(list[i].lastName, list[j].lastName) && list[i].sector<list[j].sector))
                                {
                                    auxEmployee=list[i];
                                    list[i]=list[j];
                                    list[j]=auxEmployee;
                                }
                            }
                        }

                        system("cls");
                        printf("                       LISTADO DESCENDENTE                       \n");
                        printf("-----------------------------------------------------------------\n");
                        printEmployees(list, len);
                        break;
                    default:
                        printf("Opcion invalida.");
                        break;
                }
                break;
            case 2:
                system("cls");
                printf("                   TOTAL Y PROMEDIO DE SALARIOS                  \n");
                printf("-----------------------------------------------------------------\n\n");
                calculateSalary(list, len);
                break;
            case 3:
                printf("\n");
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
        error=0;
    }

    return error;
}
