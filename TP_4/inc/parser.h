#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 * \param pFile FILE* La dirección de memoria del archivo a parsear
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se crea la lista de empleados
 * \return int 1 si hubo error, 0 si no hubo error
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

#endif // PARSER_H_INCLUDED
