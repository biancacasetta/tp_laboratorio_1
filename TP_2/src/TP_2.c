#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "input.h"

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
                   printf("\nNo hay ningun empleado dado de alta para modificar.\n\n");
                }
                break;
            case 3:
                if(option1)
                {
                    removeEmployee(arrayEmployees, LENGTH, auxEmployee.id);
                }
                else
                {
                   printf("\nNo hay ningun empleado dado de alta para dar de baja.\n\n");
                }
                allowAccess(arrayEmployees, LENGTH, &option1);
                break;
            case 4:
                if(option1)
                {
                    sortEmployees(arrayEmployees, LENGTH, order);
                }
                else
                {
                   printf("\nNo hay ningun empleado dado de alta para informar.\n\n");
                }
                break;
            case 5:
                checkCharacter(&salir, "\nConfirmar salida (S/N): ", "Opcion invalida. Confirmar salida (S/N): ", 'S', 'N');

                if(salir=='S')
                {
                    seguir='n';
                }
                break;
            default:
                printf("\nOpcion invalida. Ingrese una opcion del 1 al 5.\n\n");
                fflush(stdin);
                break;
        }
    }while(seguir=='s');

    return 0;
}
