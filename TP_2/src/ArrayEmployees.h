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
 * @fn int menu()
 * @brief Muestra el men� principal al usuario
 *
 * @return El n�mero de opci�n que ingresa el usuario
 */
int menu();

/**
 * @fn int editSubMenu()
 * @brief Muestra el submenu cuando se selecciona la opcion 2. Modificar
 *
 * @return El n�mero de opci�n que ingresa el usuario
 */
int editSubMenu();

/**
 * @fn int sortSubMenu()
 * @brief Muestra el menu cuando se selecciona la opcion 4. Informar
 *
 * @return El n�mero de opci�n que ingresa el usuario
 */
int sortSubMenu();

/**
 * @fn int initEmployees(Employee[], int)
 * @brief
 *
 * @param list un vector de tipo Employee que contiene todos los datos de un empleado en cada �ndice
 * @param len el tama�o del vector de empleados
 * @return -1 si ocurri� un error, 0 si no hubo error
 */
int initEmployees(Employee list[], int len);

/**
 * @fn int availability(Employee[], int)
 * @brief
 *
 * @param list un vector de tipo Employee que contiene todos los datos de un empleado en cada �ndice
 * @param len el tama�o del vector Employee
 * @return El n�mero de �ndice que se encuentra disponible para cargar nuevos datos, -1 si no hay lugar disponible
 */
int availability(Employee list[], int len);

/**
 * @fn int justLetters(char[])
 * @brief Valida que la cadena de caracteres ingresada contenga solo letras
 *
 * @param string Cadena de caracteres a validar
 * @return -1 si ocurri� un error, 0 si no hubo error
 */
int justLetters(char string[]);

/**
 * @fn int capitalisation(char[])
 * @brief Formatea una cadena de caracteres para que quede con la primera letra may�scula en cada nombre o apellido
 *
 * @param string La cadena de caracteres a formatear
 * @return -1 si ocurri� un error, 0 si no hubo error
 */
int capitalisation(char string[]);

/**
 * @fn int addEmployee(Employee[], int, int, char[], char[], float, int)
 * @brief Da de alta a un empleado en el primer lugar disponible
 *
 * @param list El vector de empleados
 * @param len El tama�o del vector de empleados
 * @param id El ID del empleado
 * @param name El nombre del empleado
 * @param lastName El apellido del empleado
 * @param salary El salario del empleado
 * @param sector El sector del empleado
 * @return -1 si ocurri� un error, 0 si no hubo error
 */
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);

/**
 * @fn int findEmployeeById(Employee[], int, int)
 * @brief Revisa si el ID ingresado por el usuario se encuentra cargado en el sistema o no existe
 *
 * @param list El vector de empleados
 * @param len El tama�o del vector de empleados
 * @param id El ID a validar si existe
 * @return -1 si ocurri� un error, 0 si no hubo error
 */
int findEmployeeById(Employee list[], int len, int id);

/**
 * @fn int removeEmployee(Employee[], int, int)
 * @brief Da de baja a un empleado existente del sistema despu�s de ingresar su ID
 *
 * @param list El vector de empleados
 * @param len El tama�o del vector de empleados
 * @param id El ID a validar si existe
 * @return -1 si ocurri� un error, 0 si no hubo error
 */
int removeEmployee(Employee list[], int len, int id);

/**
 * @fn int editEmployee(Employee[], int, int)
 * @brief Modifica cualquier dato ingresado de un empleado por si el usuario lo ingres� incorrectamente
 *
 * @param list El vector de empleados
 * @param len El tama�o del vector de empleados
 * @param id El ID a validar si existe
 * @return -1 si ocurri� un error, 0 si no hubo error
 */
int editEmployee(Employee list[], int len, int id);

/**
 * @fn int sortEmployees(Employee[], int, int)
 * @brief Informa listado de empleados por alfabeto o si exceden el salario promedio. Informa la suma y promedio de salarios.
 *
 * @param list El vector de empleados
 * @param len El tama�o del vector de empleados
 * @param order para ordenar alfab�ticamente, 1 si el orden es ascendente (A-Z), 0 si es descendente (Z-A)
 * @return -1 si ocurri� un error, 0 si no hubo error
 */
int sortEmployees(Employee list[], int len, int order);

/**
 * @fn void printEmployee(Employee, int)
 * @brief Muestra los datos de un solo empleado
 *
 * @param anEmployee El empleado que se desea mostrar
 */
void printEmployee(Employee anEmployee, int len);

/**
 * @fn int printEmployees(Employee[], int)
 * @brief Muestra el listado de empleados completo
 *
 * @param list El vector de empleados
 * @param len El tama�o del vector de empleados
 * @return -1 si ocurri� un error, 0 si no hubo error
 */
int printEmployees(Employee list[], int len);

/**
 * @fn int checkString(char[], char[], char[], int)
 * @brief Valida si una cadena de caracteres se encuentra en el rango v�lido (1 a 20 caracteres)
 *
 * @param string La cadena de caracteres a validar. Cambi� el tama�o de 51 a 21 para mejor visualizaci�n de la lista.
 * @param message Mensaje que se muestra al usuario para que ingrese la cadena de caracteres
 * @param errorMessage Mensaje de error que se muestra si el usuario ingres� una cadena inv�lida
 * @param min El m�nimo de caracteres a ingresar
 * @param max El m�ximo de caracteres a ingresar
 * @return -1 si ocurri� un error, 0 si no hubo error
 */
int checkString(char string[], char message[], char errorMessage[], int min, int max);

/**
 * @fn int checkCharacter(char*, char[], char[], char, char)
 * @brief Valida si el caracter ingresado est� dentro de las opciones v�lidas (para confirmaciones de S o N)
 *
 * @param character Caracter ingresado
 * @param message Mensaje que se muestra al usuario para que ingrese el caracter
 * @param errorMessage Mensaje de error que se muestra si el usuario ingres� un caracter inv�lido
 * @param validCharacter1 Primer caracter v�lido
 * @param validCharacter2 Segundo caracter v�lido
 * @return -1 si ocurri� un error, 0 si no hubo error
 */
int checkCharacter(char* character, char message[], char errorMessage[], char validCharacter1, char validCharacter2);

/**
 * @fn int checkFloat(float*, char[], char[], float, float)
 * @brief Valida si el numero flotante ingresado esta dentro del rango valido
 *
 * @param number El numero ingresado por el usuario
 * @param message Mensaje para que el usuario ingrese el numero
 * @param errorMessage Mensaje de error que se muestra si el usuario ingreso un numero invladio
 * @param min El monto minimo a ingresar
 * @param max El monto maximo a ingresar
 * @return -1 si ocurri� un error, 0 si no hubo error
 */
int checkFloat(float* number, char message[], char errorMessage[], float min, float max);

/**
 * @fn int checkInteger(int*, char[], char[], int, int)
 * @brief Valida si el numero entero ingresado esta dentro del rango valido
 *
 * @param number El numero ingresado por el usuario
 * @param message Mensaje para que el usuario ingrese el numero
 * @param errorMessage Mensaje de error que se muestra si el usuario ingreso un numero invladio
 * @param min El monto minimo a ingresar
 * @param max El monto maximo a ingresar
 * @return -1 si ocurri� un error, 0 si no hubo error
 */
int checkInteger(int* number, char message[], char errorMessage[], int min, int max);

/**
 * @fn int calculateSalary(Employee[], int)
 * @brief Realiza la suma de todos los salarios, calcula el promedio y muestra los empleados que superan el salario promedio
 *
 * @param list El vector de empleados
 * @param len El tama�o del vector de empleados
 * @return -1 si ocurri� un error, 0 si no hubo error
 */
int calculateSalary(Employee list[], int len);



