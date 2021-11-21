/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../inc/input.h"
#include "../inc/Controller.h"

int main(void)
{
	setbuf(stdout,NULL);
	/*
    startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
    startTesting(3);  // getNode - test_getNode
    startTesting(4);  // addNode - test_addNode
    startTesting(5);  // ll_add
    startTesting(6);  // ll_get
    startTesting(7);  // ll_set
    startTesting(8);  // ll_remove
    startTesting(9);  // ll_clear
    startTesting(10); // ll_deleteLinkedList
    startTesting(11); // ll_indexOf
    startTesting(12); // ll_isEmpty
    startTesting(13); // ll_push
    startTesting(14); // ll_pop
    startTesting(15); // ll_contains
    startTesting(16); // ll_containsAll
    startTesting(17); // ll_subList
    startTesting(18); // ll_clone
    startTesting(19); // ll_sort
	*/
    char seguir='s';
    char salir='n';
    char limpiar='n';
    char guardarTexto='n';
    LinkedList* listaEmpleados=ll_newLinkedList();
    int cargaArchivo=0;

    do
    {
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
                if(ll_isEmpty(listaEmpleados))
                {
                    printf("\nNo se puede limpiar una lista si ya está vacía.\n\n");
                }
                else
                {
                    validarCaracter(&limpiar, "\nConfirmar limpieza de la lista (S/N): ", "Opción inválida. Confirmar limpieza de la lista (S/N): ", 'S', 'N');

                    if(limpiar=='S')
                    {
                        controller_clearList(listaEmpleados);
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
                    printf("\nNo puede listar empleados sin antes cargar un archivo de texto o dar una alta.\n\n");
                }
                break;
            case 7:
                if(listaEmpleados->size)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nNo puede ordenar empleados sin antes cargar un archivo de texto o dar una alta.\n\n");
                }
                break;
            case 8:
                if(listaEmpleados->size)
                {
                    controller_overwriteEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nNo puede sobreescribir un empleado sin antes cargar un archivo de texto o dar un alta.\n\n");
                }
                break;
            case 9:
                if(listaEmpleados->size)
                {
                    controller_pushEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nNo puede insertar un empleado sin antes cargar un archivo de texto o dar un alta.\n\n");
                }
                break;
            case 10:
                if(listaEmpleados->size)
                {
                    controller_subList(listaEmpleados);
                }
                else
                {
                    printf("\nNo puede crear una sublista sin antes tener una lista original de la cual crearla.\n\n");
                }
                break;
            case 11:
                if(listaEmpleados->size)
                {
                    controller_popEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nNo puede separar empleados sin antes cargar un archivo de texto o dar un alta.\n\n");
                }
                break;
            case 12:
                if(listaEmpleados->size)
                {
                    validarCaracter(&guardarTexto, "\nLos datos se van a sobreescribir. Confirmar guardado (S/N): ", "Opción inválida. Confirmar guardado (S/N): ", 'S', 'N');

                    if(guardarTexto=='S')
                    {
                        controller_saveAsText("data.csv", listaEmpleados);
                    }
                }
                else
                {
                    printf("\nNo puede guardar empleados sin antes cargar un archivo de texto o dar una alta.\n\n");
                }
                break;
            case 13:
                validarCaracter(&salir, "\nConfirmar salida (S/N): ", "Opción inválida. Confirmar salida (S/N): ", 'S', 'N');

                if(salir=='S')
                {
                    ll_deleteLinkedList(listaEmpleados);
                    seguir='n';
                }
                break;
            default:
                printf("Opción inválida. Ingrese una opción del 1 al 13.\n");
                fflush(stdin);
                break;
        }

    }while(seguir=='s');

    return 0;
}
