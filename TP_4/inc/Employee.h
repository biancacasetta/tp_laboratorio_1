#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Inicializa un nuevo empleado
 * \return Employee* La dirección de memoria del nuevo empleado creado
 */
Employee* employee_new();

/** \brief Asigna valores hardcodeados a un empleado
 * \param idStr char* Cadena de caracteres del ID del empleado
 * \param nombreStr char* Cadena de caracteres del nombre del empleado
 * \param horasTrabajadasStr char* Cadena de caracteres de las horas trabajadas del empleado
 * \param sueldoStr char* Cadena de caracteres del sueldo del empleado
 * \return Employee* La dirección de memoria del empleado hardcodeado
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);

/** \brief Libera la memoria dinámica donde se guardaba un empleado
 * \return void No retorna nada
 */
void employee_delete();

/** \brief Asigna el valor del ID al empleado
 * \param this Employee* Puntero a estructura Employee a la cual se asignará el ID
 * \param id int El valor del ID a asignar
 * \return int 1 si hubo error, 0 si no hubo error
 */
int employee_setId(Employee* this,int id);

/** \brief Busca y obtiene el valor del ID de un empleado
 * \param this Employee* Puntero a estructura Employee del cual se obtiene el ID
 * \param id int* Puntero a entero del ID del empleado
 * \return int 1 si hubo error, 0 si no hubo error
 */
int employee_getId(Employee* this,int* id);

/** \brief Asigna el valor del nombre al empleado
 * \param this Employee* Puntero a estructura Employee a la cual se asignará el nombre
 * \param nombre char* La cadena de caracteres del nombre a asignar
 * \return int 1 si hubo error, 0 si no hubo error
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Busca y obtiene el valor del nombre de un empleado
 * \param this Employee* Puntero a estructura Employee del cual se obtiene el nombre
 * \param nombre char* Puntero a char del nombre del empleado
 * \return int 1 si hubo error, 0 si no hubo error
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Asigna el valor de las horas trabajadas al empleado
 * \param this Employee* Puntero a estructura Employee a la cual se asignarán las horas trabajadas
 * \param id int El valor de las horas trabajadas a asignar
 * \return int 1 si hubo error, 0 si no hubo error
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Busca y obtiene el valor de las horas trabajadas de un empleado
 * \param this Employee* Puntero a estructura Employee del cual se obtienen las horas trabajadas
 * \param id int* Puntero a entero de las horas trabajadas del empleado
 * \return int 1 si hubo error, 0 si no hubo error
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Asigna el valor del sueldo al empleado
 * \param this Employee* Puntero a estructura Employee a la cual se asignará el sueldo
 * \param id int El valor del sueldo a asignar
 * \return int 1 si hubo error, 0 si no hubo error
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Busca y obtiene el valor del sueldo de un empleado
 * \param this Employee* Puntero a estructura Employee del cual se obtiene el sueldo
 * \param id int* Puntero a entero del sueldo del empleado
 * \return int 1 si hubo error, 0 si no hubo error
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Compara los ID de los empleados
 * \param employee1 void* Puntero a void del primer empleado a comparar
 * \param employee2 void* Puntero a void del segundo empleado a comparar
 * \return int 1 si el orden es descendente, -1 si es ascendente
 */
int employee_sortById(void* employee1, void* employee2);

/** \brief Compara los nombres de los empleados
 * \param employee1 void* Puntero a void del primer empleado a comparar
 * \param employee2 void* Puntero a void del segundo empleado a comparar
 * \return int 1 si el orden es descendente, -1 si es ascendente
 */
int employee_sortByName(void* employee1, void* employee2);

/** \brief Compara las horas trabajadas de los empleados
 * \param employee1 void* Puntero a void del primer empleado a comparar
 * \param employee2 void* Puntero a void del segundo empleado a comparar
 * \return int 1 si el orden es descendente, -1 si es ascendente
 */
int employee_sortByHours(void* employee1, void* employee2);

/** \brief Compara los sueldos de los empleados
 * \param employee1 void* Puntero a void del primer empleado a comparar
 * \param employee2 void* Puntero a void del segundo empleado a comparar
 * \return int 1 si el orden es descendente, -1 si es ascendente
 */
int employee_sortBySalary(void* employee1, void* employee2);

#endif // EMPLOYEE_H_INCLUDED
