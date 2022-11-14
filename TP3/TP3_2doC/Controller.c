#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "input.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pFile;
	printf("entre al controller\n");
	if(pArrayListJugador != NULL && path != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			if(parser_JugadorFromText(pFile, pArrayListJugador) ==1)
			{
				retorno=1;
				printf("Se realizo la carga modo txt exitosamente\n");

			}
			else
			{
				printf("Error en la lectura\n");
			}
			fclose(pFile);

		}
	}


	    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{

return 1;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	Jugador* jugador;

	int retorno=0;

	char idAux[100];
	char nombreCompletoAux[100];
	char edadAux[100];
	int edadAuxInt;
	char posicionAux[100];
	char nacionalidadAux[100];
	int flagEncontrarUltimoId;
	pedirString(nombreCompletoAux, "\nIngrese un nombre: ", "\nERROR.Ingrese un nombre: ");
	pedirNumeros(&edadAuxInt, "\nIngrese su edad: ", "\nERROR.Ingrese su edad: ", "\nERROR.Ingrese su edad: ", 150, 1);
	pedirString(posicionAux, "\nIngrese una posicion: ", "\nERROR.Ingrese una posicion: ");
	pedirString(nacionalidadAux, "\nIngrese la nacionalidad: ", "\nERROR.Ingrese la nacionalidad: ");
	//flagEncontrarUltimoId= encontrarUltimoId("jugadores.cvs", idAux);
	if(flagEncontrarUltimoId != 0)
	{

		if(grabarId("jugadores.csv", idAux))
		{
			itoa(edadAuxInt,edadAux,10);

			jugador= jug_newParametros(idAux, nombreCompletoAux, edadAux, posicionAux, nacionalidadAux, "0");

			printf("creo el archivo y lo unio\n");
		}


		retorno=1;

	}
	if(retorno == 1 && jugador != NULL)
	{
		ll_add(pArrayListJugador, jugador);

	}

	return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno;

    return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}


