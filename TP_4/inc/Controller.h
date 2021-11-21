#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "Employee.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char* El nombre del archivo a cargar
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se crea la lista de empleados
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Limpia todos los nodos de una estructura de tipo LinkedList
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList a limpiar
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_clearList(LinkedList* pArrayListEmployee);

/** \brief Calcula el próximo ID a utilizar en base al último utilizado
 * \return int El último ID utilizado + 1
 */
int controller_nextId();

/** \brief Guarda el último ID utilizado en un archivo de texto para tomar como punto de partida en la próxima corrida del programa
 * \param currentId int El último ID utilizado a guardar
 * \return void No retorna nada
 */
void controller_saveId(int currentId);

/** \brief Pide y almacena los datos a cargar en un nuevo empleado
 * \param newEmployee Employee* Puntero a estructura Employee donde se guardarán los datos ingresados
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_saveEmployeeFields(Employee* newEmployee);

/** \brief Alta de empleados
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se da de alta al empleado
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Sobreescribe un pElement de un nodo de la LinkedList con nuevos datos (incluyendo ID para no reutilizar uno ya existente)
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList en donde se sobreescribirá un empleado
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_overwriteEmployee(LinkedList* pArrayListEmployee);

/** \brief Fuerza el alta de un empleado en una posición específica determinada por el usuario
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se insertará el nuevo empleado
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_pushEmployee(LinkedList* pArrayListEmployee);

/** \brief Recorre el array de la lista de empleados para verificar que el ID ingresado por el usuario sea existente
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se busca al empleado por ID
 * \param id int El ID ingresado por el usuario a verificar
 * \return int -1 si el ID no es existente, el número del índice si el ID existe
 */
int controller_employeeIndexById(LinkedList* pArrayListEmployee, int id);

/** \brief Modificar datos de empleado
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se modifica al empleado
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se da de baja al empleado
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Separa y elimina un nodo de la LinkedList sin eliminar los datos del Employee al que apuntaba
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList de donde se separará el nodo
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_popEmployee(LinkedList* pArrayListEmployee);

/** \brief Lista un único empleado
 * \param anEmployee Employee* El empleado a listar
 * \return void No retorna nada
 */
void controller_printEmployee(Employee* anEmployee);

/** \brief Listar empleados
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList de donde se listan empleados
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList donde se ordenan empleados
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char* El nombre del archivo donde se guardarán los datos
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList de donde se guardarán los datos
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);

/** \brief Crea una sublista a partir de la lista original de empleados
 * \param pArrayListEmployee LinkedList* Puntero a estructura LinkedList de la lista original
 * \return int 1 si hubo error, 0 si no hubo error
 */
int controller_subList(LinkedList* pArrayListEmployee);

#endif // CONTROLLER_H_INCLUDED
