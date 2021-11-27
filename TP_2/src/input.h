#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#endif // INPUT_H_INCLUDED

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
 * @fn int justLetters(char[])
 * @brief Valida que la cadena de caracteres ingresada contenga solo numeros
 *
 * @param string Cadena de caracteres a validar
 * @return -1 si ocurri� un error, 0 si no hubo error
 */
int justNumbers(char* numbers);

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
