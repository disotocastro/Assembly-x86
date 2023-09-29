/**
 *
 *   Generación de secuencia de números de Collatz
 *
 *   Compilar: g++ -g collatz.cc collatz.s -o collatz.out
 *   Correr: ./collatz.out 59
 *
*/
 
#include <iostream>

extern "C" int collatz( int );	// Assembly routine

/**
 *
 *   Cálculo de la secuencia de Collatz
 *
 **/ 
int Collatz( int numero ) {

   if ( numero % 2 ) {
            numero = numero * 3  + 1;
         } else {
            numero /= 2;
         }

   return numero;

}


/**
 *
 */
int main ( int argumentos, char **valores ) {
    int resultado;
    int n = 22;

    if ( argumentos > 1 ) {		// Check for argument
       n = atoi( valores[ 1 ] );	// Convert argument to number
    }
    do {
       std::cout << n << ", ";
       n = Collatz( n );			// Cambiar a "collatz" para llamar rutina en ensamblador
    } while ( n > 1 );
    std::cout << n << std::endl;

    return 0;
}