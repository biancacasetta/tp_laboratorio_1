#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#endif // ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[21];
    char lastName[21];
    float salary;
    int sector;
    int isEmpty;
}Employee;

/**
 * @fn int initEmployees(Employee[], int)
 * @brief
 *
 * @param list un vector de tipo Employee que contiene todos los datos de un empleado en cada índice
 * @param len el tamaño del vector de empleados
 * @return -1 si ocurrió un error, 0 si no hubo error
 */
int initEmployees(Employee list[], int len);

/**
 * @fn int availability(Employee[], int)
 * @brief
 *
 * @param list un vector de tipo Employee que contiene todos los datos de un empleado en cada índice
 * @param len el tamaño del vector Employee
 * @return El número de índice que se encuentra disponible para cargar nuevos datos, -1 si no hay lugar disponible
 */
int availability(Employee list[], int len);

/**
 * @fn int addEmployee(Employee[], int, int, char[], char[], float, int)
 * @brief Da de alta a un empleado en el primer lugar disponible
 *
 * @param list El vector de empleados
 * @param len El tamaño del vector de empleados
 * @param id El ID del empleado
 * @param name El nombre del empleado
 * @param lastName El apellido del empleado
 * @param salary El salario del empleado
 * @param sector El sector del empleado
 * @return -1 si ocurrió un error, 0 si no hubo error
 */
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);

/**
 * @fn int findEmployeeById(Employee[], int, int)
 * @brief Revisa si el ID ingresado por el usuario se encuentra cargado en el sistema o no existe
 *
 * @param list El vector de empleados
 * @param len El tamaño del vector de empleados
 * @param id El ID a validar si existe
 * @return -1 si ocurrió un error, 0 si no hubo error
 */
int findEmployeeById(Employee list[], int len, int id);

/**
 * @fn int removeEmployee(Employee[], int, int)
 * @brief Da de baja a un empleado existente del sistema después de ingresar su ID
 *
 * @param list El vector de empleados
 * @param len El tamaño del vector de empleados
 * @param id El ID a validar si existe
 * @return -1 si ocurrió un error, 0 si no hubo error
 */
int removeEmployee(Employee list[], int len, int id);

/**
 * @fn int editEmployee(Employee[], int, int)
 * @brief Modifica cualquier dato ingresado de un empleado por si el usuario lo ingresó incorrectamente
 *
 * @param list El vector de empleados
 * @param len El tamaño del vector de empleados
 * @param id El ID a validar si existe
 * @return -1 si ocurrió un error, 0 si no hubo error
 */
int editEmployee(Employee list[], int len, int id);

/**
 * @fn int sortEmployees(Employee[], int, int)
 * @brief Informa listado de empleados por alfabeto o si exceden el salario promedio. Informa la suma y promedio de salarios.
 *
 * @param list El vector de empleados
 * @param len El tamaño del vector de empleados
 * @param order para ordenar alfabéticamente, 1 si el orden es ascendente (A-Z), 0 si es descendente (Z-A)
 * @return -1 si ocurrió un error, 0 si no hubo error
 */
int sortEmployees(Employee list[], int len, int order);

/**
 * @fn void printEmployee(Employee, int)
 * @brief Muestra los datos de un solo empleado
 *
 * @param anEmployee El empleado que se desea mostrar
 */
void printEmployee(Employee anEmployee);

/**
 * @fn int printEmployees(Employee[], int)
 * @brief Muestra el listado de empleados completo
 *
 * @param list El vector de empleados
 * @param len El tamaño del vector de empleados
 * @return -1 si ocurrió un error, 0 si no hubo error
 */
int printEmployees(Employee list[], int len);

/**
 * @fn int calculateSalary(Employee[], int)
 * @brief Realiza la suma de todos los salarios, calcula el promedio y muestra los empleados que superan el salario promedio
 *
 * @param list El vector de empleados
 * @param len El tamaño del vector de empleados
 * @return -1 si ocurrió un error, 0 si no hubo error
 */
int calculateSalary(Employee list[], int len);

/**
 * @fn int allowAccess(Employee[], int, int*)
 * @brief Permite el ingreso a la opcion de dar de baja solo si existen altas
 *
 * @param list El vector de empleados
 * @param len El tamaño del vector de empleados
 * @param flag Puntero a entero de bandera que indica si el vector de empleados esta vacio o no
 * @return -1 si ocurrió un error, 0 si no hubo error
 */
int allowAccess(Employee list[], int len, int* flag);



