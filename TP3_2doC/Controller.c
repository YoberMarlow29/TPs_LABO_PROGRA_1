 #include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "input.h"
#include "prints.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char *path,LinkedList *pArrayListJugador, int *cantJugadores)
{
	int retorno = -1;
	FILE *pFile;

	if (pArrayListJugador != NULL && path != NULL)
{
		pFile = fopen(path, "r");
		if (pFile != NULL)
{
			if (parser_JugadorFromText(pFile, pArrayListJugador, cantJugadores) == 1)
{
				retorno = 1;
				printf(
						"Se realizo la carga modo txt exitosamente de los jugadores\n");

			}
			else
			{
				printf("**Error en la lectura\n");
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

int controller_agregarJugador(LinkedList *pArrayListJugador, int *cantJugadores)
{
	Jugador *jugador;

	int retorno = 0;

	char idAux[100];
	char nombreCompletoAux[100];
	char edadAux[100];
	int edadAuxInt;
	char posicionAux[100];
	char nacionalidadAux[100];

	pedirString(nombreCompletoAux, "\nIngrese un nombre: ",
			"\nERROR.Ingrese un nombre: ");
	pedirNumeros(&edadAuxInt, "\nIngrese su edad: ",
			"\nERROR.Ingrese su edad: ", "\nERROR.Ingrese su edad: ", 150, 1);
	pedirString(posicionAux, "\nIngrese una posicion: ",
			"\nERROR.Ingrese una posicion: ");
	pedirString(nacionalidadAux, "\nIngrese la nacionalidad: ",
			"\nERROR.Ingrese la nacionalidad: ");
	if (cantJugadores != 0) {

		int id= ll_len(pArrayListJugador);
			id+=1;

		itoa(id, idAux, 10);
		itoa(edadAuxInt, edadAux, 10);



		jugador = jug_newParametros(idAux, nombreCompletoAux, edadAux,posicionAux, nacionalidadAux, "0");

		retorno = 1;

	}
	if (retorno == 1 && jugador != NULL)
	{
		ll_add(pArrayListJugador, jugador);

	}

	return retorno;
}

int controller_encontrarJugadorPorId(LinkedList *pArrayListJugador, int id)
{
	int retorno = -1;
	int len;
	Jugador *jugador;
	int idJugador;

	if (pArrayListJugador != NULL && id > 0)
	{
		len = ll_len(pArrayListJugador);

		for (int i = 0; i < len; i++)
		{
			jugador = ll_get(pArrayListJugador, i);
			jug_getId(jugador, &idJugador);
			if ( idJugador== id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int controller_encontrarJugadorPorSeleccion(LinkedList *pArrayListJugador,int confederacion)
{
	int retorno = -1;
	int len;
	Jugador *jugador;
	int idSeleccion;

	if (pArrayListJugador != NULL)
	{
		len = ll_len(pArrayListJugador);

		for (int i = 0; i < len; i++)
		{
			jugador = ll_get(pArrayListJugador, i);
			jug_getSIdSeleccion(jugador, &idSeleccion);

			if (idSeleccion == confederacion)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


int controller_guardarJugadoresModoTexto(char *path, LinkedList *pArrayListJugador, int abiertoPreviamente)
{
	int retorno = -1;

		if(pArrayListJugador!= NULL)
		{
			if (path != NULL)
			{
				FILE* pFile;
				Jugador* jugadorAux;
				int len;
				int idAux;
				char nombreCompletoAux[100];
				int edadAux;
				char posicionAux[30];
				char nacionalidadAux[30];
				int idSeleccionAux;

				if(abiertoPreviamente == 1)
				{
					pFile = fopen (path,"w");
				}
				else
				{
					pFile = fopen (path,"a");
				}

				len = ll_len(pArrayListJugador);
				if(len > 0)
				{
					if(pFile != NULL)
					{
						fprintf(pFile,"Id,NombreCompleto,edad,Posicion,Nacionalidad,idSeleccion\n");
						for(int i = 0; i < len; i++)				{
							jugadorAux = ll_get(pArrayListJugador, i);
							if(jugadorAux != NULL)
							{
								if(jug_getId(jugadorAux, &idAux)==1)
								{
									if(jug_getNombreCompleto(jugadorAux, nombreCompletoAux)==1)
									{
										if(jug_getEdad(jugadorAux, &edadAux)==1)
										{
											if(jug_getPosicion(jugadorAux, posicionAux)==1)
											{
												if(jug_getNacionalidad(jugadorAux, nacionalidadAux)==1)
												{
													if(jug_getSIdSeleccion(jugadorAux, &idSeleccionAux)==1)
													{
														fprintf(pFile,"%d, %s, %d, %s, %s, %d\n", idAux, nombreCompletoAux, edadAux, posicionAux, nacionalidadAux, idSeleccionAux);
													}
												}
											}
										}
									}
								}
							}
						}
						retorno = 1;
					}
				}
				fclose(pFile);
			}
		}
	    return retorno;
}

int controller_cargarSeleccionesDesdeTexto(char *path,LinkedList *pArrayListSeleccion, int *cantSelecciones)
{
	int retorno = -1;
	FILE *pFile;

	if (pArrayListSeleccion != NULL && path != NULL)
	{
		pFile = fopen(path, "r");
		if (pFile != NULL)
		{
			if (parser_SeleccionFromText(pFile, pArrayListSeleccion,cantSelecciones) == 1)
			{
				retorno = 1;
				printf(
						"Se realizo la carga modo txt exitosamente de las selecciones\n");

			} else
			{
				printf("**Error en la lectura\n");
			}
			fclose(pFile);

		}
	}
	return retorno;
}

int controller_editarSeleccion(LinkedList *pArrayListSeleccion)
{
	return 1;
}

int controller_listarSelecciones(LinkedList *pArrayListSeleccion)
{
	int len;
	int retorno = -1;
	Seleccion *seleccion;

	if (pArrayListSeleccion != NULL)
	{

		if (ll_isEmpty(pArrayListSeleccion) == 0)
		{
			len = ll_len(pArrayListSeleccion);

			for (int i = 0; i < len; i++)
			{
				seleccion = ll_get(pArrayListSeleccion, i);
				selec_mostrarUno(seleccion);

			}
			printf(
					"\n==============================================================================================================\n");
			printf("Fin de la lista.\n");
		}

		else
		{
			printf("Necesita cargar datos para poder mostrarlos\n");
		}

		retorno = 1;
	}

	return retorno;
}

int controller_listarSeleccionesParaGuardarBin(LinkedList *pArrayListSeleccion, int cantiSeleccion, char* confederacionElegida)
{

	int retorno = -1;
	Seleccion *seleccion;
	char nombreConfederaciones[5][30];
	char confederacion[30];
	int contador = 0;
	int esta = 0;
	int opcion;

	if (pArrayListSeleccion != NULL)
	{

		if (ll_isEmpty(pArrayListSeleccion) == 0)
		{
			for (int i =1; i <= cantiSeleccion; i++) {
				esta = 0;
				seleccion = ll_get(pArrayListSeleccion, i);
				selec_getConfederacion(seleccion, confederacion);

				for (int i = 0; i < 5; i++)
				{
					if (strcmp(nombreConfederaciones[i], confederacion) == 0)
					{
						esta = 1;
					}
				}
				if (esta == 0)
{
					strcpy(nombreConfederaciones[contador], confederacion);
					contador++;
				}

			}

		} else
		{
			printf("Necesita cargar datos para poder mostrarlos\n");
		}

		for (int i = 0; i < 5; i++)
		{
			printf("\n%d - %s", (i + 1), nombreConfederaciones[i]);
		}

		utn_getNumero(&opcion, "\ningrese su opcion\n", "\nOpcion incorrecta\n", 1, 5, 4);


		strcpy(confederacionElegida, nombreConfederaciones[opcion-1]);
		retorno = 1;
	}

	return retorno;
}

int controller_listarSeleccionesParaConvocar(LinkedList *pArrayListSeleccion)
{
	int len;
	int retorno = -1;
	Seleccion *seleccion;
	int convocados;

	if (pArrayListSeleccion != NULL)
	{

		if (ll_isEmpty(pArrayListSeleccion) == 0)
		{
			len = ll_len(pArrayListSeleccion);

			for (int i = 0; i < len; i++)
			{
				seleccion = ll_get(pArrayListSeleccion, i);
				selec_getConvocados(seleccion, &convocados);
				if (convocados >= 0 && convocados <= 22)
				{
					selec_mostrarParaConvocar(seleccion);
				}

			}
			printf(
					"\n==============================================================================================================\n");
			printf("Fin de la lista.\n");
		}

		else
		{
			printf("Necesita cargar datos para poder mostrarlos\n");
		}

		retorno = 1;
	}

	return retorno;
}

int controller_encontrarSeleccionPorId(LinkedList *pArrayListSelecciones,int id)
{
	int retorno = -1;
	int len;
	Seleccion *seleccion;

	if (pArrayListSelecciones != NULL && id > 0)
	{
		len = ll_len(pArrayListSelecciones);

		for (int i = 0; i < len; i++)
		{
			seleccion = ll_get(pArrayListSelecciones, i);

			if (seleccion->id == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int controller_listarJugadores(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion)
{
	int len;
	int retorno = -1;
	Jugador *jugador;
	Seleccion *seleccion;
	int posicionSeleccion = -1;
	int idSeleccion;
	char confe[30] = "";

	cabecera();

	if (pArrayListJugador != NULL)
	{

		if (ll_isEmpty(pArrayListJugador) == 0)
		{
			len = ll_len(pArrayListJugador);

			for (int i = 0; i < len; i++)
			{
				jugador = ll_get(pArrayListJugador, i);

				jug_getSIdSeleccion(jugador, &idSeleccion);

				posicionSeleccion = controller_encontrarSeleccionPorId(pArrayListSeleccion, idSeleccion);

				if (posicionSeleccion >= 1)
				{

					seleccion = ll_get(pArrayListSeleccion, posicionSeleccion);

					selec_getConfederacion(seleccion, confe);

					jug_mostrarUn(jugador, confe);

				}

				else
				{
					jug_mostrarUn(jugador, "NO CONVOCADO");
				}

			}
			printf(
					"\n==============================================================================================================\n");
			printf("Fin de la lista.\n");
		} else {
			printf("Necesita cargar datos para poder mostrarlos\n");
		}

		retorno = 1;
	}

	return retorno;
}

int controller_guardarSeleccionesModoTexto(char *path,LinkedList *pArrayListSeleccion) {
	return -1;
}

int controller_listarJugadoresNoConvocados(LinkedList *pArrayListJugador)
{
	int len;
	int retorno = -1;
	int convocado = -1;
	Jugador *jugador;
	int contador = 0;

	if (pArrayListJugador != NULL)
	{

		if (ll_isEmpty(pArrayListJugador) == 0)
		{
			len = ll_len(pArrayListJugador);

			for (int i = 0; i < len; i++)
			{
				jugador = ll_get(pArrayListJugador, i);
				jug_getSIdSeleccion(jugador, &convocado);
				if (convocado == 0)
				{
					jug_mostrarUn(jugador, "NO CONVOCADO");

				}
			}
			printf(
					"\n==============================================================================================================\n");
			printf("Fin de la lista.\n");
		}

		else
		{
			printf("Necesita cargar datos para poder mostrarlos\n");
		}

		retorno = contador;
	}

	return retorno;
}

int controller_listarJugadoresConvocados(LinkedList *pArrayListJugador,LinkedList *pArrayListSeleccion)
{
	int len;
	int retorno = -1;
	int convocado = -1;
	Jugador *jugador;
	Seleccion *seleccion;
	int idSeleccion;
	int posicionSeleccion;
	char confederacion[30];
	int contador = 0;

	if (pArrayListJugador != NULL)
	{

		if (ll_isEmpty(pArrayListJugador) == 0)
		{
			len = ll_len(pArrayListJugador);

			for (int i = 0; i < len; i++)
			{
				jugador = ll_get(pArrayListJugador, i);
				jug_getSIdSeleccion(jugador, &idSeleccion);
				posicionSeleccion = controller_encontrarSeleccionPorId(pArrayListSeleccion, idSeleccion);
				seleccion = ll_get(pArrayListSeleccion, posicionSeleccion);

				jug_getSIdSeleccion(jugador, &convocado);
				if (convocado >= 1)
				{
					selec_getConfederacion(seleccion, confederacion);
					jug_mostrarUn(jugador, confederacion);
					contador++;
				}

			}
			printf(
					"\n==============================================================================================================\n");
			printf("Fin de la lista.\n");
		}
		else
		{
			printf("Necesita cargar datos para poder mostrarlos\n");
		}

		retorno = contador;
	}

	return retorno;
}

void controller_listados(LinkedList *pArrayListJugador,LinkedList *pArrayListSeleccion) {

	int opcion;


	do {
		utn_getNumero(&opcion,
				"\n1- TODOS LOS JUGADORES\n2- TODAS LAS SELECCIONES\n3-JUGADORES CONVOCADOS\n4-Salir\n",
				"Opcion incorrecta", 1, 4, 4);

		switch (opcion) {

		case 1:
			controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
			break;

		case 2:
			controller_listarSelecciones(pArrayListSeleccion);
			break;

		case 3:
			controller_listarJugadoresConvocados(pArrayListJugador,
					pArrayListSeleccion);
			break;
		}

	} while (opcion != 4);

}

int controller_convocarJugador(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion, int cantJugadores, int cantSelecciones)
{

	int idSeleccion;
	int retorno = -1;
	int idJugador = 0;
	Jugador *jugador;
	Seleccion *seleccion;
	int convocados;
	int posicionSeleccion;
	int posicionJugador;

	int longi= ll_len(pArrayListJugador);

	utn_getNumero(&idJugador, "Ingrese el id del jugador que desea Convocar: ","Error, ingrese solo numeros\n", 1, longi, 5 );

	posicionJugador = controller_encontrarJugadorPorId(pArrayListJugador, idJugador);


	jugador = ll_get(pArrayListJugador, posicionJugador);


	if (posicionJugador != -1)
	{
		controller_listarSeleccionesParaConvocar(pArrayListSeleccion);
		pedirNumeros(&idSeleccion,
				"Ingrese el id de la seleccion que convocar� al jugador ",
				"Error, ingrese solo numeros\n", "Error, numero invalido\n",
				cantSelecciones, 1);
		posicionSeleccion = controller_encontrarSeleccionPorId(pArrayListSeleccion, idSeleccion);

		if (posicionSeleccion != -1)
		{

			seleccion = ll_get(pArrayListSeleccion, posicionSeleccion);

			selec_getConvocados(seleccion, &convocados);

			if (convocados >= 0 && convocados <= 22)
			{
				jug_setIdSeleccion(jugador, idSeleccion);

				convocados += 1;

				cantJugadores--;

				selec_setConvocados(seleccion, convocados);

				retorno = 1;
			}

		}
	}

	return retorno;

}

int controller_quitarDeLaSeleccion(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion, int cantJugadores, int cantSelecciones)
{

	int idSeleccion;
	int retorno = -1;
	int idJugador = 0;
	Jugador *jugador;
	Seleccion *seleccion;
	int convocados;
	int posicionSeleccion;
	int posicionJugador;

	utn_getNumero(&idJugador, "Ingrese el id del jugador que desea bajar de la seleccion:","\nError, ingrese solo numeros\n", 1, ll_len(pArrayListJugador),5);


	posicionJugador = controller_encontrarJugadorPorId(pArrayListJugador,idJugador);

	jugador = ll_get(pArrayListJugador, posicionJugador);

	if (posicionJugador != -1)
	{
		jug_getSIdSeleccion(jugador, &idSeleccion);
		posicionSeleccion = controller_encontrarSeleccionPorId(
				pArrayListSeleccion, idSeleccion);

		if (posicionSeleccion != -1)
		{

			seleccion = ll_get(pArrayListSeleccion, posicionSeleccion);

			selec_getConvocados(seleccion, &convocados);

			if (convocados >= 1)
			{
				jug_setIdSeleccion(jugador, 0);
				convocados = convocados - 1;
				selec_setConvocados(seleccion, convocados);
				retorno = 1;
			}

		}
	}

	return retorno;

}

int controller_editarJugador(LinkedList *pArrayListJugador,LinkedList *pArrayListSeleccion)
{
	int retorno = -1;
	int len;
	int idModificar;
	int pocisionModificar;
	int confirmar;
	int continuar;
	int conservarCambios;
	Jugador *JugadorModificar;

	/////variablesAux
	char nombreCompletoAux[100];
	int edadAux;
	char posicionAux[100];
	char nacionalidadAux[100];

	len = ll_len(pArrayListJugador);

	if (len > 0)
	{
		if (pArrayListJugador != NULL)
		{
			controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);

			pedirNumeros(&idModificar,
					"Ingrese el id del jugador que desea Modificar: ",
					"Error, ingrese solo numeros\n", "Error, numero invalido\n",
					len, 1);
			pocisionModificar = controller_encontrarJugadorPorId(pArrayListJugador, idModificar);
		}
		if (pocisionModificar > -1)
		{
			JugadorModificar = ll_get(pArrayListJugador, pocisionModificar);

			if (JugadorModificar != NULL)
			{
				modificarJugador(&confirmar);
				retorno = 1;

				if (confirmar == 1)
				{
					do {
						int opcion;
						opcion = UTN_pedirEnteroRango("\nSeleccion una opcion: "
								"\n1-NOMBRE DE JUGADOR:"
								"\n2-EDAD DEL JUGADOR: "
								"\n3-POSICION DEL JUGADOR"
								"\n4-NACIONALIDAD DEL JUGADOR"
								"\n5-CANCELAR", 1, 5);

						switch (opcion) {
						case 1:
							pedirString(nombreCompletoAux,
									"\nIngrese un nombre: ",
									"\nERROR.Ingrese un nombre: ");
							if (jug_setNombreCompleto(JugadorModificar,nombreCompletoAux))
							{
								printf("Se Modifico correctamente \n");
							}

							else
							{
								printf("Error, modificar nombre\n");
							}

							break;
						case 2:
							pedirNumeros(&edadAux, "\nIngrese su edad: ",
									"\nERROR.Ingrese su edad: ",
									"\nERROR.Ingrese su edad: ", 150, 1);

							if (jug_setEdad(JugadorModificar, edadAux))
							{
								printf("Se Modifico correctamente \n");
							}

							else
							{
								printf("Error, modificar edad\n");
							}

							break;
						case 3:
							pedirString(posicionAux, "\nIngrese una posicion: ",
									"\nERROR.Ingrese una posicion: ");
							if (jug_setPosicion(JugadorModificar,posicionAux))
							{
								printf("Se Modifico correctamente \n");
							}

							else
							{
								printf("Error, modificar posicion\n");
							}

							break;
						case 4:
							pedirString(nacionalidadAux,
									"\nIngrese la nacionalidad: ",
									"\nERROR.Ingrese la nacionalidad: ");
							if (jug_setNacionalidad(JugadorModificar,nacionalidadAux))
							{
								printf("Se Modifico correctamente \n");
							}
							else
							{
								printf("Error, modificar nacionalidad\n");
							}

							break;
						case 5:

							break;
						}
						preguntaContinuar(&continuar);
					} while (continuar != 2);

					guardarCambios(&conservarCambios);
					if (conservarCambios)
					{
						if (ll_set(pArrayListJugador, pocisionModificar,JugadorModificar) == 0)
						{
							printf("\nEl jugador fue modificado con exito.\n");
						}

						else
						{
							printf(
									"\nError. No se pudo modificar el jugador\n");
						}
					}

					else {
						printf("La operacion ha sido cancelada");
					}

				}

			}

			else {
				printf("Ocurrio un error ejecutando la operacion\n");
			}
		}

		else {
			printf("\nOcurrio un error al intentar modificar\n");
		}
	}
	return retorno;
}

int controller_removerJugador(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion)
{
	int retorno = -1;
	int len;
	int idBorrar;
	int pocisionBorrar;
	int confirmar;
	Jugador *jugador;
	Seleccion *seleccion;
	int idSeleccion;
	int posicionSeleccion;
	int convocados;

	len = ll_len(pArrayListJugador);

	if (len > 0) {
		if (pArrayListJugador != NULL)
		{
			controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);

			utn_getNumero(&idBorrar, "Ingrese el id del jugador que desea borrar: ", "Error, numero invalido\n", 1, len, 5);
			pocisionBorrar = controller_encontrarJugadorPorId(pArrayListJugador,idBorrar);

			if (pocisionBorrar > -1)
			{
				jugador = ll_get(pArrayListJugador, pocisionBorrar);

				if (jugador != NULL)
				{
					jug_getSIdSeleccion(jugador, &idSeleccion);

					posicionSeleccion = controller_encontrarSeleccionPorId(pArrayListSeleccion, idSeleccion);

					seleccion = ll_get(pArrayListSeleccion, posicionSeleccion);

					borrarJugador(&confirmar);

					retorno = 1;

					if (confirmar == 1)
					{
						if (ll_remove(pArrayListJugador, pocisionBorrar) == 0)
						{
							selec_getConvocados(seleccion, &convocados);

							convocados = convocados - 1;

							selec_setConvocados(seleccion, convocados);

							jug_delete(jugador);

							printf("\nLos datos han sido borrados con exito\n");
						}
					}

					else {
						printf("La operacion ha sido cancelada con exito");
					}
				}

				else {
					printf("Ocurrio un error ejecutando la operacion\n");
				}
			}

			else {
				printf("Error el id es incorrecto\n");
			}
		}

		else {
			printf("Ocurrio un error ejecutando la operacion\n");
		}
	}

	else {
		retorno = 1;

		printf("\nNecesita tener jugadores cargados\n");
	}

	return retorno;
}

int controller_menuConvocar(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion, int cantJugadores, int cantSelecciones)
{
	int opcion;
	int resultado;
	int retorno = -1;
	int cantidad;

	do {
		utn_getNumero(&opcion,
				"\n1- CONVOCAR\n2- QUITAR DE LA SELECCION\n3-Salir\n",
				"Opcion incorrecta", 1, 3, 4);

		switch (opcion)
		{

		case 1:
			cantidad = controller_listarJugadoresNoConvocados(pArrayListJugador);

			resultado = controller_convocarJugador(pArrayListJugador,pArrayListSeleccion, cantidad, cantSelecciones);

			if (resultado == 1)
			{
				printf("\nSE CONVOCO EXISTOSAMENTE AL JUGADOR\n");

				retorno = 1;
			}

			else
			{
				printf("\nNO SE PUDO CONVOCAR AL JUGADOR\n");
			}
			break;

		case 2:
			cantidad = controller_listarJugadoresConvocados(pArrayListJugador,pArrayListSeleccion);

			resultado = controller_quitarDeLaSeleccion(pArrayListJugador,pArrayListSeleccion, cantidad, cantSelecciones);
			if (resultado == 1)
			{
				printf(
						"\nSE ELIMINO EXISTOSAMENTE AL JUGADOR DE LA SELECCION\n");
				retorno = 1;
			}

			else
			{
				printf("\nNO SE PUDO ELIMINAR AL JUGADOR\n");
			}
			break;
		}

	} while (opcion != 3);

	return retorno;
}

int controller_menuOrdenar(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion)
{
	int opcion;
		//int resultado;
		int retorno = -1;
		int orden;

		do {
			utn_getNumero(&opcion,
					"\n1- JUGADORES POR NACIONALIDAD\n2- SELECCIONES POR CONFEDERACION \n3- JUGADORES POR EDAD\n4- JUGADORES POR NOMBRE\n5- Salir\n",
					"Opcion incorrecta", 1, 5, 4);

			switch (opcion) {

			case 1:
				utn_getNumero(&orden, "\n0-Descendente\n1-Ascendente\n", "\nOpcionIvalida\n", 0, 1, 3);
				if(ll_sort(pArrayListJugador, jug_OrdenarPorNacionalidad, orden)==0)
				{
					controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);

				}

				break;

			case 2:
				utn_getNumero(&orden, "\n0-Descendente\n1-Ascendente\n", "\nOpcionIvalida\n", 0, 1, 3);
				if(ll_sort(pArrayListSeleccion, selec_OrdenarPorConfederacion, orden)==0)
				{
					controller_listarSelecciones(pArrayListSeleccion);

				}
				break;

			case 3:

				utn_getNumero(&orden, "\n0-Descendente\n1-Ascendente\n", "\nOpcionIvalida\n", 0, 1, 3);
				if(ll_sort(pArrayListJugador, jug_OrdenarPorEdad, orden)==0)
				{
					controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);

				}

				break;

			case 4:
				utn_getNumero(&orden, "\n0-Descendente\n1-Ascendente\n", "\nOpcionIvalida\n", 0, 1, 3);
				if(ll_sort(pArrayListJugador, jug_OrdenarPorNombre, orden)==0)
				{
					controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);

				}

				break;
			}

		} while (opcion != 5);

		return retorno;
}

int controller_crearListaSeleccionadosPorConfederacion(LinkedList *pArrayListJugador, LinkedList *pArrayListSelecciones, char confederacionBuscada[30], LinkedList *pSeleccionados)
{

	Seleccion* seleccion;
	Jugador *jugador;
	char confederacion[30];
	int idSeleccionJugador;
	int lonJugadores = ll_len(pArrayListJugador);

	int posicionEncontrada;
	int retorno = -0;
	int resultado;


	if (pArrayListJugador != NULL && pArrayListSelecciones != NULL)
	{

		for (int i = 0; i < lonJugadores; i++)
		{

			jugador = ll_get(pArrayListJugador, i);

			jug_getSIdSeleccion(jugador, &idSeleccionJugador);
			if(idSeleccionJugador>0)
			{

				posicionEncontrada = controller_encontrarSeleccionPorId(pArrayListSelecciones, idSeleccionJugador);

				seleccion =ll_get(pArrayListSelecciones, posicionEncontrada);

				selec_getConfederacion(seleccion, confederacion);

				resultado = strcmp(confederacion, confederacionBuscada);
				if (resultado==0)
				{
					ll_add(pSeleccionados, jugador);

					retorno = 1;
				}

			}
		}
	}

	return retorno;
}

int controller_cargarJugadoresDesdeBinario(char *path, LinkedList *pArrayListSeleccion )
{
	int retorno = -1;
	FILE *pFile;
	LinkedList* listaJugadoresConcovados = ll_newLinkedList();
	int lon = ll_len(listaJugadoresConcovados);

	if (listaJugadoresConcovados != NULL && path != NULL)
	{
		pFile = fopen(path, "rb");

		if (pFile != NULL)
		{
			if (parser_JugadorFromBinary(pFile, listaJugadoresConcovados, &lon) == 1)
			{
				controller_listarJugadores(listaJugadoresConcovados, pArrayListSeleccion);

				retorno = 1;

				printf("\nSe realizo la carga modo bin exitosamente\n");

			}

			else
			{
				printf("**\nError en la lectura\n");
			}
			fclose(pFile);

		}
	}



	return retorno;

}

int controller_saveAsBinary(char *path, LinkedList *pArrayListJugador,LinkedList *pArrayListSeleccion, int cantJugadores, int cantSelecciones)
{
	FILE *pFile;
	int escrituraBin;
	int retorno = -1;
	int longitud = ll_len(pArrayListJugador);
	char confederacionEscogida[30];

	int pude;

	LinkedList* pSeleccionados = ll_newLinkedList();

	controller_listarSeleccionesParaGuardarBin(pArrayListSeleccion, cantSelecciones ,confederacionEscogida);

	pude = controller_crearListaSeleccionadosPorConfederacion(pArrayListJugador, pArrayListSeleccion, confederacionEscogida, pSeleccionados);

	if (pude == 1)
	{
		pFile = fopen(path, "wb");

		printf("\nGUARDANDO LA LISTA DE LOS CONVOCADOS...\n");

		if (pFile != NULL)
		{
			for (int i = 0; i < longitud; i++)
			{
				escrituraBin = fwrite(ll_get(pSeleccionados, i),sizeof(Jugador), 1, pFile);
				if (escrituraBin == 1)
				{
					retorno = 1;
				}
			}

			fclose(pFile);
		}

		else
		{
			printf("Ocurrio un error al intentar guardar el achivo");
		}
	}

	else
	{
		printf("\nNO SE PUDO CREAR LA LISTA DE SELECCIONADOS\n");
	}

	return retorno;
}

