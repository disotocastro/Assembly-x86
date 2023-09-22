/**
 *   CI0118 Lenguajes ensambladores
 *   Grupo: 03 (Francisco Arroyo)
 *   Ejemplo de llamado a rutinas en ensamblador desde C
 *
 *   Compilar: g++ -g strlenTest.cc strlen.s -o strlenTest.out
 *   Correr: ./strlenTest.out
 *
 */

#include <iostream>

extern "C" int strLen( char * );	// Declaración para indicar que esta rutina se define en "link time"
				// El símbolo "strlen" debe coincidir con la rutina en ensamblador y debe ser global

/**
 *
 */
int main ( int argumentos, char **valores ) {
    char * example = (char *) "Lenguajes ensambladores 2023";
    char * test;
    int resultado;

    test = example;
    if ( argumentos > 1 ) {		// Check for argument
       test = valores[ 1 ];
    }
    resultado = strLen( test );	// Call assembly routine

    std::cout << "El largo de la tira indicada es: " << resultado << std::endl;

    return 0;

}

