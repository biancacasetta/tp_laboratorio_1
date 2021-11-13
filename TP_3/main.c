#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);

    char seguir='s';
    char salir='n';
    char guardarBinario='n';
    char guardarTexto='n';
    LinkedList* listaEmpleados=ll_newLinkedList();
    int cargaArchivo=0;

    do
    {
        system("cls");
        switch(menu())
        {
            case 1:
                if(cargaArchivo)
                {
                    printf("\nNo se puede cargar un archivo si ya se cargó uno previamente.\n\n");
                }
                else
                {
                    controller_loadFromText("data.csv", listaEmpleados);
                    cargaArchivo=1;
                }
                break;
            case 2:
                if(cargaArchivo)
                {
                    printf("\nNo se puede cargar un archivo si ya se cargó uno previamente.\n\n");
                }
                else
                {
                    if(!controller_loadFromBinary("data.bin", listaEmpleados))
                    {
                        cargaArchivo=1;
                    }
                }
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                if(listaEmpleados->size)
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nNo se puede modificar un empleado sin antes cargar un archivo o dar una alta.\n\n");
                }
                break;
            case 5:
                if(listaEmpleados->size)
                {
                    controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nNo se puede dar de baja a un empleado sin antes cargar un archivo o dar una alta.\n\n");
                }
                break;
            case 6:
                if(listaEmpleados->size)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nNo puede listar empleados sin antes cargar un archivo de texto/binario o dar una alta.\n\n");
                }
                break;
            case 7:
                if(listaEmpleados->size)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nNo puede ordenar empleados sin antes cargar un archivo de texto/binario o dar una alta.\n\n");
                }
                break;
            case 8:
                if(listaEmpleados->size)
                {
                    validarCaracter(&guardarBinario, "\nLos datos se van a sobreescribir. Confirmar guardado (S/N): ", "Opción inválida. Confirmar guardado (S/N): ", 'S', 'N');

                    if(guardarTexto=='S')
                    {
                        controller_saveAsText("data.csv", listaEmpleados);
                    }
                }
                else
                {
                    printf("\nNo puede guardar empleados sin antes cargar un archivo de texto/binario o dar una alta.\n\n");
                }
                break;
            case 9:
                if(listaEmpleados->size)
                {
                    validarCaracter(&guardarBinario, "\nLos datos se van a sobreescribir. Confirmar guardado (S/N): ", "Opción inválida. Confirmar guardado (S/N): ", 'S', 'N');

                    if(guardarBinario=='S')
                    {
                        controller_saveAsBinary("data.bin", listaEmpleados);
                    }
                }
                else
                {
                    printf("\nNo puede guardar empleados sin antes cargar un archivo de texto/binario o dar una alta.\n\n");
                }
                break;
            case 10:
                validarCaracter(&salir, "\nConfirmar salida (S/N): ", "Opción inválida. Confirmar salida (S/N): ", 'S', 'N');

                if(salir=='S')
                {
                    ll_deleteLinkedList(listaEmpleados);
                    seguir='n';
                }
                break;
            default:
                printf("\nOpción inválida. Ingrese una opción del 1 al 10.\n\n");
                fflush(stdin);
                break;
        }
    }while(seguir=='s');

    return 0;
}
