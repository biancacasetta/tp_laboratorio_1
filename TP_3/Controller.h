#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "Employee.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char* El nombre del archivo a cargar
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se crea la lista de empleados
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char* El nombre del archivo a cargar
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se crea la lista de empleados
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee);

/** \brief Calcula el próximo ID a utilizar en base al último utilizado
 * \return int El último ID utilizado + 1
 */
int controller_nextId();

/** \brief Guarda el último ID utilizado en un archivo de texto para tomar como punto de partida en la próxima corrida del programa
 * \param currentId int El último ID utilizado a guardar
 * \return void No retorna nada
 */
void controller_saveId(int currentId);

/** \brief Alta de empleados
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se crea la lista de empleados
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Recorre el array de la lista de empleados para verificar que el ID ingresado por el usuario sea existente
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se crea la lista de empleados
 * \param id int El ID ingresado por el usuario a verificar
 * \return int -1 si el ID no es existente, el número del índice si el ID existe
 */
int controller_employeeById(LinkedList* pArrayListEmployee, int id);

/** \brief Modificar datos de empleado
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se crea la lista de empleados
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se crea la lista de empleados
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Lista un único empleado
 * \param anEmployee Employee* El empleado a listar
 * \return void No retorna nada
 */
void controller_printEmployee(Employee* anEmployee);

/** \brief Listar empleados
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se crea la lista de empleados
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se crea la lista de empleados
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char* El nombre del archivo donde se guardarán los datos
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se crea la lista de empleados
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * \param path char* El nombre del archivo donde se guardarán los datos
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se crea la lista de empleados
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee);

#endif // CONTROLLER_H_INCLUDED
