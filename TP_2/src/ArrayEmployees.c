#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "input.h"

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

void printEmployee(Employee anEmployee)
{
    printf("%-5d%-21s%-21s%-14.2f%-5d\n",
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
        printf(" ID |       NOMBRE       |      APELLIDO      |   SALARIO   | SECTOR \n");
        printf("---------------------------------------------------------------------\n");

        for(i=0; i<len; i++)
        {
            if(!list[i].isEmpty)
            {
                printEmployee(list[i]);
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
                        "Ingrese el/los nombre(s) del empleado (3 a 20 caracteres): ",
                        "Nombre demasiado largo/corto. Ingrese el/los nombre(s) del empleado (3 a 20 caracteres): ",
                        3,
                        20);
            strcpy(list[availableIndex].name, name);

            checkString(lastName,
                        "Ingrese el/los apellido(s) del empleado (3 a  20 caracteres): ",
                        "Apellido demasiado largo/corto. Ingrese el/los apellido(s) del empleado (3 a 20 caracteres): ",
                        3,
                        20);
            strcpy(list[availableIndex].lastName, lastName);

            checkFloat(&salary,
                       "Ingrese el salario del empleado (1 a 100000): ",
                       "Salario invalido. Ingrese el salario del empleado (1 a 100000): ",
                       1,
                       100000);
            list[availableIndex].salary=salary;

            fflush(stdin);

            checkInteger(&sector,
                         "Ingrese el sector del empleado (1 a 5): ",
                         "Sector inválido. Ingrese el sector del empleado (1 a 5): ",
                         1, 5);
            list[availableIndex].sector=sector;

            fflush(stdin);

            list[availableIndex].isEmpty=0;

            printf("\nAlta exitosa.\n");
            printf("Se ha dado de alta al siguiente empleado: \n\n");

            printf(" ID |       NOMBRE       |      APELLIDO      |   SALARIO   | SECTOR \n");
            printf("---------------------------------------------------------------------\n");
            printEmployee(list[availableIndex]);
            printf("\n");

            error=0;
        }
        else
        {
            printf("\nNo hay mas lugar disponible para nuevas altas.\n\n");
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
            printf(" ID |       NOMBRE       |      APELLIDO      |   SALARIO   | SECTOR \n");
            printf("---------------------------------------------------------------------\n");
            printEmployee(list[idIndex]);

            checkCharacter(&confirmation,
                           "\nConfirmar baja (S/N): ",
                           "Respuesta invalida. Confirmar baja (S/N): ",
                           'S',
                           'N');

            if(confirmation=='S')
            {
                list[idIndex].isEmpty=1;
                error=0;

                system("cls");
                printf("\nBaja exitosa.\n");
                printf("Se ha dado de baja al siguiente empleado: \n\n");
                printf(" ID |       NOMBRE       |      APELLIDO      |   SALARIO   | SECTOR \n");
                printf("---------------------------------------------------------------------\n");
                printEmployee(list[idIndex]);
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
            printf(" ID |       NOMBRE       |      APELLIDO      |   SALARIO   | SECTOR \n");
            printf("---------------------------------------------------------------------\n");
            printEmployee(list[idIndex]);
            printf("\n");

            option=editSubMenu();

            switch(option)
            {
                case 1:
                    checkString(auxEmployee.name,
                                "Ingrese el/los nombre(s) del empleado (3 a 20 caracteres): ",
                                "Nombre demasiado corto/largo. Ingrese el/los nombre(s) del empleado (3 a 20 caracteres): ",
                                3,
                                20);
                    strcpy(list[idIndex].name, auxEmployee.name);
                    break;
                case 2:
                    checkString(auxEmployee.lastName,
                                "Ingrese el/los apellido(s) del empleado (3 a 20 caracteres): ",
                                "Apellido demasiado corto/largo. Ingrese el/los apellido(s) del empleado (3 a 20 caracteres): ",
                                3,
                                20);
                    strcpy(list[idIndex].lastName, auxEmployee.lastName);
                    break;
                case 3:
                    checkFloat(&auxEmployee.salary,
                               "Ingrese el salario del empleado (1 a 100000): ",
                               "Salario invalido. Ingrese el salario del empleado (1 a 100000): ",
                               1,
                               100000);

                               list[idIndex].salary=auxEmployee.salary;

                               fflush(stdin);
                    break;
                case 4:
                    checkInteger(&auxEmployee.sector,
                                 "Ingrese el sector del empleado (1 a 5): ",
                                 "Sector invalido. Ingrese el sector del empleado (1 a 5): ",
                                 1,
                                 5);

                                 list[idIndex].sector=auxEmployee.sector;

                                 fflush(stdin);
                    break;
                case 5:
                    printf("\nModificacion cancelada.\n\n");
                    break;
                default:
                    printf("Opcion invalida. Vuelva a ingresar y selecciona una opcion del 1 al 5.\n");
                    break;
            }

            if(option<5 && option>0)
            {
                system("cls");
                printf("Modificacion exitosa.\n");
                printf("Se ha modificado al siguiente empleado: \n\n");
                printf(" ID |       NOMBRE       |      APELLIDO      |   SALARIO   | SECTOR \n");
                printf("---------------------------------------------------------------------\n");
                printEmployee(list[idIndex]);
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

int calculateSalary(Employee list[], int len)
{
    int error=-1;

    float salarySum=0;
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

        printf("El total de salarios es %.2f.\n", salarySum);
        printf("El promedio de salarios es %.2f.\n\n", average);

        printf(" ID |       NOMBRE       |      APELLIDO      |   SALARIO   | SECTOR \n");
        printf("---------------------------------------------------------------------\n");

        for(int i=0; i<len; i++)
        {
            if(!list[i].isEmpty && list[i].salary>average)
            {
                aboveAverageSalary++;
                printEmployee(list[i]);
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
                        printf("Opcion invalida. Vuelva a ingresar y selecciona una opcion del 1 al 2.");
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
                printf("\nInforme cancelado.\n\n");
                break;
            default:
                printf("\nOpcion invalida. Vuelva a ingresar y selecciona una opcion del 1 al 3.\n\n");
                break;
        }
        error=0;
    }

    return error;
}

int allowAccess(Employee list[], int len, int* flag)
{
    int error=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty)
        {
            *flag=0;
        }
        else
        {
            *flag=1;
            break;
        }
                }
    return error;
}
