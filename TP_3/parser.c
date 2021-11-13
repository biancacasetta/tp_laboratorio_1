#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int error=1;

    Employee* auxEmployee;
    char buffer[3][5];
    char auxNombre[128];
    char* id="1";

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], auxNombre, buffer[1], buffer[2]);

        do
        {
            if((fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], auxNombre, buffer[1], buffer[2]))==4)
            {
                id=buffer[0];

                auxEmployee=employee_newParametros(buffer[0], auxNombre, buffer[1], buffer[2]);

				if(auxEmployee!=NULL)
				{
					if(ll_add(pArrayListEmployee, auxEmployee))
					{
                        employee_delete(auxEmployee);
						error=1;
						break;
					}
					else
					{
						error=0;
					}
				}
			}
			else
			{
				break;
			}
        }
        while(!feof(pFile));

        controller_saveId(atoi(id));
    }
    return error;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int error=1;
    Employee* auxEmployee;
    int id;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        do
        {
            auxEmployee=employee_new();
            fread(auxEmployee, sizeof(Employee), 1, pFile);

            if(!feof(pFile))
            {
                if(ll_add(pArrayListEmployee, auxEmployee)!=0)
                {
                    employee_delete(auxEmployee);
                    error=1;
                    break;
                }
                else
                {
                    id=auxEmployee->id;
                    error=0;
                }
            }
            else
            {
                break;
            }
        }
        while(!feof(pFile));

        controller_saveId(id);
    }
    return error;
}

