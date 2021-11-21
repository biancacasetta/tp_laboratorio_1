#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/Employee.h"
#include "../inc/Controller.h"
#include "../inc/parser.h"
#include "../inc/input.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int error=1;
	FILE* f;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		f=fopen(path, "r");
		if(f!=NULL)
		{
			parser_EmployeeFromText(f, pArrayListEmployee);
			printf("\nCarga de archivo de texto exitosa.\n\n");
			error=0;
		}
		else
        {
            printf("\nNo se pudo cargar el archivo.\n\n");
        }
		fclose(f);
	}
    return error;
}

int controller_clearList(LinkedList* pArrayListEmployee)
{
    int error=1;

    if(pArrayListEmployee!=NULL)
    {
        ll_clear(pArrayListEmployee);
    }

    return error;
}

int controller_nextId()
{
	FILE* f=fopen("lastId.txt", "r");
	int* currentId=(int*) malloc(sizeof(int));
    int nextId;

    if(f==NULL)
    {
        nextId=1001;
    }
    else
    {
        fscanf(f, "%d", currentId);
        nextId=*currentId+1;
    }
    fclose(f);

    return nextId;
}

void controller_saveId(int currentId)
{
    FILE* f=fopen("lastId.txt", "r+");

    if(f==NULL)
    {
        f=fopen("lastId.txt", "w");
    }

    fprintf(f,"%d", currentId);
    fclose(f);
}

int controller_saveEmployeeFields(Employee* newEmployee)
{
    int error=1;
    int id;
    char nombre[128];
    int horas;
    int sueldo;

    if(newEmployee!=NULL)
    {
        id=controller_nextId();
		employee_setId(newEmployee, id);

		validarCadena(nombre,
                      "Ingrese el nombre del empleado: ",
                      "Nombre demasiado largo. Ingrese el nombre del empleado: ",
                      2,
                      127);

		employee_setNombre(newEmployee, nombre);

		validarEntero(&horas,
                          "Ingrese las horas trabajadas del empleado (1-350): ",
                          "Valor inválido. Ingrese las horas trabajadas del empleado (1-350): ",
                          1,
                          350);

		employee_setHorasTrabajadas(newEmployee, horas);

		fflush(stdin);

		validarEntero(&sueldo,
                          "Ingrese el sueldo del empleado (0-100000): ",
                          "Sueldo inválido. Ingrese el sueldo del empleado (0-100000): ",
                          1,
                          100000);

		employee_setSueldo(newEmployee, sueldo);

		fflush(stdin);
    }

    return error;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    Employee* newEmployee;

	if(pArrayListEmployee!=NULL)
	{
		newEmployee=employee_new();

		if(newEmployee!=NULL)
		{
			system("cls");
            printf("                          ALTA DE EMPLEADO                         \n");
            printf("-------------------------------------------------------------------\n\n");

			controller_saveEmployeeFields(newEmployee);

			ll_add(pArrayListEmployee, newEmployee);
			controller_saveId(newEmployee->id);

			system("cls");
            printf("Alta exitosa.\n");
            printf("Se ha dado de alta al siguiente empleado: \n\n");
            printf(" ID |       NOMBRE       | HORAS | SUELDO \n");
            printf("------------------------------------------\n");
            controller_printEmployee(newEmployee);
            printf("\n");

		}
	}
    return error;
}

int controller_overwriteEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    int overwrittenId;
    int idIndex;
    Employee* employee;
    Employee* newEmployee;
    char confirmacion;

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("            SOBREESCRIBIR EMPLEADO             \n");
        printf("-----------------------------------------------\n\n");
        controller_ListEmployee(pArrayListEmployee);
        printf("Ingrese el ID que desea sobreescribir: ");
        scanf("%d", &overwrittenId);
        fflush(stdin);

        idIndex=controller_employeeIndexById(pArrayListEmployee, overwrittenId);
        employee=ll_get(pArrayListEmployee, idIndex);

        if(ll_contains(pArrayListEmployee, employee) && employee!=NULL)
        {
            system("cls");
            printf(" ID |       NOMBRE       | HORAS | SUELDO \n");
            printf("------------------------------------------\n");
            controller_printEmployee(employee);

            validarCaracter(&confirmacion,
                            "Confirmar sobreescritura (S/N): ",
                            "OpciÃ³n invÃ¡lida. Confirmar sobreescritura (S/N): ",
                            'S',
                            'N');

            newEmployee=employee_new();
            controller_saveEmployeeFields(newEmployee);
            ll_set(pArrayListEmployee, ll_indexOf(pArrayListEmployee, employee), newEmployee);
            controller_saveId(newEmployee->id);

            system("cls");
            printf("Sobreescritura exitosa.\n");
            printf("Se ha dado de alta al siguiente empleado: \n\n");
            printf(" ID |       NOMBRE       | HORAS | SUELDO \n");
            printf("------------------------------------------\n");
            controller_printEmployee(newEmployee);
            printf("\n");

        }
        else
        {
            printf("\nNo existe el ID ingresado.\n\n");
        }
    }

    return error;
}

int controller_pushEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    int pushId;
    int idIndex;
    Employee* newEmployee;

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("                INSERTAR EMPLEADO              \n");
        printf("-----------------------------------------------\n\n");
        controller_ListEmployee(pArrayListEmployee);
        printf("Ingrese un ID para luego insertar un nuevo empleado en la posición siguiente: ");
        scanf("%d", &pushId);
        fflush(stdin);

        idIndex=controller_employeeIndexById(pArrayListEmployee, pushId);
        newEmployee=employee_new();

        if(newEmployee!=NULL && idIndex>=0)
        {
            printf("\n");
            controller_saveEmployeeFields(newEmployee);
            ll_push(pArrayListEmployee, idIndex+1, newEmployee);

            system("cls");
            printf("Alta exitosa.\n");
            printf("Se ha dado de alta al siguiente empleado en la posición elegida: \n\n");
            printf(" ID |       NOMBRE       | HORAS | SUELDO \n");
            printf("------------------------------------------\n");
            controller_printEmployee(newEmployee);
            printf("\n");
        }
        else
        {
            printf("\nNo existe el ID ingresado.\n\n");
        }
    }

    return error;
}

int controller_employeeIndexById(LinkedList* pArrayListEmployee, int id)
{
    int idIndex=-1;
    int len;
    Employee* employee;

    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);

        for(int i=0; i<len; i++)
        {
            employee=ll_get(pArrayListEmployee, i);
			if(employee!=NULL)
			{
				employee_getId(employee, &idIndex);
				if(idIndex==id)
				{
					idIndex=i;
					break;
				}
			}
        }
    }
    return idIndex;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    int inputId;
    int idIndex;
    Employee* employee;
    int opcion;
    char nombre[128];
    int horas;
    int sueldo;

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("                           MODIFICAR EMPLEADO                       \n");
        printf("--------------------------------------------------------------------\n");
        controller_ListEmployee(pArrayListEmployee);
        printf("\nIngrese el ID del empleado a modificar: ");
        scanf("%d", &inputId);
        fflush(stdin);
        printf("\n");

        idIndex=controller_employeeIndexById(pArrayListEmployee, inputId);
        employee=ll_get(pArrayListEmployee, idIndex);

        if(ll_contains(pArrayListEmployee, employee) && employee!=NULL)
        {
            printf(" ID |       NOMBRE       | HORAS | SUELDO \n");
            printf("------------------------------------------\n");
            controller_printEmployee(employee);

            opcion=subMenuModificar();

            switch(opcion)
            {
                case 1:
                    validarCadena(nombre,
                          "Ingrese el nuevo nombre del empleado: ",
                          "Nombre demasiado largo. Ingrese el nuevo nombre del empleado: ",
                          2,
                          127);

                    employee_setNombre(employee, nombre);
                    break;
                case 2:
                    validarEntero(&horas,
                          "Ingrese las nuevas horas trabajadas del empleado (1-350): ",
                          "Valor inválido. Ingrese las nuevas horas trabajadas del empleado (1-350): ",
                          1,
                          350);

                    employee_setHorasTrabajadas(employee, horas);
                    fflush(stdin);
                    break;
                case 3:
                    validarEntero(&sueldo,
                          "Ingrese el nuevo sueldo del empleado (1-100000): ",
                          "Sueldo inválido. Ingrese el nuevo sueldo del empleado (1-100000): ",
                          1,
                          100000);

                    employee_setSueldo(employee, sueldo);
                    fflush(stdin);
                    break;
                case 4:
                    printf("Modificación cancelada.\n\n");
                    break;
                default:
                    printf("Opción inválida. Ingrese una opción del 1 al 4.\n");
                    fflush(stdin);
                    break;
            }

            if(opcion>0 && opcion<4)
            {
                system("cls");
                printf("Modificación exitosa.\n");
                printf("Se ha modificado al siguiente empleado: \n\n");
                printf(" ID |       NOMBRE       | HORAS | SUELDO \n");
                printf("------------------------------------------\n");
                controller_printEmployee(employee);
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

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    int inputId;
    int idIndex;
    Employee* employee;
    char confirmation;

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("                            BAJA DE EMPLEADO                        \n");
        printf("--------------------------------------------------------------------\n");
        controller_ListEmployee(pArrayListEmployee);
        printf("\nIngrese el ID del empleado a dar de baja: ");
        scanf("%d", &inputId);
        fflush(stdin);
        printf("\n");

        idIndex=controller_employeeIndexById(pArrayListEmployee, inputId);
        employee=ll_get(pArrayListEmployee, idIndex);

        if(ll_contains(pArrayListEmployee, employee) && employee!=NULL)
        {
            printf(" ID |       NOMBRE       | HORAS | SUELDO \n");
            printf("------------------------------------------\n");
            controller_printEmployee(employee);

            validarCaracter(&confirmation,
                           "\nConfirmar baja (S/N): ",
                           "Respuesta inválida. Confirmar baja (S/N): ",
                           'S',
                           'N');

            if(confirmation=='S')
            {
                system("cls");
                printf("Baja exitosa.\n");
                printf("Se ha dado de baja al siguiente empleado: \n\n");
                printf(" ID |       NOMBRE       | HORAS | SUELDO \n");
                printf("------------------------------------------\n");
                controller_printEmployee(employee);
                printf("\n");

                ll_remove(pArrayListEmployee, idIndex);
                employee_delete(employee);
                error=0;
            }
        }
        else
        {
            printf("No existe el ID ingresado.\n\n");
        }
    }
    return error;
}

int controller_popEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    int inputId;
    int idIndex;
    Employee* employee;
    char confirmation;

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("                            SEPARAR EMPLEADO                        \n");
        printf("--------------------------------------------------------------------\n");
        controller_ListEmployee(pArrayListEmployee);
        printf("\nIngrese el ID del empleado a separar: ");
        scanf("%d", &inputId);
        fflush(stdin);
        printf("\n");

        idIndex=controller_employeeIndexById(pArrayListEmployee, inputId);
        employee=ll_get(pArrayListEmployee, idIndex);

        if(employee!=NULL)
        {
            printf(" ID |       NOMBRE       | HORAS | SUELDO \n");
            printf("------------------------------------------\n");
            controller_printEmployee(employee);

            validarCaracter(&confirmation,
                           "\nConfirmar separación (S/N): ",
                           "Respuesta inválida. Confirmar separación (S/N): ",
                           'S',
                           'N');

            if(confirmation=='S')
            {
                system("cls");
                printf("Separación exitosa.\n");
                printf("Se ha separado al siguiente empleado: \n\n");
                printf(" ID |       NOMBRE       | HORAS | SUELDO \n");
                printf("------------------------------------------\n");
                controller_printEmployee(employee);
                printf("\n");

                ll_pop(pArrayListEmployee, idIndex);
                error=0;
            }
        }
        else
        {
            printf("No existe el ID ingresado.\n\n");
        }
    }
    return error;
}

void controller_printEmployee(Employee* anEmployee)
{
    int id;
    char nombre[128];
    int horas;
    int sueldo;

    if(anEmployee!=NULL)
    {
        employee_getId(anEmployee, &id);
        employee_getNombre(anEmployee, nombre);
        employee_getHorasTrabajadas(anEmployee, &horas);
        employee_getSueldo(anEmployee, &sueldo);

        printf("%-5d%-21s%-8d%-8d\n", id, nombre, horas, sueldo);
    }
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    Employee* anEmployee=NULL;
    int len;

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("             LISTA DE EMPLEADOS           \n");
        printf("------------------------------------------\n");
        printf(" ID |       NOMBRE       | HORAS | SUELDO \n");
        printf("------------------------------------------\n");

        len=ll_len(pArrayListEmployee);

        if(len>0)
        {
            for(int i=0; i<len; i++)
            {
                anEmployee=ll_get(pArrayListEmployee, i);
                controller_printEmployee(anEmployee);
            }
        }
        printf("\n");
        error=0;
    }

    return error;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    LinkedList* auxList;

    if(pArrayListEmployee!=NULL)
    {
        auxList=ll_clone(pArrayListEmployee);

        system("cls");
        printf("        ORDENAR EMPLEADOS       \n");
        printf("--------------------------------\n\n");

        if(!ll_isEmpty(pArrayListEmployee) && ll_containsAll(pArrayListEmployee, auxList))
        {
            switch(subMenuOrdenar())
            {
                case 1:
                    system("cls");
                    printf("        LISTA POR ID        \n");
                    printf("----------------------------\n\n");

                    switch(subMenuCriterio())
                    {
                        case 1:
                            printf("\nAguarde un momento. Se está realizando el ordenamiento.\n\n");
                            ll_sort(auxList, employee_sortById, 1);
                            system("cls");
                            controller_ListEmployee(auxList);
                            break;
                        case 2:
                            printf("\nAguarde un momento. Se está realizando el ordenamiento.\n\n");
                            ll_sort(auxList, employee_sortById, 0);
                            system("cls");
                            controller_ListEmployee(auxList);
                            break;
                        default:
                            printf("\nOpción inválida.\n");
                            break;
                    }
                    break;
                case 2:
                    system("cls");
                    printf("      LISTA POR NOMBRE      \n");
                    printf("----------------------------\n\n");

                    switch(subMenuCriterio())
                    {
                        case 1:
                            printf("\nAguarde un momento. Se está realizando el ordenamiento.\n\n");
                            ll_sort(auxList, employee_sortByName, 1);
                            system("cls");
                            controller_ListEmployee(auxList);
                            break;
                        case 2:
                            printf("\nAguarde un momento. Se está realizando el ordenamiento.\n\n");
                            ll_sort(auxList, employee_sortByName, 0);
                            system("cls");
                            controller_ListEmployee(auxList);
                            break;
                        default:
                            printf("\nOpción inválida.\n");
                            break;
                    }
                    break;
                case 3:
                    system("cls");
                    printf("       LISTA POR HORAS       \n");
                    printf("-----------------------------\n\n");

                    switch(subMenuCriterio())
                    {
                        case 1:
                            printf("\nAguarde un momento. Se está realizando el ordenamiento.\n\n");
                            ll_sort(auxList, employee_sortByHours, 1);
                            system("cls");
                            controller_ListEmployee(auxList);
                            break;
                        case 2:
                            printf("\nAguarde un momento. Se está realizando el ordenamiento.\n\n");
                            ll_sort(auxList, employee_sortByHours, 0);
                            system("cls");
                            controller_ListEmployee(auxList);
                            break;
                        default:
                            printf("\nOpción inválida.\n");
                            break;
                    }
                    break;
                case 4:
                    system("cls");
                    printf("      LISTA POR SUELDO      \n");
                    printf("----------------------------\n\n");

                    switch(subMenuCriterio())
                    {
                        case 1:
                            printf("\nAguarde un momento. Se está realizando el ordenamiento.\n\n");
                            ll_sort(auxList, employee_sortBySalary, 1);
                            system("cls");
                            controller_ListEmployee(auxList);
                            break;
                        case 2:
                            printf("\nAguarde un momento. Se está realizando el ordenamiento.\n\n");
                            ll_sort(auxList, employee_sortBySalary, 0);
                            system("cls");
                            controller_ListEmployee(auxList);
                            break;
                        default:
                            printf("\nOpción inválida.\n");
                            break;
                    }
                    break;
                case 5:
                    printf("\nOrdenamiento cancelado.\n\n");
                    break;
                default:
                    printf("\nOpción inválida. Ingrese una opción del 1 al 5.\n\n");
                    break;
            }
        }
        else
        {
            printf("\nLa lista se encuentra vacía y no se puede ordenar.\n\n");
        }

        ll_deleteLinkedList(auxList);
        error=0;
    }
    return error;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int error=1;
    FILE* f;
    Employee* employee;
    int id;
	char nombre[128];
	int sueldo;
	int horas;
	int len;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		f=fopen(path, "w");
		employee=employee_new();
		len=ll_len(pArrayListEmployee);

		fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");

		for(int i=0; i<len; i++)
		{
			employee=ll_get(pArrayListEmployee, i);

			if(employee!=NULL)
			{
				employee_getId(employee, &id);
				employee_getNombre(employee, nombre);
				employee_getHorasTrabajadas(employee, &horas);
				employee_getSueldo(employee, &sueldo);

				fprintf(f, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
				error=0;
			}
		}
		fclose(f);
		printf("\nArchivo de texto guardado con éxito.\n\n");
	}

    return error;
}

int controller_subList(LinkedList* pArrayListEmployee)
{
    int error=1;
    LinkedList* subList=NULL;
    int from;
    int to;
    int indexFrom;
    int indexTo;
    int lastId;

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("                         CREAR SUBLISTA                       \n");
        printf("--------------------------------------------------------------\n\n");

        lastId=controller_nextId();

        controller_ListEmployee(pArrayListEmployee);

        validarEntero(&from,
                      "Ingrese el ID desde el cual crear la sublista (inclusive): ",
                      "ID inválido. Ingrese el ID desde el cual crear la sublista (inclusive): ",
                      1,
                      lastId);

        validarEntero(&to,
                      "Ingrese el ID hasta el cual crear la sublista (no inclusive): ",
                      "ID inválido. Ingrese el ID desde el cual crear la sublista (no inclusive): ",
                      from+1,
                      lastId);

        indexFrom=controller_employeeIndexById(pArrayListEmployee, from);
        indexTo=controller_employeeIndexById(pArrayListEmployee, to);

        subList=ll_subList(pArrayListEmployee, indexFrom, indexTo);

        if(subList!=NULL)
        {
            controller_ListEmployee(subList);
            printf("Sublista creada con éxito.\n\n");
            error=0;
        }
    }
    return error;
}
