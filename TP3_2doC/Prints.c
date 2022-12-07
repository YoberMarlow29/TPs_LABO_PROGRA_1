#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "input.h"

void guardarCambios(int* confirmar)
{
	pedirNumeros(confirmar, "Desea guardar los cambios?\n"
			"1- Si\n"
			"2- No\n","Error, debe ingresar (1-2)\n", "Error, escoga una opcion valida", 2, 1);
}

void borrarJugador(int* confirmar)
{
	pedirNumeros(confirmar, "Esta seguro de borrar los datos del jugador? seleccione 2 si el id es erroneo \n"
			"1- Si\n"
			"2- No\n","Error, debe ingresar (1-2)\n", "Error, escoga una opcion valida", 2, 1);
}

void modificarJugador(int* confirmar)
{
	pedirNumeros(confirmar, "Esta seguro de modificar los datos del jugador? seleccione 2 si el id es erroneo \n"
			"1- Si\n"
			"2- No\n","Error, debe ingresar (1-2)\n", "Error, escoja una opcion valida", 2, 1);
}



void preguntaContinuar(int* continuar)
{
	pedirNumeros(continuar, "Desea continuar? \n"
			"1- Si\n"
			"2- No\n","Error, debe ingresar (1-2)\n", "Error, escoja una opcion valida", 2, 1);
}

void cabecera(){
	printf( "==================================================================================================================================\n"
			"| ID  |     NOMBRE             |EDAD|         POSICION        |        NACIONALIDAD    |      CONFEDERACION           |\n"
			"==================================================================================================================================");
}

