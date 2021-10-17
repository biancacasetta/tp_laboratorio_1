#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

#define LENGTH 1000

int main()
{
	setbuf(stdout, NULL);

    char seguir='s';
    char salir;
    int nextId=1;
    int order=0;
    int option1=0;
    Employee auxEmployee;
    Employee arrayEmployees[LENGTH];

    initEmployees(arrayEmployees, LENGTH);

    do
    {
        system("cls");

        switch(menu())
        {
            case 1:
                addEmployee(arrayEmployees,
                            LENGTH,
                            nextId,
                            auxEmployee.name,
                            auxEmployee.lastName,
                            auxEmployee.salary,
                            auxEmployee.sector);
                nextId++;
                option1=1;
                break;
            case 2:
                if(option1)
                {
                    editEmployee(arrayEmployees, LENGTH, auxEmployee.id);
                }
                else
                {
                   printf("No hay ningún empleado dado de alta para modificar.\n");
                }
                break;
            case 3:
                if(option1)
                {
                    removeEmployee(arrayEmployees, LENGTH, auxEmployee.id);
                }
                else
                {
                   printf("No hay ningún empleado dado de alta para dar de baja.\n");
                }

                for(int i=0; i<LENGTH; i++)
                {
                    if(arrayEmployees[i].isEmpty)
                    {
                        option1=0;
                    }
                    else
                    {
                        option1=1;
                        break;
                    }
                }
                break;
            case 4:
                if(option1)
                {
                    sortEmployees(arrayEmployees, LENGTH, order);
                }
                else
                {
                   printf("No hay ningún empleado dado de alta para informar.\n");
                }
                break;
            case 5:
                checkCharacter(&salir, "\nConfirmar salida (S/N): ", "Opción inválida. Confirmar salida (S/N): ", 'S', 'N');

                if(salir=='S')
                {
                    seguir='n';
                }
                break;
            default:
                printf("Opción inválida. Ingrese una opción del 1 al 5.\n");
                fflush(stdin);
                break;
        }
        system("pause");
    }while(seguir=='s');

    return 0;
}
